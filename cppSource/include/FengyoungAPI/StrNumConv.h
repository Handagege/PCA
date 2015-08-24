/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrNumConv.h : 字符串数字和数值型数字转换类StrNumConv的声明
//
// 版本：v1.0 - 2012.02.12 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_NUMERIC_CONV_H 
#define _FENGYOUNG_API_STR_NUMERIC_CONV_H 

#include <string>
using namespace std; 
#include <stdint.h>

#define _DOUBLE_MAX_ACCURACY	16	// double的最大精度（double的最大精度为15~16位，最后一位无法保证准确性）
#define _FLOAT_MAX_ACCURACY	7	// float的最大精度（float的最大精度为6~7位，最后一位无法保证准确性）


namespace fengyoung
{

// 数值编码枚举
enum ENumericCodec 
{
	_NUMERIC_CODEC_HEX,		// 16进制
	_NUMERIC_CODEC_DEC,		// 10进制
	_NUMERIC_CODEC_BIN,		// 2进制
};


// 类名：StrNumConv
//	字符串和数字之间的转换类
class StrNumConv
{
private:
	// 构造函数 & 析构函数	
	StrNumConv(); 
	virtual ~StrNumConv(); 
public:
	// 函数名：BitmapToStr
	// 说明：bitmap 转 str
	// 参数：
	// 	[IN] unBitmap - bitmap
	// 	[IN] bits - 位数
	// 返回值：bitmap字符串
	static string BitmapToStr(const uint32_t unBitmap, const uint32_t bits = 32);
	
	// 函数名：StrToBitmap
	// 说明：str 转 bitmap
	// 参数：
	// 	[IN] sStrBitmap - bitmap字符串
	// 返回值：bitmap
	static uint32_t StrToBitmap(const char* sStrBitmap); 

	// 函数名：DoubleToStr
	// 说明：double 转 str
	// 参数：
	//	[IN] num - 待转换的double型数值
	//	[IN] accuracy - 精度（精确到小数点后的位数），超出范围（<0或大于最大精度）取最大精度
	// 返回值：字符串型数值
	static string DoubleToStr(const double num, const int32_t accuracy = _DOUBLE_MAX_ACCURACY); 
	static string DoubleToString(const double num); 

	// 函数名：FloatToStr
	// 说明：float 转 str
	// 参数：
	//	[IN] num - 待转换的float型数值
	//	[IN] accuracy - 精度（精确到小数点后的位数），超出范围（<0或大于最大精度）取最大精度
	// 返回值：字符串型数值
	static string FloatToStr(const float num, const int32_t accuracy = _FLOAT_MAX_ACCURACY); 

	// 函数名：StrToDouble
	// 说明：str 转 double
	// 参数：
	//	[IN] sNum - 待转换的字符串数值
	// 返回值：double数值
	static double StrToDouble(const char* sNum);

	// 函数名：StrToUint32 / StrToUint64
	// 说明：字符串无符号整型转 uint32_t / uint64_t
	// 参数：
	//	[IN] sNum - 待转换的字符串数值
	//	[IN] eInCodec - 输入的进制类型
	// 返回值：uint32_t / uint64_t 型数值
	static uint32_t StrToUint32(const char* sNum, const ENumericCodec eInCodec = _NUMERIC_CODEC_DEC);
	static uint64_t StrToUint64(const char* sNum, const ENumericCodec eInCodec = _NUMERIC_CODEC_DEC);
	
	// 函数名：Uint32ToStr / Uint64ToStr
	// 说明：32位 / 64位 无符号整型转string
	// 参数：
	//	[IN] num - 待转换的无符号整型数值
	//	[IN] align - 最小对齐位数，为负值无效
	//	[IN] eOutCodec - 输出的进制类型
	// 返回值：字符串型的无符号整数
	static string Uint32ToStr(const uint32_t num, const int32_t align = -1, const ENumericCodec eOutCodec = _NUMERIC_CODEC_DEC);
	static string Uint64ToStr(const uint64_t num, const int32_t align = -1, const ENumericCodec eOutCodec = _NUMERIC_CODEC_DEC);

private:
	// 函数名：Uint64toStr_asBinary
	// 说明：uint64_t 转换成 二进制表示的str
	// 参数：
	//	[IN] num - 待转换的无符号整型数值
	//	[IN] align - 最小对齐位数，为负值无效
	// 返回值：二进制表示的字符串型数值
	static string Uint64toStr_asBinary(const uint64_t num, const int32_t align); 

	// 函数名：StrToUint64_fromBinary
	// 说明：二进制表示的str 转换成 uint64_t 
	// 参数：
	//	[IN] sNum - 待转换的字符串数值
	// 返回值：64位 无符号整型数值
	static uint64_t StrToUint64_fromBinary(const char* sNum); 
};

}

#endif /* _FENGYOUNG_API_STR_NUMERIC_CONV_H */ 

