/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CircularQueue.h : 循环对列模板类CircularQueue的声明 & 定义
//
// 版本：v1.0 - 2013.07.18 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_CIRCULAR_QUEUR_H 
#define _FENGYOUNG_API_CIRCULAR_QUEUR_H 

#include <vector>
using namespace std; 
#include <stdint.h>


namespace fengyoung 
{


// 类名：CircularQueue
//	循环队列模板类
template <class _T>
class CircularQueue
{
public:
	// 构造函数
	CircularQueue(const int32_t nCapacity) : m_nCapacity(nCapacity), 
										  m_nSize(0),
										  m_nStartPos(0),
										  m_pvtrElement(NULL) 
	{
		m_pvtrElement = new vector<_T>(m_nCapacity); 
	}
	// 拷贝构造函数
	CircularQueue(const CircularQueue<_T>& _circ_queue)
	{
		m_nCapacity = _circ_queue.m_nCapacity;
		m_nSize = _circ_queue.m_nSize;
		m_nStartPos = _circ_queue.m_nStartPos;
		m_pvtrElement = new vector<_T>(m_nCapacity); 
		for(uint32_t i = 0; i < _circ_queue.m_pvtrElement->size(); i++) 
		{
			(*m_pvtrElement)[i] = (*(_circ_queue.m_pvtrElement))[i]; 
		}
	}
	// 析构函数
	virtual ~CircularQueue()
	{
		if(!m_pvtrElement)
		{
			delete m_pvtrElement; 
			m_pvtrElement = NULL; 
		}
	}

	// 重载赋值操作符
	CircularQueue<_T>& operator = (const CircularQueue<_T>& _circ_queue)
	{
		m_nCapacity = _circ_queue.m_nCapacity;
		m_nSize = _circ_queue.m_nSize;
		m_nStartPos = _circ_queue.m_nStartPos;
		m_pvtrElement = new vector<_T>(m_nCapacity); 
		for(uint32_t i = 0; i < _circ_queue.m_pvtrElement->size(); i++) 
		{
			(*m_pvtrElement)[i] = (*(_circ_queue.m_pvtrElement))[i]; 
		}
		return *this; 
	}

	// 函数名：Push
	// 说明：向队列尾部push一个元素，如果队列已满，则会删除头部元素
	// 参数：
	// 	[IN] element - 待push的元素
	void Push(const _T element)
	{
		if(m_nSize < m_nCapacity)
			(*m_pvtrElement)[m_nSize++] = element;  
		else
		{
			(*m_pvtrElement)[m_nStartPos++] = element; 
			if(m_nStartPos >= m_nCapacity)
				m_nStartPos = 0; 
		}
	}

	// 函数名：Get
	// 说明：获取一个元素
	// 参数：
	// 	[OUT] element - 输出的元素
	// 	[IN] nIdx 索引号
	// 返回值：获取成功返回true，否则返回false
	bool Get(_T& element, const int32_t nIdx)
	{
		if(nIdx < 0 || nIdx >= m_nSize)
			return false; 
		int32_t pos = m_nStartPos + nIdx; 
		if(pos >= m_nCapacity)
			pos = pos - m_nCapacity; 
		element = (*m_pvtrElement)[pos];  
		return true; 
	}	

	// 函数名：GetList_InOrder
	// 说明：将队列中的元素顺序输出
	// 参数：
	// 	[OUT] vtrOut - 输出的所有元素列表
	// 返回值：输出的元素数
	int32_t GetList_InOrder(vector<_T>& vtrOut)
	{
		vtrOut.clear(); 
		int32_t pos; 
		for(int32_t i = 0; i < m_nSize; i++) 
		{
			pos = m_nStartPos + i; 
			if(pos >= m_nCapacity)
				pos = pos - m_nCapacity;
			vtrOut.push_back((*m_pvtrElement)[pos]); 
		}
		return m_nSize; 
	}
	
	// 函数名：GetList_Reversed
	// 说明：将队列中的元素反序输出
	// 参数：
	// 	[OUT] vtrOut - 输出的所有元素列表
	// 返回值：输出的元素数
	int32_t GetList_Reversed(vector<_T>& vtrOut)
	{
		vtrOut.clear(); 
		int32_t pos; 
		if(m_nSize >= m_nCapacity)
		{
			for(int32_t i = 0; i < m_nSize; i++) 
			{
				pos = m_nStartPos - i - 1; 
				if(pos < 0)
					pos = m_nCapacity + pos; 
				vtrOut.push_back((*m_pvtrElement)[pos]); 
			}
		}
		else
		{
			for(pos = m_nSize - 1; pos >= 0; pos--) 
			{
				vtrOut.push_back((*m_pvtrElement)[pos]); 
			}
		}
		return m_nSize; 
	}

	// 函数名：Size
	// 说明：获取队列中元素数
	uint32_t Size()
	{
		return (uint32_t)m_nSize; 
	}

	// 函数名：Capacity
	// 说明：获取队列的容量
	uint32_t Capacity()
	{
		return (uint32_t)m_nCapacity; 
	}

	// 函数名：Empty
	// 说明：判断队列是否为空
	bool Empty()
	{
		return (m_nSize == 0); 
	}

	// 函数名：Full
	// 说明：判断队列是否已满
	bool Full()
	{
		return (m_nSize == m_nCapacity); 
	}

private: 
	int32_t m_nCapacity;	// 队列容量
	int32_t m_nSize;		// 存储的元素数
	int32_t m_nStartPos;	// 起点	
	vector<_T>* m_pvtrElement; 
};

}

#endif /* _FENGYOUNG_API_CIRCULAR_QUEUR_H */

