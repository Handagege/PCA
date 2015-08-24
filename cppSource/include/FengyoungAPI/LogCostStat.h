/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// LogCostStat.h : 日志中的时间消耗统计类LogCostStat的声明
//
// v1.0 - 2013.08.18 by (fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_LOG_COST_STAT_H 
#define _FENGYOUNG_API_LOG_COST_STAT_H


#include <string>
#include <vector>
#include <map>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

class NumNode 
{
public: 
	NumNode(const float fValue = 0.0); 
	virtual ~NumNode(); 

	bool FromString(const char* sStr, const int32_t nLen); 
	string ToString(); 

	void AddWith(NumNode* pNode); 
	void MultiWith(const float a); 

	void CurAsSubSum(); 

private: 
	void ParseVector(vector<string>& vtr, int32_t& offset); 
	void ParseString(vector<string>& vtr, const char* sStr, const int32_t nLen); 

public: 
	float m_fValue; 				// 当前node的值
	vector<NumNode*> m_vtrSubNode; 	// 子节点
}; 


// 类名：LogCostInfo
// 说明：日志耗时信息
class LogCostInfo
{
public:
	// 构造函数 & 析构函数
	LogCostInfo(); 
	virtual ~LogCostInfo(); 

	// 解析日志记录
	bool ParseFromLogRecord(const char* sLogRecord); 
	// 获取时间戳
	uint32_t GetTimestamp();
	// 获取时间戳的小数位
	string GetLessSec(); 
	// 获取日志级别
	string GetLogLevel(); 
	// 获取处理类型
	string GetProcType(); 
	// 获取耗时
	NumNode* GetCost(); 

private: 
	// 解析日志级别
	bool ParseLogLev(const char* sLogRecord); 
	// 解析日志时间戳
	bool ParseTimestamp(const char* sLogRecord); 
	// 解析处理类型
	bool ParseProcType(const char* sLogRecord); 
	// 解析耗时
	bool ParseCost(const char* sLogRecord); 

private: 
	uint32_t m_unTimestamp; 	// 时间戳
	string m_strLessSec; 	// 时间的小数部分
	string m_strLogLevel;	// 日志级别
	string m_strProcType;	// 请求类型
	NumNode* m_pCost; 		// 耗时
};


// 类名：GeneralCostStat
// 说明：通用耗时统计
class GeneralCostStat
{
public: 
	// 构造函数 & 析构函数
	GeneralCostStat(const uint32_t unTimeoutMSec, const float fToleranceRate = 0.9999); 
	virtual ~GeneralCostStat(); 

	// 执行统计
	void DoStat(vector<LogCostInfo*>& vtrSortedInfo); 

	// 打印当前信息
	void Print(ostream& os); 

private: 	
	static bool CmpCost_Less(pair<pair<uint32_t,string>, NumNode*> a, pair<pair<uint32_t,string>, NumNode*> b);
	static bool CmpCost_Great(pair<pair<uint32_t,string>, NumNode*> a, pair<pair<uint32_t,string>, NumNode*> b); 

	// 计算超时率，并以字符串返回
	string TimeoutRate();
	// 获取超时容忍度
	string ToleranceRate(); 
	// 获取分时段统计
	string CostSegRate(); 
	// 时间戳转换成字符串
	string TimestampToStr(const uint32_t unTimeStamp); 

	// 统计最大&最小耗时
	void StatMaxMinCost(vector<LogCostInfo*>& vtrSortedInfo); 
	// 统计"超时并超过容忍度的耗时记录" & "未超时的最大耗时记录"
	void StatNoToleranceNoOverTime(vector<LogCostInfo*>& vtrSortedInfo, 
			const uint32_t unToleranceCnt); 

	// 计算qps
	string CalculateQPS();

public: 
	uint32_t m_unTimeoutMSec;		// 超时时间(ms)
	float m_fToleranceRate;		// 超时容忍度
	uint32_t m_unToleranceCnt;		// 超时容忍条数

	uint32_t m_unRecordCnt;			// 记录条数	
	uint32_t m_unTimeoutRecordCnt;	// 超时记录条数
	uint32_t m_unCostSegCnt[7]; 	// 分时段统计 0~50ms, 50~100ms, 100~200ms, 200~300ms, 300~500ms, 500~1000ms, >1000ms

	uint32_t m_unMinTimestamp; 		// 最小时间戳
	uint32_t m_unMaxTimestamp;		// 最大时间戳 

	NumNode* m_pAvgCost;			// 平均耗时统计
	vector<pair<pair<uint32_t,string>, NumNode*> > m_vtrMaxCostRecords; 	// 最大耗时记录
	vector<pair<pair<uint32_t,string>, NumNode*> > m_vtrMinCostRecords; 	// 最小耗时记录
	vector<pair<pair<uint32_t,string>, NumNode*> > m_vtrMaxCostRecords_NoTolerance; 	// 超时并超过容忍度的耗时记录
	vector<pair<pair<uint32_t,string>, NumNode*> > m_vtrMaxCostRecords_NoOverTime; 	// 未超时的最大耗时记录

	static const uint32_t _CNT_LIMITTED; 
}; 


// 类名：LogCostStat
// 说明：日志耗时信息管理器
class LogCostStat
{
public:
	// 构造函数 & 析构函数
	LogCostStat(const char* sLevels = "iwdte"); 
	virtual ~LogCostStat(); 

	// 清空当前管理器
	void Clear(); 

	// 解析日志文件
	bool ParseLogFile(const char* sLogFile); 

	// 获取通用耗时统计
	void GetGeneralCostStat(map<string, GeneralCostStat*>& mapGeneralCostStat, 
			const uint32_t unTimeoutMSec, const float fToleranceRate, 
			const uint32_t unStartTimestamp = 0, 
			const uint32_t unEndTimestamp = 0xffffffff); 

private: 
	static bool CmpCost_Less(LogCostInfo* a, LogCostInfo* b); 

private:
	uint32_t m_unLevBitmap; 	// 日志级别bitmap
	map<string, vector<LogCostInfo*> > m_mapLogCostInfo; // "处理类型->耗时信息向量"映射表
}; 

}


#endif /* _FENGYOUNG_API_LOG_COST_STAT_H */

