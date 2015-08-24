/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayStder : arrayStder.h
////
//// v1.0 - 2015.05.20 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "defType.h"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>
#include <time.h>

#ifndef _ARRAYSTDER_H 
#define _ARRAYSTDER_H

using namespace std;

typedef struct _statIndexData{
	float mean;
	float stdev;	
}statIndexData;

typedef map<int32_t,statIndexData> MistContainer;
typedef map<int32_t,statIndexData>::iterator MisttIter;

class CarrayStder
{
public:
	CarrayStder();
	CarrayStder( VViContainer& primData, MisContainer& dimTemplate ):
		m_primData(primData),m_dimTemplate(dimTemplate){}
	virtual ~CarrayStder();
	
	virtual void Init( VViContainer& primData, MisContainer& dimTemplate ){
		m_primData = primData;
		m_dimTemplate = dimTemplate;
	}
	virtual VVfContainer Stder();
	virtual VVfContainer Stder( MiMiiContainer& enumTemplate, MistContainer& contTemplate, VViContainer& dataByTrans );

	MiMiiContainer GetEnumTemplate(){ return m_enumTemplate; }
	MistContainer GetContTemplate(){ return m_contTemplate; }
        MiiContainer GetEnumTemplateLenPerDim();
private:
	MiiContainer CalEnumRel( ViContainer& dimData );		//calculate 'E' dim n:n' relationship
	statIndexData CalContStatIndex( ViContainer& dimData );		//calculate 'C' dim stat index
	void TrainTemplate( VViContainer& dataByTrans );		//train enum and continuous type template
	VViContainer TransformData();					//matrix transform
	VVfContainer TransformData( VVfContainer& stdData );
	float GetValueByEnumTemplate( int32_t ID, int32_t val );
	float GetValueByContTemplate( int32_t ID, int32_t val );
	VfContainer GetArrayByEnumTemplate( int32_t ID, ViContainer& array );
	VfContainer GetArrayByContTemplate( int32_t ID, ViContainer& array );

	VViContainer m_primData;
	MisContainer m_dimTemplate;		//mark per dim by 'E'or'C' {'E':enum,'C':continuous}
	MiMiiContainer m_enumTemplate;		//mark per 'E' dim by n:n'
	MistContainer m_contTemplate;		//mark per 'C' dim by mean and stdev
};

#endif /* _ARRAYSTDER_H */
