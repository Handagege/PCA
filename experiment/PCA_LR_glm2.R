#!/usr/home/zhanghan5/bin/Rscript

setwd("/data1/zhanghan/PCA/experiment/data")
Args = commandArgs()
ctr_train_all = read.table("ctr_train.table",sep=",")
ctr_test_all = read.table("ctr_test.table",sep=",")
col = ncol(ctr_train_all)
ctr_train = ctr_train_all[,-col]
ctr_test = ctr_test_all[,-col]
ctr_train.answer = ctr_train_all[,col]
ctr_test.answer = ctr_test_all[,col]

ccr = as.double(Args[6])
#ccr = 0.3
dcor = cor(ctr_train)
deig = eigen(dcor)
pclength = 1
while( sum(deig$values[1:pclength])/sum(deig$values) < ccr ){
  pclength = pclength+1
}
ctr_PCA_train = as.matrix(ctr_train)%*%deig$vectors
ctr_PCA_test = as.matrix(ctr_test)%*%deig$vectors
ctr_PCA_train = data.frame(ctr_PCA_train[,1:pclength])
ctr_PCA_test = data.frame(ctr_PCA_test[,1:pclength])

ctr_train_all = data.frame(cbind(ctr_PCA_train,ctr_train.answer))
ctr_test_all = data.frame(cbind(ctr_PCA_test,ctr_test.answer))
dvar = names(ctr_train_all)
ivar = dvar[-length(dvar)]
dvar = dvar[length(dvar)]
y = paste0(dvar,"~")
f <- as.formula(paste(y,paste(ivar, collapse = "+")))

library("glm2")
glm.fit=glm2(f,data=ctr_train_all,
  family=binomial(link="logit"),maxit=25)# epsilon = 1e-14

p=predict(glm.fit,ctr_test_all)

np=exp(p)/(1+exp(p))
library("pROC")
np = as.numeric(np)
ans = as.factor(ctr_test.answer)
rocData = roc(ans,np,plot=TRUE, smooth=TRUE,print.thres=F, print.auc=TRUE)
auc = rocData$auc[1]

result = list(ccr = ccr, pclength = pclength, auc = auc)
print(result)
