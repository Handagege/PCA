/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Histogram.h : 直方图类Histogram的声明 
//
// 版本：v1.0 - 2011.12.26 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_HISTOGRAM_H
#define _FENGYOUNG_API_HISTOGRAM_H

#include <vector>
#include <map>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// 类名：Histogram
// 说明：直方图类
class Histogram
{
public:
	// 构造函数 & 析构函数
	Histogram(const double fStep);
	Histogram(const double max, const double min, const uint32_t seg); 
	virtual ~Histogram();

	// 提取直方图
	void Extract(vector<double>& vtrValue);

	// 获取直方图结果
	uint32_t GetHist(vector<pair<double,uint32_t> >& vtrHist);	
	
private:
	double m_fStep;	// 窗口步长
	map<int32_t,uint32_t> m_mapHist;	// 直方图映射表
};

}

#endif /* _FENGYOUNG_API_HISTOGRAM_H */

