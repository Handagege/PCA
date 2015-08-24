#ifndef _LINEAR_OPTS_LOGISTIC_H 
#define _LINEAR_OPTS_LOGISTIC_H 

#include <stdint.h>


namespace fengyoung
{

// 函数名：Logistic
// 说明：Logistic变换相关计算类
class Logistic
{
private:
	// 构造函数 & 析构函数
	Logistic(); 
	virtual ~Logistic(); 

public:
	// 函数名：Sigma
	// 说明：Logistic变换，y = 1/(1+exp(-x))
	// 参数：
	//	[IN] x - 自变量
	// 返回值：Logistic变换结果(因变量y)	
	static double Sigma(const double x);

	// 函数名：Sigma_FF
	// 说明：Logistic回归函数
	//		 参与计算的特征权重向量以及特征向量都是完整向量
	// 参数：
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] xi - 特征向量
	//	[IN] vec_size - 特征向量长度
	// 返回值：Logistic回归值
	static double Sigma_FF(double* w, const double yi, double* xi, 
			const int64_t vec_size); 

	// 函数名：Sigma_FS
	// 说明：Logistic回归函数
	//		 参与计算的特征权重向量是完整向量，特征向量是稀疏向量
	// 参数：
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] sxi - 特征向量(稀疏向量)
	//	[IN] vec_size - 特征向量长度
	//	[IN] scnt - 稀疏的特征向量中非零元素个数
	// 返回值：Logistic回归值
	static double Sigma_FS(double* w, const double yi, double* sxi, 
			const int64_t vec_size, const int64_t scnt); 
	
	// 函数名：CostFunc_FF
	// 说明：Logistic回归中的损失函数
	//		 参与计算的特征权重向量以及特征向量都是完整向量
	// 参数：
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] xi - 特征向量
	//	[IN] vec_size - 特征向量长度
	// 返回值：Logistic回归损失函数值
	static double CostFunc_FF(double* w, const double yi, double* xi, 
			const int64_t vec_size); 
	
	// 函数名：CostFunc_FS
	// 说明：Logistic回归中的损失函数
	//		 参与计算的特征权重向量是完整向量，特征向量是稀疏向量
	// 参数：
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] sxi - 特征向量(稀疏向量)
	//	[IN] vec_size - 特征向量长度
	//	[IN] scnt - 稀疏的特征向量中非零元素个数
	// 返回值：Logistic回归损失函数值
	static double CostFunc_FS(double* w, const double yi, double* sxi, 
			const int64_t vec_size, const int64_t scnt); 
	
	// 函数名：CostFuncGrad_FF
	// 说明：计算Logistic回归中损失函数的梯度
	//		 参与计算的特征权重向量以及特征向量都是完整向量
	//	[OUT] g - 损失函数的梯度向量
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] xi - 特征向量
	//	[IN] vec_size - 特征向量长度
	static void CostFuncGrad_FF(double* g, const double yi, double* w, 
			double* xi, const int64_t vec_size);
	
	// 函数名：CostFuncGrad_FS
	// 说明：计算Logistic回归中损失函数的梯度
	//		 参与计算的特征权重向量是完整向量，特征向量是稀疏向量
	//	[OUT] g - 损失函数的梯度向量(完整向量)
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] sxi - 特征向量(稀疏向量)
	//	[IN] vec_size - 特征向量长度
	//	[IN] scnt - 稀疏的特征向量中非零元素个数
	static void CostFuncGrad_FS(double* g, const double yi, double* w, 
			double* sxi, const int64_t vec_size, const int64_t scnt);

	// 函数名：CostFuncWithGrad_FF
	// 说明：计算Logistic回归中损失函数以及损失函数的梯度
	//		 参与计算的特征权重向量以及特征向量都是完整向量
	//	[OUT] cost - 损失函数值
	//	[OUT] g - 损失函数的梯度向量
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] xi - 特征向量
	//	[IN] vec_size - 特征向量长度
	static void CostFuncWithGrad_FF(double& cost, double* g, const double yi, 
			double* w, double* xi, const int64_t vec_size);
	
	// 函数名：CostFuncWithGrad_FS
	// 说明：计算Logistic回归中损失函数以及损失函数的梯度
	//		 参与计算的特征权重向量是完整向量，特征向量是稀疏向量
	//	[OUT] cost - 损失函数值
	//	[OUT] g - 损失函数的梯度向量(完整向量)
	//	[IN] w - 特征权重向量
	//	[IN] yi - 样本分类标签(+1 or -1)
	//	[IN] sxi - 特征向量(稀疏向量)
	//	[IN] vec_size - 特征向量长度
	//	[IN] scnt - 稀疏的特征向量中非零元素个数
	static void CostFuncWithGrad_FS(double& cost, double* g, const double yi, 
			double* w, double* sxi, const int64_t vec_size, const int64_t scnt);
};

}

#endif /* _LINEAR_OPTS_LOGISTIC_H */

