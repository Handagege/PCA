/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BiChar.h : 双字字符类BiChar声明 
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BI_CHAR_H 
#define _FENGYOUNG_API_BI_CHAR_H 

#include <iostream>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

// 类名：BiChar
// 说明：双字字符 
class BiChar
{
public:
	// 构造函数 & 析构函数
	BiChar();
	BiChar(const char* sStr);
	BiChar(const char ch_0, const char ch_1);
	BiChar(const BiChar& bi_char);
	virtual ~BiChar();
	
	// 重载操作符
	BiChar& operator = (const BiChar& bi_char);
	bool operator == (const BiChar& bi_char) const;
	bool operator != (const BiChar& bi_char) const;
	bool operator > (const BiChar& bi_char) const;
	bool operator < (const BiChar& bi_char) const;
	
	// 输出双字字符占内存大小
	uint32_t SizeOf();

public: 
	char data[3];
};

}

#endif /* _FENGYOUNG_API_BI_CHAR_H */ 

