/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// UintHash.h : 无符号整数的hash算法接口声明
//
// 版本：v1.0 - 2011.03.10 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_UINT_HASH_H
#define _FENGYOUNG_API_UINT_HASH_H

#include <stdint.h>

namespace fengyoung
{

// 类名：UintHash
// 说明：无符号整数的hash算法
class UintHash
{
private: 
	// 构造函数 & 析构函数
	UintHash(); 
	virtual ~UintHash(); 

public: 
	// 无符号整数hash函数
	static uint32_t Uint32HashCode(const uint32_t unKey, const uint32_t unHashCnt);
	static uint32_t Uint64HashCode(const uint64_t unKey, const uint32_t unHashCnt);
};

}

#endif /* _FENGYOUNG_API_UINT_HASH_H */


