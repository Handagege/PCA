#!/usr/home/zhanghan5/bin/Rscript

setwd("/data1/zhanghan/PCA/experiment/data")
ctr = read.table("ctr.table",sep=",")
ctr.answer = read.table("ctr.answer",sep=",")

dim(ctr)
ctr[is.na(ctr)] = 0
Args = commandArgs()
Num = as.double(Args[6])
ratio = Num/(Num+1)
ctr_train_sub = sample(nrow(ctr),ratio*nrow(ctr))
ctr_train = ctr[ctr_train_sub,]
ctr_test = ctr[-ctr_train_sub,]
ctr_train.answer = data.frame(ctr.answer[ctr_train_sub,])
ctr_test.answer = data.frame(ctr.answer[-ctr_train_sub,])
rm(ctr)
rm(ctr.answer)

fun1 = function(data){
  which(apply(data,2,function(x) max(x)-min(x)) == 0 | apply(data,2,sum) == 1)
}

delist = fun1(ctr_train)
ctr_train = ctr_train[,-delist]
ctr_test = ctr_test[,-delist]

dim(ctr_train)
ctr_train_all = cbind(ctr_train,ctr_train.answer)
ctr_test_all = cbind(ctr_test,ctr_test.answer)
dim(ctr_train_all)
write.table(ctr_train_all,file="ctr_train.table",row.names=F,col.names=F,sep=",")
write.table(ctr_test_all,file="ctr_test.table",row.names=F,col.names=F,sep=",")

print("vec length: ")
print(length(ctr_train))
print("")
#ctr_train_all[,ncol(ctr_train_all)-1]
