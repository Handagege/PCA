/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrMatch_BoyerMoore.h : 基于Boyer-Moore算法的子串匹配类声明
//
// Boyer-Moore字符串搜索算法是一种非常高效的字符串搜索算法。它由Bob Boyer和J Strother Moore设计于1977年。
// 此算法仅对搜索目标字符串（关键字）进行预处理，而非被搜索的字符串。虽然Boyer-Moore算法的执行时间同样线
// 性依赖于被搜索字符串的大小，但是通常仅为其它算法的一小部分：它不需要对被搜索的字符串中的字符进行逐一
// 比较，而会跳过其中某些部分。通常搜索关键字越长，算法速度越快。它的效率来自于这样的事实：对于每一次失败
// 的匹配尝试，算法都能够使用这些信息来排除尽可能多的无法匹配的位置。
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_MATCH_BOYER_MOORE_H 
#define _FENGYOUNG_API_STR_MATCH_BOYER_MOORE_H

#include <map>
#include <vector>
#include <string>
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// 类名：StrMatch_BoyerMoore
//	基于Boyer-Moore算法的子串匹配类
class StrMatch_BoyerMoore
{
private:
	// 构造函数 & 析构函数
	StrMatch_BoyerMoore(); 
	virtual ~StrMatch_BoyerMoore(); 

public: 
	// 函数名：Find
	// 说明：子串查找
	// 参数：
	//	[IN] sStr - 字符串
	//	[IN] sSub - 子串
	// 返回值：子串在字符串中的起始位置，如果子串不能存在返回-1
	static int32_t Find(const char* sStr, const char* sSub);

private:
	// 函数名：SuffixAndCharMap
	// 说明：构造后缀位置以及字符位置映射表
	// 参数：
	//	[IN] sStr - 字符串
	//	[OUT] mapSuffix - 后缀位置映射表
	//	[OUT] mapChar - 字符位置映射表
	static void SuffixAndCharMap(const char* sStr, map<string,vector<int32_t> >& mapSuffix, map<char,vector<int32_t> >& mapChar); 

	// 函数名：RFindBandChar
	// 说明：反向查找第一个坏字符(字符串中的字符)，返回该字符在字符串中的相对位置
	// 参数：
	//	[IN] sStr - 字符串
	//	[IN] sSub - 子串
	//	[IN] nSubLen - 子串长度
	//	[IN] offset - 字符串偏移量
	// 返回值：第一个坏字符在子串中的位置，如果不存在坏字符则返回-1
	static int32_t RFindBandChar(const char* sStr, const char* sSub, const int32_t nSubLen, const int32_t offset);

	// 函数名：CharLastPos
	// 说明：获取子串中某个字符在子串中上次出现的位置
	// 参数：
	//	[IN] cChar - 待查找字符
	//	[IN] sSub - 子串
	//	[IN] nCurPos - 当前位置
	// 返回值：字符在子串中上次出现的位置，如果没有返回-1
	static int32_t CharLastPos(const char cBadChar, const char* sSub, const int32_t nCurPos);

	// 函数名：SuffixLastPos
	// 说明：获取子串中某个后缀在子串中上次出现的位置
	// 参数：
	//	[IN] sSub - 子串
	//	[IN] sSubLen - 子串长度
	//	[IN] nSuffixLen - 后缀长度
	//	[IN] mapSuffix - 后缀位置映射表
	static int32_t SuffixLastPos(const char* sSub, const int32_t nSubLen, const int32_t nSuffixLen, map<string,vector<int32_t> >& mapSuffix);
};

}

#endif /* _FENGYOUNG_API_STR_MATCH_BOYER_MOORE_H */
