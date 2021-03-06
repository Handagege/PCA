#!/usr/bin/python
import os
import glob
import time

sourcePath = r'/data1/zhanghan/PCA/UseProfileData/'
prefixName = r'b0099-template_id_001-'
indexStr = [r"20150517"]
targetPath = r'/data1/zhanghan/PCA/data/VecData/'

delList = []
for i in range(0,98):
	delList.append(0)
for s in indexStr:
    index = sourcePath + prefixName + s + r'*'
    filenames = glob.glob(index)
    targetFile_NO_c = targetPath + r"vec-" + s + r'-NoC.table'
    targetFile_c_No_r = targetPath + r"vec-" + s + r'-YesC-NoR.table'
    targetFile_c_r = targetPath + r"vec-" + s + r'-YesC-YesR.table'
    fout1 = open(targetFile_NO_c,'w')
    fout2 = open(targetFile_c_No_r,'w')
    fout3 = open(targetFile_c_r,'w')

    for filename in filenames:
        print filename
        fin = open(filename,'r')
        lines = fin.readlines()
        for line in lines:
            vecDataList = []
            lineData = line.split('|')
            ctrData = lineData[2]
	    rpmData = lineData[3]
            vecData = lineData[7]
            result = ','
            nodeDatas = vecData.split(';')
            for nodeData in nodeDatas:
                vecDataList.append(nodeData.split(',')[1])
            result = result.join(vecDataList)
	    if cmp(result,delList) != 0:
		if ctrData == '-1':
            	    fout1.write(result)
		elif rpmData == '1':
		    fout3.write(result)
		else:
		    fout2.write(result) 

