/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Attenuation.h : 衰减函数类声明 
//
// 版本：v1.0 - 2012.08.13 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_ATTENUATION_H 
#define _FENGYOUNG_API_ATTENUATION_H 

#include <stdint.h>


namespace fengyoung
{

// 类名：Attenuation 
// 说明：衰减函数
class Attenuation 
{
private:
	// 构造函数 & 析构函数
	Attenuation();
	virtual ~Attenuation(); 

public:
	// 函数名：Linear
	// 说明：线性衰减 y = f(x) = ax+b
	//	 a = - r / (2*h)，r为衰减幅度，h为半衰期
	//	 b = r + 1
	// 参数：
	//	[IN] x - x变量
	//	[IN] att_range - 衰减幅度
	// 	[IN] half_lift - 半衰期	
	// 返回值：衰减值
	static double Linear(const double x, const double att_range, const double half_life); 

	// 函数名：Exponential
	// 说明：指数衰减 y = f(x) = exp[b/(1+x/a)]; 
	//	 a = h * ln((r+2)/2) / ln((2r+2)/(r+2))，r为衰减幅度，h为半衰期 
	//	 b = ln(r+1)
	// 参数：
	//	[IN] x - x变量
	//	[IN] att_range - 衰减幅度
	// 	[IN] half_lift - 半衰期	
	// 返回值：衰减值
	static double Exponential(const double x, const double att_range, const double half_life); 
};

}

#endif /* _FENGYOUNG_API_ATTENUATION_H */ 


