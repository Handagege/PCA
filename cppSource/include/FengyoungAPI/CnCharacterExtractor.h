/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CnCharacterExtractor.h : 汉字提取类CnCharacterExtractor声明
//
// 版本：v1.0 - 2013.04.09 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_CN_CHARACTER_EXTRACTOR_H 
#define _FENGYOUNG_API_CN_CHARACTER_EXTRACTOR_H 

#include <map>
using namespace std;
#include <stdint.h>
#include "PinyinMap.h"
#include "TradSimpConv.h"


namespace fengyoung
{

// 类名：CnCharacterExtractor 
// 说明：汉字提取器，用于从字符串中提取汉字
class CnCharacterExtractor : public PinyinMap, public TradSimpConv
{
public:
	// 构造函数 & 析构函数	
	CnCharacterExtractor(); 
	virtual ~CnCharacterExtractor(); 

	// 函数：LoadResource
	// 说明：载入资源
	// 参数：
	//	[IN] sPinyinMapFile - 拼音码表文件
	//	[IN] sTradSimpFile - 汉字繁简体对应表(繁体to简体)
	// 返回值：载入成功返回true，否则返回false
	bool LoadResource(const char* sPinyinMapFile, const char* sTradSimpFile);

	// 函数名：GetCnCh_asSimp / GetCnCh_asTrad
	// 说明：提取字符串中的简体 / 繁体 汉字串(包括进行繁简体转换)
	// 参数：
	//	[IN] sIn - 输入的字符串
	//	[OUT] sOut - 输出的字符串
	// 返回值：汉字数
	uint32_t GetCnCh_asSimp(const char* sIn, char* sOut);
	uint32_t GetCnCh_asTrad(const char* sIn, char* sOut);

};

}

#endif /* _FENGYOUNG_API_CN_CHARACTER_EXTRACTOR_H */
