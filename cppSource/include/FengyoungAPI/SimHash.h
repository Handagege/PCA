/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SimHash.h : 文本SimHash算法接口声明
//
// 版本：v1.0 - 2013.04.12 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_SIM_HASH_H
#define _FENGYOUNG_API_SIM_HASH_H

#include <vector>
#include <string>
using namespace std;
#include <stdint.h>


namespace fengyoung
{

// 类名：SimHash
// 说明：文本SimHash算法，针对文本的关键词向量计算文本指纹
class SimHash
{
private:
	// 构造函数 & 析构函数	
	SimHash(); 
	virtual ~SimHash(); 

public:
	// 函数名：TxtFingerprint32
	// 说明：通过SimHash算法生成32位文本指纹
	// 参数：
	//	[IN] vtrKeywrods - 文本关键词向量
	//	[IN] unMaxKeywordsCnt - 对关键词向量长度的限制，如果为0则不作限制
	// 返回值：32位的文本指纹
	static uint32_t TxtFingerprint32(vector<pair<string,double> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint32_t TxtFingerprint32(vector<pair<string,float> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint32_t TxtFingerprint32(vector<pair<string,uint32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint32_t TxtFingerprint32(vector<pair<string,int32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);

	// 函数名：TxtFingerprint64
	// 说明：通过SimHash算法生成64位文本指纹
	// 参数：
	//	[IN] vtrKeywrods - 文本关键词向量
	//	[IN] unMaxKeywordsCnt - 对关键词向量长度的限制，如果为0则不作限制
	// 返回值：64位的文本指纹
	static uint64_t TxtFingerprint64(vector<pair<string,double> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint64_t TxtFingerprint64(vector<pair<string,float> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint64_t TxtFingerprint64(vector<pair<string,uint32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint64_t TxtFingerprint64(vector<pair<string,int32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);

private:
	// 对关键词生成32位特征向量
	static void GenKeywordFeatArray32(double* pdArray32, const char* sKeyword, const double dWeight); 

	// 对关键词生成64位特征向量
	static void GenKeywordFeatArray64(double* pdArray64, const char* sKeyword, const double dWeight); 
};

}

#endif /* _FENGYOUNG_API_SIM_HASH_H */


