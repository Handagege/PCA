/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// MathMethod.h : 常用数学公式类声明 
//
// 版本：v1.0 - 2011.09.26 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_MATH_METHOD_H 
#define _FENGYOUNG_API_MATH_METHOD_H 

#include <stdint.h>

#define PI	3.14159265358979323846	// 圆周率
#define EULER	2.71828182845904523536	// 自然常数e


namespace fengyoung
{

// 类名：MathMethod
//	常用一些数学计算的实现
class MathMethod
{ 
public: 
	MathMethod();  
	virtual ~MathMethod(); 

	// 函数名：LogN
	// 说明：求以n为底，a的对数
	// 参数：
	//	[IN] n - 底数
	//	[IN] a - 指数
	// 返回值：以n为底，a的对数 
	static double LogN(const double n, const double a); 
	
	// 函数名：Ln
	// 说明：求以自然数为底，a的对数
	// 参数：
	//	[IN] a - 指数
	// 返回值：ln(a)
	static double Ln(const double a); 

	// 函数名：Exp
	// 说明：求自然数的a次幂
	// 参数：
	//	[IN] a - 幂指数
	// 返回值：exp(a)
	static double Exp(const double a); 

	// 比较a和b，返回其中的最大值 
	static double Max(const double a, const double b);
 
	// 比较a和b，返回其中的最小值 
	static double Min(const double a, const double b); 

	// 获取一个正实数的数量级
	static int32_t Magnitude(const double a); 

	//////////////////////////////////////////////////////////////////////
	// 三角函数
	// 

	// 函数名：Sin Cos Tan Cot
	// 说明：求正弦、余弦、正切、余切
	static double Sin(const double x); 
	static double Cos(const double x); 
	static double Tan(const double x); 
	static double Cot(const double x); 
	
	// 函数名：ArcSin ArcCos ArcTan ArcCot
	// 说明：求反正弦、反余弦、反正切、反余切
	static double ArcSin(const double x); 
	static double ArcCos(const double x); 
	static double ArcTan(const double x); 
	static double ArcCot(const double x); 

	// EOF 	
	//////////////////////////////////////////////////////////////////////
}; 

}

#endif /* _FENGYOUNG_API_MATH_METHOD_H */ 

