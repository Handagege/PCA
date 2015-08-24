/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// PinyinMap.h : 拼音映射表类PinyinMap声明
//
// 版本：v1.0 - 2013.04.09 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_PINYIN_MAP_H 
#define _FENGYOUNG_API_PINYIN_MAP_H 

#include <map>
using namespace std;
#include <stdint.h>
#include "BiChar.h"

namespace fengyoung
{

// 类名：PinyinMap
// 说明：拼音映射表
class PinyinMap 
{
public:
	// 构造函数 & 析构函数 
	PinyinMap();
	virtual ~PinyinMap();

	// 函数名：ReadPinyinMap
	// 说明：从文件中读取拼音映射
	// 参数：
	//	[IN] sFile - 拼音映射码表
	// 返回值：读取成功返回true，否则返回false
	bool ReadPinyinMap(const char* sFile);

	// 函数名：GetCode
	// 说明：获取汉字的拼音编码
	// 参数：
	//	[OUT] code - 拼音编码
	//	[IN] sCh - 中文字符
	bool GetCode(uint8_t& code, const char* sCh);

	// 函数名：GetPinyin
	// 说明：获取汉字的拼音
	// 参数：
	//	[IN] sCh - 中文字符
	// 返回值：中文字符对应的拼音
	string GetPinyin(const char* sCh); 

protected:
	uint8_t m_maxPinyinCode;	// 最大的拼音编码
	map<BiChar, pair<string,uint8_t> > m_mapBiChar2PinyinCode;	// 中文字符->拼音编码 映射表
};

}

#endif /* _FENGYOUNG_API_PINYIN_MAP_H */


