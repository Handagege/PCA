/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayFixer : arrayFixer.cpp
////
//// v1.0 - 2015.05.21 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "arrayFixer.h"

CarrayFixer::CarrayFixer()
{
	m_overBorderIndex = 3.0;
}

CarrayFixer::~CarrayFixer()
{
}

/////////////////////////////////////////////////////////////////////
//operator

//fix complete standard data
VVfContainer CarrayFixer::Fixer( VVfContainer& stdArray )
{
	VVfContainer fixResult = stdArray;
	for( uint32_t i=0; i<fixResult.size(); ++i )
	{
		FixOverBorder(fixResult[i]);
	}
	return fixResult;
}

void CarrayFixer::FixOverBorder( VfContainer& rowArray )
{
	int32_t len = rowArray.size();
	for( int32_t i=0; i<len; ++i )
	{
		if(CheckOverBorder(rowArray[i]))
			rowArray[i] = m_overBorderIndex;
	}
}	

bool CarrayFixer::CheckOverBorder( float& value )
{
	return float(fabs(double(value))) >= m_overBorderIndex;
}

//fix ! complete standard data
VVfContainer CarrayFixer::Fixer( VVfContainer& stdArray, MisContainer& dimTemplate )
{
	VVfContainer fixResult = stdArray;
	for( uint32_t i=0; i<fixResult.size(); ++i )
	{
		FixOverBorder(fixResult[i],dimTemplate);
	}
	return fixResult;
}

void CarrayFixer::FixOverBorder( VfContainer& rowArray, MisContainer& dimTemplate )
{
	int32_t len = rowArray.size();
	for( int32_t i=0; i<len; ++i )
	{
		if( dimTemplate[i] == "C" && CheckOverBorder(rowArray[i]))
			rowArray[i] = m_overBorderIndex;
	}
}	
