#!/bin/bash

for i in {8..9}
do
        cp ./data1/$i/ctr.* ./data1/
	echo PCA test start... >> result1/result$i.txt
        Rscript PCA_LR-n.R 8 >> result1/result$i.txt
        cd ./data1
        rm ctr.table ctr.answer
        cd ..
done
