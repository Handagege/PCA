/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TradSimpConv.h : 汉字繁简体转换类TradSimpConv声明
//
// 版本：v1.0 - 2013.04.09 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_TRAD_SIMP_CONV_H
#define _FENGYOUNG_API_TRAD_SIMP_CONV_H

#include <map>
using namespace std; 
#include <stdint.h>
#include "BiChar.h"

namespace fengyoung
{

// 类名：TradSimpConv
// 说明：汉字繁简体转换
class TradSimpConv
{
public:
	// 构造函数 & 析构函数
	TradSimpConv(); 
	virtual ~TradSimpConv();

	// 函数名：LoadTradSimpMapFromFile
	// 说明：从文件中载入汉字繁简体对应表(繁体to简体)
	// 参数：
	//	[IN] sFile - 汉字繁简体对应表(繁体to简体)
	// 返回值：成功返回true，否则返回false
	bool LoadTradSimpMapFromFile(const char* sFile); 

	// 函数名：Convert_TradToSimp / Convert_SimpToTrad
	// 说明：繁体转简体 / 简体转繁体
	// 参数：
	//	[IN] sIn - 输入的字符串
	//	[OUT] sOut - 输出的字符串
	// 返回值：发生转换的汉字数
	uint32_t Convert_TradToSimp(const char* sIn, char* sOut); 
	uint32_t Convert_SimpToTrad(const char* sIn, char* sOut); 


protected: 
	map<BiChar, BiChar> m_mapTradToSimp;	// 繁体to简体码表
	map<BiChar, BiChar> m_mapSimpToTrad;	// 简体to繁体码表
};

}

#endif /* _FENGYOUNG_API_TRAD_SIMP_CONV_H */ 

