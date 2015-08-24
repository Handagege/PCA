#!/usr/home/zhanghan5/bin/Rscript

setwd("/data1/zhanghan/PCA/experiment/data")
ctr_train_all = read.table("ctr_train.table",sep=",")
ctr_test_all = read.table("ctr_test.table",sep=",")
col = ncol(ctr_train_all)
ctr_train = ctr_train_all[,-col]
ctr_test = ctr_test_all[,-col]
ctr_train.answer = ctr_train_all[,col]
ctr_test.answer = ctr_test_all[,col]

print("data prepare end ...")
dvar = names(ctr_train_all)
nlength = length(dvar)
ivar = dvar[-nlength]
dvar = dvar[nlength]
y = paste0(dvar,"~")
f <- as.formula(paste(y,paste(ivar, collapse = "+")))

glm.fit=glm(f,data=ctr_train_all,
            family=binomial(link="logit"),maxit=25,epsilon = 1e-6)

p=predict(glm.fit,ctr_test_all)
print("Logit regression predict end ...")

np=exp(p)/(1+exp(p))
library("pROC")
np = as.numeric(np)
ans = as.factor(ctr_test.answer)
rocData = roc(ans,np,plot=TRUE, smooth=TRUE,print.thres=F, print.auc=TRUE)
auc = rocData$auc
result = list(ccr = "all", length = nlength, auc = auc)
print(result)

