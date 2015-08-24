/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// FBuffer.h : 数据缓存类FBuffer声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_F_BUFFER_H 
#define _FENGYOUNG_API_F_BUFFER_H 

#include <string>
#include <set>
using namespace std; 
#include <pthread.h>
#include <stdint.h>
#include "ThreadMutex.h"


namespace fengyoung
{


class FBuffer_DumpThreadParam
{
public: 
	FBuffer_DumpThreadParam(const char* sDumpFile, const uint32_t unBuffSize); 
	virtual ~FBuffer_DumpThreadParam(); 
	
public: 	
	uint32_t m_unLen;	// 数据长度 
	uint32_t m_unBuffSize;	// 缓存大小
	char* m_pdata; 	// 数据缓存指针
	string m_strDumpFile; // dump数据文件 

	bool m_bStopFlag;	// 线程终止信号
}; 


class FBuffer
{
public: 
	FBuffer(const char* sDumpFile, const uint32_t unBuffSize = _DEFAULT_BUFF_SIZE); 
	virtual ~FBuffer(); 

	void Push(const char* pData, const uint32_t unDataLen); 
	bool Dump(); 
	uint32_t DataLen(); 
	uint32_t BuffSize(); 

private: 
	static void* Thread_Dump(void* pParam);

private: 
	uint32_t m_unBuffSize;	// 缓存大小
	uint32_t m_unLen;		// 缓存数据长度 
	char* m_pBuff;		// 数据缓存
	string m_strDumpFile;	// dump数据文件

public: 
	FBuffer_DumpThreadParam* m_dumpThreadParam; 
	static const uint32_t _DEFAULT_BUFF_SIZE; 	// 默认的缓存大小
	static ThreadMutex mutex;	// 线程锁 
}; 

}

#endif /* _FENGYOUNG_API_F_BUFFER_H */  


