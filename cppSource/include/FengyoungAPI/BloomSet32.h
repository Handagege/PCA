/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BloomSet32.h : 32位bloom集合类的声明
//
// 版本：v1.0 - 2013.04.01 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BLOOM_SET32_H
#define _FENGYOUNG_API_BLOOM_SET32_H

#include <map>
#include <vector>
using namespace std; 
#include <stdint.h>

#define _BLOOM_SET32_BUFF_SIZE		(512*1024*1024)		// 数据缓存大小
#define _BLOOM_SET32_COMPRESS_RATE	8			// 压缩比


namespace fengyoung
{

// 类名：BloomSet32
// 说明：32位bloom集合
class BloomSet32
{
public:
	// 构造函数 & 析构函数
	BloomSet32();
	virtual ~BloomSet32();

	// 函数名：Clear
	// 说明：清空集合
	void Clear(); 

	// 函数名：Insert
	// 说明：插入一个对象
	// 参数：
	//	[IN] unItem - 待插入对象
	// 返回值：插入成功返回true，否则返回false（该对象已经存在）
	bool Insert(const uint32_t unItem);  

	// 函数名：IfExist
	// 说明：判断一个对象是否存在
	// 参数：
	//	[IN] unItem - 对象
	// 返回值：对象存在返回true，否则返回fasle
	bool IfExist(const uint32_t unItem);

	// 函数名：Delete
	// 说明：删除一个对象
	// 参数：
	//	[IN] unItem - 对象
	void Delete(const uint32_t unItem);

	// 函数名：GetFront
	// 说明：从前往后获取若干对象，输出对象升序排列
	// 参数：
	//	[OUT] vtrItems - 输出的对象
	//	[IN] unCnt - 待获取对象数
	// 返回值：实际获取对象数
	uint32_t GetFront(vector<uint32_t>& vtrItems, const uint32_t unCnt);
	
	// 函数名：GetBack
	// 说明：从后往前获取若干对象，输出对象降序排列
	// 参数：
	//	[OUT] vtrItems - 输出的对象
	//	[IN] unCnt - 待获取对象数
	// 返回值：实际获取对象数
	uint32_t GetBack(vector<uint32_t>& vtrItems, const uint32_t unCnt);

	// 函数名：DelFront
	// 说明：从前往后删除若干对象
	// 参数：
	//	[IN] unCnt - 待删除对象数
	// 返回值：被删除对象数
	uint32_t DelFront(const uint32_t unCnt); 

	// 函数名：DelBack
	// 说明：从后往前删除若干对象
	// 参数：
	//	[IN] unCnt - 待删除对象数
	// 返回值：被删除对象数
	uint32_t DelBack(const uint32_t unCnt); 

	// 函数名：Size
	// 说明：获取对象数
	// 返回值：集合中的对象数
	uint32_t Size(); 

private:
	// 函数名：CalcPos
	// 说明：计算item在数据缓存中的位置
	// 参数：
	//	[IN] unItem - 对象
	// 返回值：对象在数据缓存中的位置：<byte_pos, bit_pos>
	pair<int32_t,int32_t> CalcPos(const uint32_t unItem);

	// 函数名：CalcItem
	// 说明：通过对象在数据缓存中的位置计算对象值
	// 参数：
	//	[IN] byte_pos - 字节位置
	//	[IN] bit_pos - 位位置
	// 返回值：对象值
	uint32_t CalcItem(const int32_t byte_pos, const int32_t bit_pos);

private:
	uint32_t m_unItemCnt;	// 对象数
	uint8_t* m_pDataBuff;	// 数据缓存
};

}

#endif /* _FENGYOUNG_API_BLOOM_SET32_H */

