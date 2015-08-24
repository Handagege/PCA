/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrMarkExp.h : 字符串标记操作类StrMarkExp声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_MARK_EXP_H 
#define _FENGYOUNG_API_STR_MARK_EXP_H 

#include <set> 
using namespace std; 
#include <stdint.h> 
#include "BiChar.h"


namespace fengyoung
{

// 空格类型枚举
enum EBlankType
{
	_BLANK_EN,	// ' '
	_BLANK_CN,	// '　'
	_BLANK_TAB,	// '\t'
	_BLANK_NOT	// 非空格
}; 


// 类名：StrMarkExp
//	字符串标记操作类 
class StrMarkExp 
{
private:
	// 构造函数 & 析构函数	
	StrMarkExp(); 
	virtual ~StrMarkExp(); 
public:
       	// 将字符串中的所有小写英文字符改为大写 	
	static void ConvEnUp(char* sBuf); 
       	// 将字符串中的所有大写英文字符改为小写 	
	static void ConvEnLow(char* sBuf); 

	// 函数名：FilterShortURL
	// 说明：过滤文本中的短链
	// 参数：
	//      [IN/OUT] sBuf - 输入的字符串，输出时过滤掉短链
	// 返回值：返回过滤掉的<短链数, 过滤掉的字符串长度>
	static pair<uint32_t,uint32_t> FilterShortURL(char* sBuf); 

	// 提取文本中的短链
	static uint32_t ExtShortURL(set<string>& setURLs, char* sBuf); 
	
	// 函数名：FilterExpSymbol
	// 说明：过滤字符串中的表情符 
	// 参数：
	//      [IN/OUT] sBuf - 输入的字符串，输出时过滤掉表情符
	// 返回值：返回过滤掉的<表情数, 过滤掉的字符串长度>
	static pair<uint32_t,uint32_t> FilterExpSymbol(char* sBuf);

	// 函数名：FilterGreeting
	// 说明：过滤字符串中的“@$”
	// 参数：
	//      [IN/OUT] sBuf - 输入的字符串，输出时过滤掉"@$"
	// 返回值：返回过滤掉的<@数目, 过滤掉的字符串长度>
	static pair<uint32_t,uint32_t> FilterGreeting(char* sBuf); 

	// 函数名：IgnoreHTMLSign
	// 说明：剔除一个字符串中的html标记 
	// 参数：
	//	[IN/OUT] sBuf - 输入的字符串，输出时过滤HTML标记 
	// 返回值：被剔除的字符串总长度
	static uint32_t IgnoreHTMLSign(char* sBuf); 

	// 函数名：IgnoreSignTerm	
	// 说明：过滤掉一些特殊的标记词
	// 参数：
	//	[IN/OUT] sBuf - 输入的字符串，输出时过滤HTML标记 
	//	[IN] sSignTerm - 需要被剔除的词
	// 返回值：被剔除的字符串总长度
	static uint32_t IgnoreSignTerm(char* sBuf, const char* sSignTerm);

	// 函数名：FilterTag
	// 说明：过滤文本中的标注"【】"
	// 参数：
	//      [IN/OUT] sBuf - 输入的字符串，输出时过滤"【】"中的内容 
	// 返回值：返回过滤掉的<标注块数目,过滤掉的字符串长度>
	static pair<uint32_t,uint32_t> FilterTag(char* sBuf); 
	
	// 函数名：IsPureNum
	// 说明：判断一个字符串是否是纯数字（如果是数字带标点按纯数字对待）
	// 参数：
	//	[IN] sStr - 待检测的字符串
	static bool IsPureNum(const char* sStr);

	// 函数名：ConvNumCnToArab
	// 说明：将字符串中的中文数字转换成阿拉伯数字
	// 参数：
	//      [IN/OUT] sBuf - 输入的字符串，输出时将其中的中文数字转换成阿拉伯数字(半角)
	// 返回值：输出字符串的长度
	static uint32_t ConvNumCnToArab(char* sBuf); 

	// 函数名：NumRate
	// 说明：计算一个字符串中数字（含中文数字）占比
	// 参数：
	//	[IN] sStr - 待检测的字符串
	static double NumRate(const char* sStr); 

	// 函数名：NoCnRate
	// 说明：计算一个字符串中非汉字占比（中文标点不算汉字）
	// 参数：
	//	[IN] sStr - 待检测的字符串
	//	[IN] bExceptCnNum - 是否将中文数字不算作汉字
	static double NoCnRate(const char* sStr, const bool bExceptCnNum = false); 

	// 函数名：IgnoreBlanks
	// 说明：剔除掉字符串中的多余空格，包括全角空格、半角空格、tab
	// 参数：
	//      [IN/OUT] sBuf - 输入的字符串，输出时过滤掉其中所有的多余空格
	// 返回值：被剔除的字符串总长度
	static uint32_t IgnoreBlanks(char* sBuf);

	// 函数名：IgnoreEnPunctFrontBack
	// 说明：剔除一个字符串前后的英文标点符号 
	// 参数：
	//	[IN/OUT] sBuf - 输入的字符串，输出时过滤掉首尾的英文标点符号
	// 返回值：被剔除的字符串总长度
	static uint32_t IgnoreEnPunctFrontBack(char* sBuf); 

	// 函数名：IgnoreCnPunctFrontBack
	// 说明：剔除一个字符串前后的中文标点符号 
	// 参数：
	//	[IN/OUT] sBuf - 输入的字符串，输出时过滤掉首尾的中文标点符号
	// 返回值：被剔除的字符串总长度
	static uint32_t IgnoreCnPunctFrontBack(char* sBuf); 
	
	// 函数名：IgnorePunctFrontBack
	// 说明：剔除一个字符串前后的中、英文标点符号 
	// 参数：
	//	[IN/OUT] sBuf - 输入的字符串，输出时过滤掉首尾的中、英文标点符号
	// 返回值：被剔除的字符串总长度
	static uint32_t IgnorePunctFrontBack(char* sBuf); 

	// 判断一个中文字符串是否是AAB、ABB、AABB模式
	static bool IsCnAAB(const char* sStr); 
	static bool IsCnABB(const char* sStr); 
	static bool IsCnAABB(const char* sStr); 
private:
	// 初始化英文标点集 
	static void InitEnPunctSet();  
	// 初始化中文标点集 
	static void InitCnPunctSet(); 
	// 识别一个字符串从偏移量开始的空格类型
	static EBlankType BlankType(const char* sStr, const uint32_t unOffset = 0);
	// 判断一个字符串从偏移量开始是否是英文标点
	static bool IsEnPunctuation(const char* sStr, const uint32_t unOffset = 0); 
	// 判断一个字符串从偏移量开始是否是中文文标点
	static bool IsCnPunctuation(const char* sStr, const uint32_t unOffset = 0); 
	// 从偏移位开始，查找紧邻的连续英文（含数字）的子字符串，并返回子串长度。如果不含紧邻连续英文子串，则返回0
	static uint32_t NeighborEnSubStrLen(const char* sStr, const uint32_t unOffset = 0);
	// 从偏移位开始，查找紧邻的连续非分隔符（中英文标点、空格）的子字符串，并返回字串长度。如果不含紧邻连续子串，则返回0
	static uint32_t NeighborSubStrLen(const char* sStr, const uint32_t unOffset = 0);

	static set<char> m_setEnPunct;		// 英文标点集  
	static set<BiChar> m_setCnPunct; 	// 中文标点集
}; 

}

#endif /* _FENGYOUNG_API_STR_MARK_EXP_H */ 

 
