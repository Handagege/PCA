/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DirInfo.h : 路径信息DirInfo的声明
//
// v1.0 - 2015.01.14 by (fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_DIR_INFO_H 
#define _FENGYOUNG_API_DIR_INFO_H 

#include <string>
#include <vector>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

class DirInfo
{
public: 
	DirInfo(); 
	virtual ~DirInfo(); 

	bool ReadPath(const char* sPath);

	uint32_t SubPathCnt(); 
	uint32_t HiddenSubPathCnt(); 
	uint32_t FileCnt(); 
	uint32_t HiddenFileCnt(); 

	string SubPath(const uint32_t idx); 
	string HiddenSubPath(const uint32_t idx); 
	string File(const uint32_t idx); 
	string HiddenFile(const uint32_t idx); 

private: 
	vector<string> m_vtrSubPath;			// 子路径
	vector<string> m_vtrHiddenSubPath;		// 隐藏子路径
	vector<string> m_vtrFile;				// 文件 
	vector<string> m_vtrHiddenFile;			// 隐藏文件
};

}

#endif /* _FENGYOUNG_API_DIR_INFO_H */  


