/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BinaryFile.h : BinaryFile
//
// v1.0 - 2011.04.11 by (fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BINARY_FILE_H 
#define _FENGYOUNG_API_BINARY_FILE_H 

#include <stdio.h>
#include <stdint.h>

#define _BINARY_FILE_DATABUFF_SIZE	(1024*1024*128)	// 
// 
#define _BINARY_FILE_ERROR_HANDLE_NULL	-1	// ()  


namespace fengyoung
{


// 
enum BFHandleType
{
	_BINARY_FILE_READONLY,	// 	
	_BINARY_FILE_WRITE,	// 
	_BINARY_FILE_APPEND,	// 
};


// BinaryFile
// 
class BinaryFile
{
public:
	//  & 
	BinaryFile();
	virtual ~BinaryFile();

	// Open
	// 
	// 
	//	[IN] sFile - 
	//	[IN] eHandleType - 	
	// truefalse
	bool Open(const char* sFile, BFHandleType eHandleType); 

	// Close
	// 
	void Close();

	// GetData
	// ()
	// 
	//	[IN] unOffset - 
	// NULL
	char* GetData(const uint64_t unOffset = 0) const;

	// GetDataLen
	// ()
	// 
	//	[IN] unOffset - 
	// 
	uint64_t GetDataLen(const uint64_t unOffset = 0) const;

	// WriteData
	// ()
	// 
	//	[IN] pData - 	
	//	[IN] unLen - 
	// truefasle
	bool WriteData(const void* pData, const uint64_t unLen);

	// IsOpen
	// 
	// truefalse
	bool IsOpen();
	
	// FileLen
	// 
	// 
	//	[IN] sFile - 	
	// -1
	static int64_t FileLen(const char* sFile);	

private:
	// OpenForReadOnly
	// 
	// 
	//	[IN] sFile - 	
	// truefalse
	bool OpenForReadOnly(const char* sFile);

	// OpenForWrite
	// 
	// 
	//	[IN] sFile - 	
	// truefalse
	bool OpenForWrite(const char* sFile);

	// OpenForAppend
	// 
	// 
	//	[IN] sFile - 	
	// truefalse
	bool OpenForAppend(const char* sFile);

	// WriteBuffDataToFile
	// () 
	void WriteBuffDataToFile();

private:
	BFHandleType m_eHandleType;	// 
	FILE* m_fp;	// 
	char* m_pDataBuff;	// 
	uint64_t m_unDataLen;	// 
};

}


#endif /* _FENGYOUNG_API_BINARY_FILE_H */ 

