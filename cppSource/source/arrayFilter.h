/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayFilter : arrayFilter.h
////
//// v1.0 - 2015.05.21 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "defType.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>

#ifndef _ARRAYFILTER_H 
#define _ARRAYFILTER_H

using namespace std;

class CarrayFilter
{
public:
	CarrayFilter();
	virtual ~CarrayFilter();

	virtual VVfContainer Filter( VVfContainer& stdArray, MisContainer& dimTemplate );
	virtual VVfContainer Filter( VVfContainer& stdArray );

	void SetOverBorderIndex( float value ){ m_overBorderIndex = value; }
private:
	SiContainer GetArrayIdByFilter( VVfContainer& stdArray, MisContainer& dimTemplate );
	SiContainer GetArrayIdByFilter( VVfContainer& stdArray );
	VVfContainer DeleteArray( VVfContainer& stdArray, SiContainer& filterResult );
	bool CheckOverBorder( VfContainer& rowArray, MisContainer& dimTemplate );
	bool CheckOverBorder( VfContainer& rowArray );
	
	float m_overBorderIndex;
};

#endif
