/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StringTokenizer.h : 字符串Token解析类StringTokenizer的声明
//
// 版本：v3.0 - 2011.02.12 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STRING_TOKENIZER_H 
#define _FENGYOUNG_API_STRING_TOKENIZER_H 

#include <string> 
#include <queue> 
using namespace std; 
#include <stdint.h> 

namespace fengyoung
{

// 类名：StringTokenizer 
// 说明：字符串Token解析 
class StringTokenizer 
{ 
public: 
	// 函数名：StringTokenizer & ~StringTokenizer 
	// 说明：构造函数 & 析构函数 
	// 参数：
	//	[IN] sStr - 待解析的字符串
	//	[IN] sDilm - token分隔符 
	//	[IN] bIgnoreSpace - 是否忽略首位空格（或\t）的标志  
	StringTokenizer(const char* sStr, const char* sDilm, const bool bIgnoreSpace = true);  
	virtual ~StringTokenizer(); 

	// 函数名：HasMoreToken 
	// 说明：判断该字符串中是否还包含token 
	// 返回值：true表示还包含token；false表示已没有更多的token
	bool HasMoreToken() const; 
	
	// 函数名：NextToken 
	// 说明：获取下一个token字符串
	// 返回值：token字符串 
	string NextToken(); 

	// 函数名：TokenCount 
	// 说明：获取token数目
	// 返回值：token数目 
	uint32_t TokenCount() const; 
 
private: 
	// 解析字符串，按照token分隔符对字符串进行分割 
	void Decompose(const char* sStr, const char* sDilm, const bool bIgnoreSpace); 
	// 忽略掉一个字符串首位的空格以及\t 
	void IgnoreSpace(string& str); 

	queue<string> m_queToken;	// token队列 
}; 

}

#endif /* _FENGYOUNG_API_STRING_TOKENIZER_H */  

