/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ThreadRWLock.h : 线程读写锁ThreadRWLock的声明
//
// 版本：v1.0 - 2015.01.09 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_THREAD_RW_LOCK_H 
#define _FENGYOUNG_API_THREAD_RW_LOCK_H 

#include <pthread.h>
#include <stdint.h>

namespace fengyoung
{

// 类名：ThreadRWLock 
//	线程读写锁 
class ThreadRWLock
{ 
public:
	// 构造函数 & 析构函数 
	ThreadRWLock();
	virtual ~ThreadRWLock();

	//加锁
	void RdLock() const;
	void WrLock() const;

	//尝试锁
	bool TryRdLock() const;
	bool TryWrLock() const;

	//解锁
	void Unlock() const;

protected:
	mutable pthread_rwlock_t _rw_lock;	// 读写锁 
}; 

}

#endif /* _FENGYOUNG_API_THREAD_RW_LOCK_H */  
 
