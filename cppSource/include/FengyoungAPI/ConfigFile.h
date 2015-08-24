/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ConfigFile.h : ConfigFile
//
// v1.0 - 2011.04.11 by (fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_CONGIG_FILE_H 
#define _FENGYOUNG_API_CONGIG_FILE_H 

#include <string> 
#include <map> 
#include <vector> 
#include <fstream> 
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// ConfigFile 
//  
class ConfigFile 
{ 
public: 
	//  &  
	ConfigFile();  
	virtual ~ConfigFile();  

	//  
	bool ReadFromConfigFile(const char* sConfigFile); 

	// 
	int32_t ValueCount(const char* sKey); 

	//  	
	string GetValueAsString(const char* sKey, const uint32_t unIdx = 0, const char* sDefault = NULL); 
	int32_t GetValueAsInt(const char* sKey, const uint32_t unIdx = 0, const int32_t nDefault = 0); 
	uint32_t GetValueAsUint(const char* sKey, const uint32_t unIdx = 0, const uint32_t nDefault = 0); 
	double GetValueAsFloat(const char* sKey, const uint32_t unIdx = 0, const double dDefault = 0.0); 
	bool GetValueAsBool(const char* sKey, const uint32_t unIdx = 0, const bool bDefault = false); 

private: 
	map<string,vector<string> > m_mapKeyToValues;	// Key->Values  
}; 

}

#endif /* _FENGYOUNG_API_CONGIG_FILE_H */  


