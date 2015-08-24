#!/bin/bash

t1=$(date +%s)
./ALL_LR.R >> result.txt
t2=$(date +%s)
echo cost time : 
echo $(($t2 - $t1))
