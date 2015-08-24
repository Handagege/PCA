/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Timer.h : 计时器类Timer的声明
//
// 版本：v1.0 - 2011.04.11 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_TIMER_H 
#define _FENGYOUNG_API_TIMER_H 

#include <string>
#include <vector>
using namespace std;
#include <stdint.h>
#include <sys/time.h>

namespace fengyoung
{

// 类名：Timer  
// 说明：计时器
class Timer
{
public:
	// 构造函数 & 析构函数
	Timer();
	Timer(const Timer& timer);
	virtual ~Timer();

	// 重载赋值操作符
	Timer& operator = (const Timer& timer);
	
	// 清空当前计时器
	void Clear();

	// 开始计时
	void Start();
	// 停止计时
	void Stop();
	// 获取时间段数目
	uint32_t SegCount();

	// 获取最后一次计时
	int32_t GetLast_asUSec();
	float GetLast_asMSec();
	float GetLast_asSec();
	float GetLast_asMinute();
	float GetLast_asHour();

	// 获取一次计时
	pair<uint32_t,uint32_t> Get(const uint32_t unSeg); 
	int32_t Get_asUSec(const uint32_t unSeg);
	float Get_asMSec(const uint32_t unSeg);
	float Get_asSec(const uint32_t unSeg);
	float Get_asMinute(const uint32_t unSeg);
	float Get_asHour(const uint32_t unSeg);

	// 获取总计时
	int32_t GetTotal_asUSec(); 
	float GetTotal_asMSec(); 
	float GetTotal_asSec(); 
	float GetTotal_asMinute(); 
	float GetTotal_asHour(); 

	string ToString_asMS(); 
	bool FromString_asMS(const char* sStr); 

	void CombineWith(Timer& timer); 
	

public: 
	timeval m_laststart;    // 最后一次起始时间
	bool m_bPingPang;       // 计时开关
	vector<pair<uint32_t, uint32_t> > m_vtrSeg; 	// 计时时间段<秒，微秒>
};

}

#endif /* _FENGYOUNG_API_TIMER_H */ 


