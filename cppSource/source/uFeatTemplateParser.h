/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CuFeatTemplateParser : uFeatTemplateParser.h
////
//// v1.0 - 2015.05.20 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "defType.h"
#include <stdio.h>
#include <map>
#include <json/json.h>
#include <fstream>

#ifndef _UFEATTEMPLATEPARSER_H 
#define _UFEATTEMPLATEPARSER_H

using namespace std;

typedef struct _uFeatTemplateNode{
	string id;
	string name;
	string active;
	string type;
	VsContainer range;
	string defaultValue;
}uFeatTemplateNode;

typedef vector<uFeatTemplateNode> VuContainer;
typedef vector<uFeatTemplateNode>::iterator VuIter;

class CuFeatTemplateParser
{
public:
	CuFeatTemplateParser();
	virtual ~CuFeatTemplateParser();
	
	virtual void ParserFromFile( ifstream& fcin, VuContainer& uFeatTemplateData );
private:

};

#endif /* _UFEATTEMPLATEPARSER_H */ 
