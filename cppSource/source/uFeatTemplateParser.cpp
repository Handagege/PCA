/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CuFeatTemplateParser : uFeatTemplateParser.cpp
////
//// v1.0 - 2015.05.20 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "uFeatTemplateParser.h"

CuFeatTemplateParser::CuFeatTemplateParser()
{
}


CuFeatTemplateParser::~CuFeatTemplateParser()
{
}

/////////////////////////////////////////////////////////////////////
//operator

//
void CuFeatTemplateParser::ParserFromFile( ifstream& fcin, VuContainer& uFeatTemplateData)
{
	Json::Reader reader;
	Json::Value root;
	reader.parse(fcin,root,false);
	Json::Value uFeatPrimJData = root["prim_feat_unit"];
	for( uint32_t i=0; i<uFeatPrimJData.size(); ++i )
	{
		uFeatTemplateNode tempNode;
		tempNode.id = uFeatPrimJData[i]["id"].asString();
		tempNode.name = uFeatPrimJData[i]["name"].asString();
		tempNode.active = uFeatPrimJData[i]["active"].asString();
		tempNode.type = uFeatPrimJData[i]["type"].asString();
		tempNode.defaultValue = uFeatPrimJData[i]["default"].asString();
		VsContainer rangeValue;
		Json::Value rangeJNode = uFeatPrimJData[i]["range"];
		for( uint32_t j=0; j<rangeJNode.size(); ++j )
			rangeValue.push_back(rangeJNode[j].asString());
		tempNode.range = rangeValue;
		uFeatTemplateData.push_back(tempNode);
	}
}
