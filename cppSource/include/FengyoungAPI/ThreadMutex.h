/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ThreadMutex.h : 线程互斥锁ThreadMutex的声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_THREAD_MUTEX_H 
#define _FENGYOUNG_API_THREAD_MUTEX_H 

#include <pthread.h>
#include <stdint.h>

namespace fengyoung
{

// 类名：ThreadMutex 
//	利用互斥量实现的线程锁 
class ThreadMutex
{ 
public:
	// 构造函数 & 析构函数 
	ThreadMutex();
	virtual ~ThreadMutex();

	//加锁
	void Lock() const;

	//尝试锁
	bool TryLock() const;

	//解锁
	void Unlock() const;

protected:
	mutable pthread_mutex_t _mutex;	// 互斥量 
}; 

}

#endif /* _FENGYOUNG_API_THREAD_MUTEX_H */  
 
