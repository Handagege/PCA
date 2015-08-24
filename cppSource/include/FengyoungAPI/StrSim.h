/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrSim.h : 字符串匹配类StrSim声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_SIM
#define _FENGYOUNG_API_STR_SIM

#include <map>
#include <vector>
#include <string>
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// 类名：StrSim
//	字符串匹配计算类
class StrSim
{
private:
	// 构造函数 & 析构函数
	StrSim(); 
	virtual ~StrSim(); 

public:
	// 函数名：EditDistance
	// 说明：计算两个字符串之间的编辑距离
	// 参数：
	//	[IN] sSrc - 源字符串
	//	[OUT] sTarget - 目标字符串
	// 返回值：目标字符串相对源字符串的编辑距离
	static int32_t EditDistance(const char* sSrc, const char* sTarget);
};

}

#endif /* _FENGYOUNG_API_STR_SIM */
