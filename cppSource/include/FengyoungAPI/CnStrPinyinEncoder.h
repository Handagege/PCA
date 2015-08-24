/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CnStrPinyinEncoder.h : 汉字串拼音编码类CnStrPinyinEncoder声明
//
// 版本：v1.0 - 2013.04.09 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_CN_STR_PINYIN_ENCODER_H 
#define _FENGYOUNG_API_CN_STR_PINYIN_ENCODER_H 

#include <set>
#include <string>
using namespace std; 
#include <stdint.h>
#include "PinyinMap.h"

namespace fengyoung
{

// 类名：CnStrPinyinEncoder
// 说明：中文字符串编码器
class CnStrPinyinEncoder
{
public:
	// 构造函数 & 析构函数
	CnStrPinyinEncoder(); 
	virtual ~CnStrPinyinEncoder(); 

	// 函数名：LoadPinyinMap
	// 说明：载入拼音映射表
	// 参数：
	//	[IN] sPinyinMapFile - 拼音码表文件
	// 返回值：载入成功返回true，否则返回false
	bool LoadPinyinMap(const char* sPinyinMapFile);

	// 函数名：PinyinCode
	// 说明：对字符串进行拼音编码，返回拼音编码串
	// 参数：
	//	[OUT] encoded - 拼音编码串 
	// 	[IN] sStr - 待编码的字符串
	// 返回值：拼音编码串的长度
	uint32_t PinyinCode(uint8_t* encoded, const char* sStr);

	// 函数名：Encode_8CnChar / Encode_4CnChar / Encode_2CnChar
	// 说明：对字符串进行拼音编码，每n个汉字拼音构成一个特征码（n=8,4,2)
	// 参数：
	//	[OUT] setPinyinCode - 拼音编码集合
	//	[IN] sStr - 待编码的字符串
	void Encode_8CnChar(set<uint64_t>& setPinyinCode, const char* sStr);  
	void Encode_4CnChar(set<uint32_t>& setPinyinCode, const char* sStr);  
	void Encode_2CnChar(set<uint16_t>& setPinyinCode, const char* sStr);  

	// 函数名：EncodeToPyStr
	// 说明：将字符串转换为拼音串（英文保留）
	// 参数：
	//	[OUT] sPyStr - 拼音串
	//	[IN] sStr - 待编码的字符串
	// 返回值：拼音串长度	
	int32_t EncodeToPyStr(char* sPyStr, const char* sStr); 	

protected:
	PinyinMap m_pinyinMap;	// 拼音编码映射表
};

}

#endif /* _FENGYOUNG_API_CN_STR_PINYIN_ENCODER_H */

