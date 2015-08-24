/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Random.h : 各种随机函数的声明 
//
// 版本：v1.0 - 2011.03.10 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_RANDOM_H
#define _FENGYOUNG_API_RANDOM_H

#include <set>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

class Random 
{
private:
	// 构造函数 & 析构函数
	Random();
	virtual ~Random();

public:
	// 函数名：RandomDistri
	// 说明：按随机分布产生一个随机值
	// 参数：
	//	[IN] unLowerLimit - 区间下限 
	//	[IN] unUpperLimit - 区间上限
	// 返回值：(区间内)符合随机分布的随机值	
	static uint32_t RandomDistri();
	static uint32_t RandomDistri(const uint32_t unLowerLimit, const uint32_t unUpperLimit); 

	// 函数名：RandomDistriN
	// 说明：按随机分布产生N个不同的随机值
	// 参数：
	// 	[OUT] setRandom - 随机值集合
	//	[IN] unLowerLimit - 区间下限 
	//	[IN] unUpperLimit - 区间上限
	//	[IN] n - 随机值个数
	// 返回值：实际产生的随机值个数
	static uint32_t RandomDistriN(set<uint32_t>& setRandom, const uint32_t n);
	static uint32_t RandomDistriN(set<uint32_t>& setRandom, const uint32_t unLowerLimit, 
			const uint32_t unUpperLimit, const uint32_t n); 

private:	
	static uint32_t HRandomDistriN(set<uint32_t>& setRandom, const uint32_t unLowerLimit, 
			const uint32_t unUpperLimit, const uint32_t n); 
};

}

#endif /* _FENGYOUNG_API_RANDOM_H */

