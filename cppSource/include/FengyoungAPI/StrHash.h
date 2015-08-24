/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrHash.h : 字符串hash算法接口声明
//
// 版本：v1.0 - 2012.05.29 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_HASH_H
#define _FENGYOUNG_API_STR_HASH_H

#include <stdint.h>

namespace fengyoung
{

// 类名：StrHash
// 说明：字符串hash算法
class StrHash
{
private: 
	// 构造函数 & 析构函数
	StrHash(); 
	virtual ~StrHash(); 

public:
	// BKDR算法	
	static uint32_t BKDRHash_asUint32(const char* sStr); 
	static uint64_t BKDRHash_asUint64(const char* sStr);

	// 字符串hash
	static uint32_t HashCode_asUint32(const char* sStr, const uint32_t unHashCnt);  
	static uint64_t HashCode_asUint64(const char* sStr, const uint64_t unHashCnt);  
};

}

#endif /* _FENGYOUNG_API_STR_HASH_H */


