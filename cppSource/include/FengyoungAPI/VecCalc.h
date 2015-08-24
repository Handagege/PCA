#ifndef _LINEAR_OPTS_VEC_CALC_H 
#define _LINEAR_OPTS_VEC_CALC_H 

#include <stdint.h>


namespace fengyoung
{

// 类名：VecCalc
// 说明：向量计算类
class VecCalc
{
private: 
	// 构造函数 & 析构函数
	VecCalc(); 
	virtual ~VecCalc(); 

public:
	// 函数名：Print_F / Print_S
	// 说明：打印一个完整向量 / 打印一个稀疏向量	
	// 参数：
	//	[IN] v - 完整向量
	//	[IN] size - 向量长度
	//	[IN] sv - 稀疏向量
	//	[IN] scnt - 稀疏向量中非零元素个数
	static void Print_F(double* v, const int64_t size); 
	static void Print_S(double* sv, const int64_t scnt); 

	// 函数名：Copy_F / Copy_S
	// 说明：copy v to v_out / copy sparse sv to sv_out
	//	[OUT] v_out - 输出的完整向量
	//	[IN] v - 完整向量
	//	[IN] size - 向量长度
	//	[OUT] sv_out - 输出的稀疏向量
	//	[IN] sv - 稀疏向量
	//	[IN] scnt - 稀疏向量中非零元素个数
	static void Copy_F(double* v_out, double* v, const int64_t size); 
	static void Copy_S(double* sv_out, double* sv, const int64_t scnt); 

	// 函数名：Dot_FF / Dot_FS
	// 说明：计算dot(v1, v2) / dot(v1, sv2)
	// 参数：	
	//	[IN] v1, v2 - 完整向量
	//	[IN] size - 向量长度
	//	[IN] sv1, sv2 - 稀疏向量
	//	[IN] scnt1, scnt2 - 稀疏sv1和sv2中非零元素个数
	// 返回值：点乘结果
	static double Dot_FF(double* v1, double* v2, const int64_t size); 
	static double Dot_FS(double* v1, const int64_t size, double* sv2, const int64_t scnt2); 

	// 函数名：ScalWith_F / ScalWith_S
	// 说明：v := alpha * v / sv := alpha * sv
	// 参数：
	//	[IN|OUT] v - 完整向量
	//	[IN] alpha - 常数
	//	[IN] size - 向量长度
	//	[IN|OUT] sv - 稀疏向量
	//	[IN] scnt - 稀疏向量中非零元素个数
	static void ScalWith_F(double* v, const double alpha, const int64_t size); 
	static void ScalWith_S(double* sv, const double alpha, const int64_t scnt); 
	
	// 函数名：Scal_F / Scal_S
	// 说明：v_out := alpha * v / sv_out := alpha * sv
	// 参数：
	//	[OUT] v_out - 输出的完整向量
	//	[IN] alpha - 常数
	//	[IN] v - 完整向量
	//	[IN] size - 向量长度
	//	[OUT] sv_out - 输出的稀疏向量
	//	[IN] sv - 稀疏向量
	//	[IN] scnt - 稀疏向量中非零元素个数
	static void Scal_F(double* v_out, const double alpha, double* v, 
			const int64_t size); 
	static void Scal_S(double* sv_out, const double alpha, double* sv, 
			const int64_t scnt); 

	// 函数名：AddWith_FF
	// 说明：v_out := alpha * v + v_out
	// 参数：
	//	[OUT] v_out - 输出的完整向量
	//	[IN] alpha - 常数
	//	[IN] v - 完整向量
	//	[IN] size - 向量长度
	static void AddWith_FF(double* v_out, const double alpha, double* v, 
			const int64_t size); 

	// 函数名：Add_FF
	// 说明：v_out := alpha * v1 + beta * v2
	// 参数：
	//	[OUT] v_out - 输出的完整向量
	//	[IN] alpha, beta - 常数
	//	[IN] v1, v2 - 完整向量
	//	[IN] size - 向量长度
	static void Add_FF(double* v_out, const double alpha, double* v1, 
			const double beta, double* v2, const int64_t size); 

	// 函数名：ModL1_F / ModL1_S
	// 说明：计算完整向量的L1模 / 计算稀疏向量的L1模
	// 参数：
	//	[IN] v - 完整向量
	//	[IN] size - 向量长度
	//	[IN] sv - 稀疏向量
	//	[IN] scnt - 稀疏向量中非零元素个数
	static double ModL1_F(double* v, const int64_t size); 
	static double ModL1_S(double* sv, const int64_t scnt); 
	
	// 函数名：ModL2_F / ModL2_S
	// 说明：计算完整向量的L2模 / 计算稀疏向量的L2模
	// 参数：
	//	[IN] v - 完整向量
	//	[IN] size - 向量长度
	//	[IN] sv - 稀疏向量
	//	[IN] scnt - 稀疏向量中非零元素个数
	static double ModL2_F(double* v, const int64_t size); 
	static double ModL2_S(double* sv, const int64_t scnt); 
};

}

#endif /* _LINEAR_OPTS_VEC_CALC_H */

