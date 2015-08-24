/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayFilter : arrayFilter.cpp
////
//// v1.0 - 2015.05.21 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "arrayFilter.h"

CarrayFilter::CarrayFilter()
{
	m_overBorderIndex = 3.0;
}

CarrayFilter::~CarrayFilter()
{
}

/////////////////////////////////////////////////////////////////////
//operator

//deal complete standard data
VVfContainer CarrayFilter::Filter( VVfContainer& stdArray )
{
	SiContainer filterResult = GetArrayIdByFilter(stdArray);
	return DeleteArray(stdArray,filterResult);
}

SiContainer CarrayFilter::GetArrayIdByFilter( VVfContainer& stdArray )
{
	SiContainer resultByFilter;
	int32_t row = stdArray.size();
	for( int32_t i=0; i<row; ++i )
	{
		VfContainer rowArray = stdArray[i];
		bool OverBorderFlag = CheckOverBorder(rowArray);
		if(OverBorderFlag)
		{
			//for( uint32_t j=0; j<rowArray.size(); ++j )
			//	cout << rowArray[j] << " ";
			//cout << endl;
			resultByFilter.insert(i);
		}
	}
	return resultByFilter;
}

//deal ! complete standard data
VVfContainer CarrayFilter::Filter( VVfContainer& stdArray, MisContainer& dimTemplate )
{
	SiContainer filterResult = GetArrayIdByFilter(stdArray,dimTemplate);
	return DeleteArray(stdArray,filterResult);
}

SiContainer CarrayFilter::GetArrayIdByFilter( VVfContainer& stdArray,MisContainer& dimTemplate )
{
	SiContainer resultByFilter;
	int32_t row = stdArray.size();
	for( int32_t i=0; i<row; ++i )
	{
		VfContainer rowArray = stdArray[i];
		bool OverBorderFlag = CheckOverBorder(rowArray,dimTemplate);
		if(OverBorderFlag)
		{
			//for( uint32_t j=0; j<rowArray.size(); ++j )
			//	cout << rowArray[j] << " ";
			//cout << endl;
			resultByFilter.insert(i);
		}
	}
	return resultByFilter;
}
 
bool CarrayFilter::CheckOverBorder( VfContainer& rowArray, MisContainer& dimTemplate )
{
	bool flag = false;
	int32_t len = rowArray.size();
	for( int32_t i=0; i<len; ++i )
	{
		if( dimTemplate[i] == "C" && float(fabs(double(rowArray[i]))) >= m_overBorderIndex )
			flag = true;
	}
	return flag;
}
///////////////

VVfContainer CarrayFilter::DeleteArray( VVfContainer& stdArray, SiContainer& filterResult )
{
	VVfContainer newArray;
	int32_t len = stdArray.size();
	for( int32_t i=0; i<len; ++i )
	{
		if( filterResult.find(i) == filterResult.end() )
			newArray.push_back(stdArray[i]);
	}
	return newArray;
}

bool CarrayFilter::CheckOverBorder( VfContainer& rowArray )
{
	bool flag = false;
	int32_t len = rowArray.size();
	for( int32_t i=0; i<len; ++i )
	{
		if( float(fabs(double(rowArray[i]))) >= m_overBorderIndex )
			flag = true;
	}
	return flag;
}
