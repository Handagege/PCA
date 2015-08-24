/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StringSplitter.h : 字符串切分类StringSplitter的声明
//
// 版本：v3.0 - 2011.02.12 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STRING_SPLITTER_H 
#define _FENGYOUNG_API_STRING_SPLITTER_H 

#include <string> 
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// 类名：StringSplitter 
// 说明：字符串切分  
class StringSplitter 
{ 
public: 
	// 函数名：StringSplitter & ~StringSplitter 
	// 说明：构造函数 & 析构函数 
	// 参数：
	//	[IN] sStr - 待解析的字符串
	//	[IN] sDilm - 分隔符 
	//	[IN] bIgnoreSpace - 是否忽略首位空格（或\t）的标志  
	StringSplitter(const char* sStr, const char* sDilm, const bool bIgnoreSpace = true);  
	virtual ~StringSplitter();  

	// 函数名：GetSubString 
	// 说明：获取子字符串
	// 参数：
	//	[IN] bIsFront - true取分隔符前面的子字符串，false取分隔符后面的子字符串
	// 返回值：子字符串  
	string GetSubString(const bool bIsFront = true) const; 
private: 
	// 解析字符串，按照分隔符对字符串进行分割 
	void DoSplit(const char* sStr, const char* sDilm, const bool bIgnoreSpace); 
	// 忽略掉一个字符串首位的空格以及\t 
	void IgnoreSpace(string& str);  

	string m_strFront;	// 前一个子字符串 
	string m_strBack;	// 后一个子字符串 
}; 

}

#endif /* _FENGYOUNG_API_STRING_SPLITTER_H */ 

