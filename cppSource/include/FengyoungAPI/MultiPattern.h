/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// MultiPattern.h : 多模式匹配类MultiPattern的声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_MULTI_PATTERN_H
#define _FENGYOUNG_API_MULTI_PATTERN_H

#include <map>
#include <vector>
#include <string>
using namespace std; 
#include <stdint.h>
#include "strmatch_fengyoung.h"


#define _MULTIPATTERN_SUCCESS		1
#define _MULTIPATTERN_ERROR_INITFAILED	-1
#define _MULTIPATTERN_ERROR_LOADPATTERN	-2


namespace fengyoung
{

// 类名：MultiPattern
// 说明：多模式匹配
class MultiPattern
{
public:
	// 构造函数 & 析构函数
	MultiPattern();
	virtual ~MultiPattern();

	// 函数名：LoadPattern
	// 说明：载入模式
	// 参数：
	//	[IN] sFile - 模式文件
	// 返回值：载入成功返回1，否则返回错误代码（<0）
	int32_t LoadPattern(const char* sFile);

	// 函数名：InsertPattern
	// 说明：插入模式
	// 参数：
	//	[IN] sFile - 模式文件
	// 返回值：载入成功返回1，否则返回错误代码（<0）
	int32_t InsertPattern(const char* sPattern); 
	bool PreparePattern(); 

	// 函数名：Match
	// 说明：执行多模式匹配
	// 参数：
	//	[OUT] mapMatched - "匹配模式->匹配数"映射表
	//	[OUT] vtrMatched - "<匹配模式->匹配数>"向量
	//	[IN] sTxt - 待匹配文本
	// 返回值：匹配数目
	int32_t Match(map<string,int32_t>& mapMatched, const char* sTxt); 
	int32_t Match(vector<pair<string,int32_t> >& vtrMatched, const char* sTxt); 

private: 
	MATCHENTRY_FENGYOUNG* m_matchEntry;	// 匹配入口
};

}

#endif /* _FENGYOUNG_API_MULTI_PATTERN_H */

