/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Statistic.h : 统计类常用公式声明
//
// 版本：v1.0 - 2011.12.26 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_MATH_STATISTIC_H
#define _FENGYOUNG_API_MATH_STATISTIC_H

#include <vector>
#include <set>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// 类名：Statistic
// 说明：统计类
class Statistic
{
private:
	// 构造函数 & 析构函数
	Statistic();
	virtual ~Statistic();

public:
	// 计算样本均值
	static float SampleMean(vector<float>& vtrValue);
	// 计算样本方差
	static float SampleVariance(vector<float>& vtrValue);
	// 计算众数	
	static set<float> Mode(vector<float>& vtrValue);
	// 计算中列数
	static float Midrange(vector<float>& vtrValue);
	// 最小 & 最大值
	static pair<float,float> MinAndMax(vector<float>& vtrValue);

	// 计算协方差
	static float Covariance(vector<float>& vtrValue1, vector<float>& vtrValue2);

private:
	// 比较两个pair
	static float PairCmp_Second(pair<float,uint32_t> a, pair<float,uint32_t> b);
};

}

#endif /* _FENGYOUNG_API_MATH_STATISTIC_H */

