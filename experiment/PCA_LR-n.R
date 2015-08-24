#!/usr/home/zhanghan5/bin/Rscript

setwd("/data1/zhanghan/PCA/experiment/data1")
library("pROC")
Args = commandArgs()
Num = as.double(Args[6])
ratio = Num/(Num+1)
#ratio = 7/8
array_PCA_AUC = array()
total_all_AUC = c()
nlength = 1
pclength = 1
ctr = read.table("ctr.table",sep=",")
ctr.answer = read.table("ctr.answer",sep=",")

for(i in 1:3){
        #sample train and test data by ratio,default 8-1
	ctr_train_sub = sample(nrow(ctr),ratio*nrow(ctr))
	ctr_train = ctr[ctr_train_sub,]
	ctr_test = ctr[-ctr_train_sub,]
	ctr_train.answer = ctr.answer[ctr_train_sub,]
	ctr_test.answer = ctr.answer[-ctr_train_sub,]
        ans = as.factor(ctr_test.answer)
        #column filter function (filter constand value)
	fun1 = function(data){
	  which(apply(data,2,function(x) max(x)-min(x)) == 0 | apply(data,2,sum) == 1)
	}
	delist = fun1(ctr_train)
	ctr_train = ctr_train[,-delist]
	ctr_test = ctr_test[,-delist]
	ctr_train_all = cbind(ctr_train,ctr_train.answer)
	ctr_test_all = cbind(ctr_test,ctr_test.answer)
        
        #all column logic regression
        dvar = names(ctr_train_all)
        nlength = length(dvar)
        ivar = dvar[-nlength]
        dvar = dvar[nlength]
        y = paste0(dvar,"~")
        f <- as.formula(paste(y,paste(ivar, collapse = "+")))
        
        glm.fit=glm(f,data=ctr_train_all,
                    family=binomial(link="logit"),maxit=25,epsilon = 1e-4)
        
        p=predict(glm.fit,ctr_test_all)
        np=exp(p)/(1+exp(p))
        np = as.numeric(np)
        rocData = roc(ans,np,plot=TRUE, smooth=TRUE,print.thres=F, print.auc=TRUE)
        auc = rocData$auc
        total_all_AUC = append(total_all_AUC,auc)
        #####

        #PCA process start
        dcor = cor(ctr_train)
        deig = eigen(dcor)
        total_PCA_AUC = c()
        total_ccr = c()
        total_pclength = c()
        ctr_PCA_train_m = as.matrix(ctr_train)%*%deig$vectors
        ctr_PCA_test_m = as.matrix(ctr_test)%*%deig$vectors
        for (ccr in seq(0.1,0.9,0.05))
        {
                pclength = 1
                while( sum(deig$values[1:pclength])/sum(deig$values) < ccr ){
                pclength = pclength+1
                }
                ctr_PCA_train = data.frame(ctr_PCA_train_m[,1:pclength])
                ctr_PCA_test = data.frame(ctr_PCA_test_m[,1:pclength])
                ctr_PCA_train_all = data.frame(cbind(ctr_PCA_train,ctr_train.answer))
                ctr_PCA_test_all = data.frame(cbind(ctr_PCA_test,ctr_test.answer))

                #logic regression start by PCA matrix
                dvar = names(ctr_PCA_train_all)
                ivar = dvar[-length(dvar)]
                dvar = dvar[length(dvar)]
                y = paste0(dvar,"~")
                f <- as.formula(paste(y,paste(ivar, collapse = "+")))
        
                glm.fit=glm(f,data=ctr_PCA_train_all,
                        family=binomial(link="logit"),maxit=30)
                p=predict(glm.fit,ctr_PCA_test_all)
        
                #result analysis
                np=exp(p)/(1+exp(p))
                np = as.numeric(np)
                rocData = roc(ans,np,plot=TRUE, smooth=TRUE,print.thres=F, print.auc=TRUE)
                auc = rocData$auc[1]
                total_PCA_AUC = append(total_PCA_AUC,auc)
                total_ccr = append(total_ccr,ccr)
                total_pclength = append(total_pclength,pclength)
        }
        array_PCA_AUC = rbind(array_PCA_AUC,total_PCA_AUC)
}
print("PCA result : ")
print(array_PCA_AUC[-1,])
print("mean result : ")
PCA_result = list(ccr = total_ccr, pclength = total_pclength, auc = apply(array_PCA_AUC[-1,],2,mean))
print(PCA_result)

print("ALL column result : ")
print(total_all_AUC)
print("mean result : ")
ALL_result = list(ccr = "all", length = nlength, auc = mean(total_all_AUC))
print(ALL_result)
