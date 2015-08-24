/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayFixer : arrayFixer.h
////
//// v1.0 - 2015.05.22 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "defType.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>

#ifndef _ARRAYFIXER_H 
#define _ARRAYFIXER_H

using namespace std;

class CarrayFixer
{
public:
	CarrayFixer();
	virtual ~CarrayFixer();

	virtual VVfContainer Fixer( VVfContainer& stdArray );
	virtual VVfContainer Fixer( VVfContainer& stdArray, MisContainer& dimTemplate );
private:
	void FixOverBorder( VfContainer& rowArray );	
	void FixOverBorder( VfContainer& rowArray, MisContainer& dimTemplate );	
	bool CheckOverBorder( float& value );
	
	float m_overBorderIndex;
};

#endif
