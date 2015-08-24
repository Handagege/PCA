#ifndef _FENGYOUNG_API_H
#define _FENGYOUNG_API_H

#include <stdint.h>

// Hash
#include "UintHash.h"
#include "StrHash.h"
#include "SimHash.h"

// String Operations
#include "BiChar.h"
#include "CnCharacterExtractor.h"
#include "CnStrPinyinEncoder.h"
#include "PinyinMap.h"
#include "StringArray.h"
#include "StringSplitter.h"
#include "StringTokenizer.h"
#include "StrMarkExp.h"
#include "StrNumConv.h"
#include "TradSimpConv.h"
#include "StrSim.h"
#include "StrMatch_BoyerMoore.h"
#include "NumFormulaTree.h"

// File Operations
#include "ConfigFile.h"
#include "BinaryFile.h"
#include "FileStatus.h"
#include "LogFile.h"
#include "LogCostStat.h"
#include "DirInfo.h"

// Math
#include "Attenuation.h"
#include "Histogram.h"
#include "MathMethod.h"
#include "ROCAnalyzer.h"
#include "Random.h"
#include "Random64.h"
#include "Statistic.h"
#include "VecCalc.h"
#include "Logistic.h"
#include "Identity.h"

// Pattern
#include "MultiPattern.h"
#include "strmatch_fengyoung.h"

// Time
#include "TimeFmtConv.h"
#include "Timer.h"

// Thread
#include "ThreadMutex.h"
#include "ThreadRWLock.h"
#include "FBuffer.h"
#include "FCach_KeyVal.h"

// Set Operations 
#include "BloomSet32.h"
#include "BinarySearch.h"

// Template
#include "CircularQueue.h"

// Net
#include "IfAddr.h"

#endif /* _FENGYOUNG_API_H */

