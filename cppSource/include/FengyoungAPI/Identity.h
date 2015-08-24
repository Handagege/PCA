/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Identity.h : 标记生成类声明
//
// 版本：v1.0 - 2014.02.20 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_IDENTITY_H 
#define _FENGYOUNG_API_IDENTITY_H 

#include <stdint.h>


namespace fengyoung
{

// 类名：Identity
// 说明：标记生成类
class Identity
{
private: 
	// 构造函数 & 析构函数
	Identity(); 
	virtual ~Identity(); 

public: 
	static uint64_t AsUint64(); 
	static int64_t AsInt64(); 
};

}

#endif /* _FENGYOUNG_API_IDENTITY_H */

