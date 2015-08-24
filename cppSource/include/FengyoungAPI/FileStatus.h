/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// FileStatus.h : FileStatus 
//
// v1.0 - 2011.04.11 by (fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_FILE_STATUS_H 
#define _FENGYOUNG_API_FILE_STATUS_H 

#include <stdio.h>
#include <stdint.h>

#define _FILE_STATUS_LINE_MAX_SIZE	(1024*1024*64)

namespace fengyoung
{

// FileStatus
//  
class FileStatus
{ 
private: 
	//  &  
	FileStatus();  
	virtual ~FileStatus();  

public: 
	// 
	static int64_t FileSize(const char* sFile); 

	// 
	static int64_t LineCount(const char* sFile, const bool bIgnoreNullLine = true); 
}; 

}

#endif /* _FENGYOUNG_API_FILE_STATUS_H */  


