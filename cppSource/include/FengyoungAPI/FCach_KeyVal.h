
#ifndef _FENGYOUNG_API_F_CACH_KEY_VALUE_H 
#define _FENGYOUNG_API_F_CACH_KEY_VALUE_H 

#include <string>
#include <map>
#include <queue>
using namespace std; 
#include <pthread.h>
#include <stdint.h>
#include <time.h>
#include "ThreadMutex.h"


namespace fengyoung
{



class FCach_KeyVal
{
public: 
	FCach_KeyVal(const uint32_t unTimeoutSec, 
			const uint32_t unMaxCachCnt = _DEFAULT_MAX_CACH_CNT); 
	virtual ~FCach_KeyVal(); 
	
	void Push(const uint64_t key, const char* sVal); 

	string GetVal(const uint64_t key); 
	uint32_t GetTimestamp(const uint64_t key); 

	uint32_t Size(); 

	void Clear(); 

private: 
	// 获取当前时间戳
	static uint32_t CurTimestamp(); 

	//
	static void* CheckTimeout_ThreadProc(void* pParam);  

public: 
	uint32_t m_unTimeoutSec;	// 失效时间(s)
	uint32_t m_unMaxCachCnt;	// 最大缓存数
	map<uint64_t, pair<uint32_t,string> > m_mapCach;	// 缓存数据 	
	queue<pair<uint32_t, uint64_t> > m_queueKey;		// key队列

public: 
	static const uint32_t _DEFAULT_MAX_CACH_CNT; 	// 默认的缓存大小
	static ThreadMutex mutex;	// 线程锁 
}; 

}

#endif /* _FENGYOUNG_API_F_CACH_KEY_VALUE_H */  



