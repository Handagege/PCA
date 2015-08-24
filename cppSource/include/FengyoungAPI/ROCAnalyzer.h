/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ROCAnalyzer.h : ROC分析器ROCAnalyzer的声明
//
// 版本：v1.0 - 2013.07.25 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_ROC_ANALYZER_H 
#define _FENGYOUNG_API_ROC_ANALYZER_H 

#include <vector>
#include <map>
#include <algorithm>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

// 标签类型(正、负样本)
enum ELabelType
{
	_POSITIVE,	// 正样本
	_NEGATIVE	// 负样本
};

// Positive & Negative 判定类型
enum EPNDetType
{
	_TP,
	_FN,
	_FP,
	_TN
}; 

// Positive & Negative 判定统计表
// +---------+-----------------------------------------+
// |         |                  预测                   |
// |         +--------------------+--------------------+
// |         |    P(positive)     |    N(negative)     |
// |-----+---+--------------------+--------------------+
// |     | P | tp(true positive)  | fn(false negative) |
// |实际 +---+--------------------+--------------------+
// |     | N | fp(false positive) | tn(true negative)  |
// +-----+---+--------------------+--------------------+
class PNDetTable
{
public: 
	// 构造函数 & 析构函数
	PNDetTable(); 
	PNDetTable(const PNDetTable& table); 
	virtual ~PNDetTable();

	// 清空
	void Clear(); 

	// 重载赋值操作符	
	PNDetTable& operator = (const PNDetTable& table); 

	// 函数名: SampleCnt
	// 说明: 获取总样本数
	uint32_t SampleCnt(); 
	
	// 函数名: RealPositiveCnt / PredPositiveCnt
	// 说明: 获取实际/预测正样本数
	uint32_t RealPositiveCnt(); 
	uint32_t PredPositiveCnt();
	
	// 函数名: RealNegativeCnt / PredNegativeCnt
	// 说明: 获取实际/预测负样本数
	uint32_t RealNegativeCnt(); 
	uint32_t PredNegativeCnt(); 

	// 函数名: TPR
	// 说明：TPR = TP / (TP + FN)
	double TPR(); 

	// 函数名: FPR 
	// 说明：FPR = FP / (FP + TN)
	double FPR(); 

	// 函数名：TNR
	// 说明：TNR = TN / (FP + TN) 
	double TNR(); 

	// 函数名: Precision
	// 说明: 计算准确率, precision = TP / (TP + FP)
	double Precision(); 

	// 函数名: Recall
	// 说明: 计算召回率, recall = TP / (TP + FN) = sensitivity
	double Recall(); 

public: 
	uint32_t m_unCnt[4]; 
}; 


// 类名：ROCAnalyzer
// 说明：ROC(Receiver Operating Characteristic)分析器
class ROCAnalyzer
{
public:
	// 构造函数 & 析构函数
	ROCAnalyzer(const double dScoreFrom, const double dScoreTo); 
	virtual ~ROCAnalyzer();

	// 函数名：Clear
	// 说明：清空当前分析器
	void Clear(); 

	// 函数名：Insert
	// 说明：插入一个样本实际标签 & 分值
	// 参数：
	// 	[IN] label_type - 样本实际标签(正样本 or 负样本)
	// 	[IN] dScore - 样本判定分值
	void Insert(ELabelType label_type, const double dScore); 

	// 函数名：AUCValue
	// 说明：计算AUC(Area Under ROC Curve)值
	double AUCValue(); 

	// 函数名：ROCCurve
	// 说明：获取ROC曲线参数
	// 参数：
	// 	[OUT] curve - ROC曲线参数(判定阈值 & PN判定统计表)
	// 	[IN] step - 阈值步长
	void ROCCurve(vector<pair<double, PNDetTable> >& curve, const double step); 

	uint32_t Count(const ELabelType eType); 

private:
	// 比较样本分值
	static bool Comp(pair<ELabelType,double> a, pair<ELabelType, double> b); 

private: 
	double m_dScoreFrom;	// 分值(开)区间下界
	double m_dScoreTo;		// 分值(开)区间上界
	uint32_t m_unPositiveCnt; // 正样本数
	uint32_t m_unNegativeCnt; // 负样本数

	vector<pair<ELabelType,double> > m_vtrLabelScore;	// 样本实际标签(正、负) & 分值列表	
}; 

}

#endif /* _FENGYOUNG_API_ROC_ANALYZER_H */ 


