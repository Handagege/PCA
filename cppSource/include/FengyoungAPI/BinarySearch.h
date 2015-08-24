/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BinarySearch.h : 二分查找方法(模板函数)的声明 & 定义
//
// 版本：v1.0 - 2013.04.01 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BINARY_SEARCH_H 
#define _FENGYOUNG_API_BINARY_SEARCH_H

#include <vector>
#include <map>
using namespace std;


namespace fengyoung
{

// 函数名：BinarySearch
// 说明：对有序队列进行二分查找
// 参数：
//	[IN] vtrSorted - 有序队列
//	[IN] key - 待查找的key
//	[IN] _start_pos - 进行查找的起始位置（小于0则以0为起始位置）
//	[IN] _end_pos - 进行查找的终止位置（小于0或大于队列的最末位，则以队列最末位为终止位置）
// 返回值：key所在的位置
template <class _K>
int32_t BinarySearch(vector<_K>& vtrSorted, const _K key, const int32_t _start_pos = -1, const int32_t _end_pos = -1); 

// 函数名：BinarySearch
// 说明：对有key-value序队列进行二分查找
// 参数：
//	[IN] vtrSortedMap - 有序的key-value队列
//	[IN] key - 待查找的key
//	[IN] _start_pos - 进行查找的起始位置（小于0则以0为起始位置）
//	[IN] _end_pos - 进行查找的终止位置（小于0或大于队列的最末位，则以队列最末位为终止位置）
// 返回值：key所在的位置
template <class _K, class _V>
int32_t BinarySearch(vector<pair<_K,_V> >& vtrSortedMap, const _K key, const int32_t _start_pos = -1, const int32_t _end_pos = -1); 

}



// 对有序队列进行二分查找
template <class _K>
int32_t fengyoung::BinarySearch(vector<_K>& vtrSorted, const _K key, const int32_t _start_pos, const int32_t _end_pos)
{
	int32_t size = (int32_t)vtrSorted.size(); 
	if(size <= 0)
	  return -1; 
	if(_start_pos > _end_pos && (_start_pos >= 0 || _end_pos >= 0))
	  return -1;

	int32_t left = _start_pos >= 0 ? _start_pos : 0;	// 左边界
	int32_t right = ((_end_pos >= 0) && (_end_pos < size)) ? _end_pos : (size - 1);		// 右边界
	int32_t mid;	// 中值 

	while(left <= right)
	{
		mid = (left + right) / 2; 
		if(key < vtrSorted[mid])
		{
			right = mid - 1; 
		}
		else if(key > vtrSorted[mid])
		{
			left = mid + 1; 
		}
		else
		{
			return mid; 
		}
	}

	return -1; 
}


// 对有key-value序队列进行二分查找
template <class _K, class _V>
int32_t fengyoung::BinarySearch(vector<pair<_K,_V> >& vtrSortedMap, const _K key, const int32_t _start_pos, const int32_t _end_pos)
{
	int32_t size = (int32_t)vtrSortedMap.size(); 
	if(size <= 0)
	  return -1; 
	if(_start_pos > _end_pos && (_start_pos >= 0 || _end_pos >= 0))
	  return -1;

	int32_t left = _start_pos >= 0 ? _start_pos : 0;	// 左边界
	int32_t right = ((_end_pos >= 0) && (_end_pos < size)) ? _end_pos : (size - 1);		// 右边界
	int32_t mid;	// 中值 

	while(left <= right)
	{
		mid = (left + right) / 2; 
		if(key < vtrSortedMap[mid].first)
		{
			right = mid - 1; 
		}
		else if(key > vtrSortedMap[mid].first)
		{
			left = mid + 1; 
		}
		else
		{
			return mid; 
		}
	}

	return -1; 
}


#endif /* _FENGYOUNG_API_BINARY_SEARCH_H */


