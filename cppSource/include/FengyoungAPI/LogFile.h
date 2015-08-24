/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// LogFile.h : 日志文件类LogFile的声明
//
// v1.0 - 2013.07.18 by (fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_LOG_FILE_H 
#define _FENGYOUNG_API_LOG_FILE_H

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>

namespace fengyoung 
{

const int32_t LOG_LEVEL_ERROR_FY = 0;
const int32_t LOG_LEVEL_WARN_FY = 1;
const int32_t LOG_LEVEL_INFO_FY = 2;
const int32_t LOG_LEVEL_TRACE_FY = 3;
const int32_t LOG_LEVEL_DEBUG_FY = 4;


const char LOG_LEVEL_STR_FY[][8] = 
{
	"ERROR",
	"WARN",
	"INFO",
	"TRACE",
	"DEBUG"
};

typedef struct _log_file_fy_t 
{
	int32_t fd;
	time_t sw_time;
} LogFileT;


typedef struct _log_data_fy_t 
{
	int32_t is_open;
	LogFileT file[2];
	int32_t idx;
	int32_t created_key;
	pthread_key_t log_key;
	size_t buf_size;
	char path[128];
	int32_t filter_level;
	int32_t flush_level;
	int64_t log_id;
	pthread_mutex_t mutex;
} LogDataT; 


typedef struct _log_thead_data_fy_t 
{
	int64_t log_id;
	size_t len;
	size_t size;
	char buf[0];
} LogThreadDataT;


class LogFile
{
private:
	LogFile();
	virtual ~LogFile();
public:
	static int32_t OpenLog(const char *path, size_t buf_size, const char *write_level, const char *flush_level);
	static int32_t OpenThreadLog();
	static void SetLogID(int64_t id);
	static int32_t Log(int32_t level, int32_t flush, const char *fmt, ...);
	static void CloseLog();
private: 
	static int32_t LogWrite(const char *buf, size_t len);
	static int32_t LogWrite(int32_t level, const char *fmt, va_list ap);
	static void CloseThreadLog(void *arg); 
	static int32_t Level_Str2Int(const char *str);
private:
	static LogDataT log_data;
};


}

/*
#define LOG_ERROR(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_ERROR_FY, 0, "[%s:%u] " fmt "\n", __FILE__, __LINE__, ##arg); \
	} while(0)

#define LOG_DEBUG(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_DEBUG_FY, 0, "[%s:%u] " fmt "\n", __FILE__, __LINE__, ##arg); \
	} while(0)

#define LOG_WARN(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_WARN_FY, 0, "[%s:%u] " fmt "\n", __FILE__, __LINE__, ##arg); \
	} while(0) 

#define LOG_INFO(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_INFO_FY, 0, "[%s:%u] " fmt "\n", __FILE__, __LINE__, ##arg); \
	} while(0) 

#define LOG_TRACE(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_TRACE_FY, 0, "[%s:%u] " fmt "\n", __FILE__, __LINE__, ##arg); \
	} while(0) 
*/

#define LOG_ERROR_FY(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_ERROR_FY, 0, fmt "\n", ##arg); \
	} while(0)

#define LOG_DEBUG_FY(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_DEBUG_FY, 0, fmt "\n", ##arg); \
	} while(0)

#define LOG_WARN_FY(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_WARN_FY, 0, fmt "\n", ##arg); \
	} while(0) 

#define LOG_INFO_FY(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_INFO_FY, 0, fmt "\n", ##arg); \
	} while(0) 

#define LOG_TRACE_FY(fmt, arg...) \
	do { \
		fengyoung::LogFile::Log(fengyoung::LOG_LEVEL_TRACE_FY, 0, fmt "\n", ##arg); \
	} while(0) 



#endif /* _FENGYOUNG_API_LOG_FILE_H */


