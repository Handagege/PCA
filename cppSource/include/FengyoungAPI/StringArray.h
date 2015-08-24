/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StringArray.h : 字符串序列类StringArray的声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STRING_ARRAY_H 
#define _FENGYOUNG_API_STRING_ARRAY_H 

#include <string> 
#include <vector> 
using namespace std; 
#include <stdint.h> 

namespace fengyoung
{

// 类名: StringArray 
// 说明: 字符串序列类 
class StringArray 
{
public: 
	// 构造函数 & 析构函数  
	// 参数：
	//	[IN] sStr - 包含序列所有字符串的完整字符串
	//	[IN] sDilm - 分隔符  
	StringArray(const char* sStr, const char* sDilm);   
	virtual ~StringArray(); 

	// 函数名：GetString 
	// 说明：获取一个字符串 
	// 参数：
	//	[IN] unIdx - 字符串在当前序列中的索引号 
	// 返回值：索引号对应的字符串  
	string GetString(const uint32_t unIdx) const; 
	
	// 函数名：Count
	// 说明：获取当前序列中的字符串数目
	// 返回值：当前序列中的字符串数目
	uint32_t Count() const; 
private: 
	// 对一个完整的序列字符串进行分解，获取序列  
	void Decompose(const char* sStr, const char* sDilm); 
	
	vector<string> m_vtrString; 	// 字符串向量 
};  

}

#endif /* _FENGYOUNG_API_STRING_ARRAY_H */ 

