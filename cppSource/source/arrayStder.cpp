/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayStder : arrayStder.cpp
////
//// v1.0 - 2015.05.20 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "arrayStder.h"

CarrayStder::CarrayStder()
{
}

CarrayStder::~CarrayStder()
{
}

/////////////////////////////////////////////////////////////////////
//operator

//
VVfContainer CarrayStder::Stder()
{
	VVfContainer stdArray;
	VViContainer dataByTrans = TransformData();
	cout << "complete transfor data" << endl;	
	TrainTemplate(dataByTrans);
	cout << "complete train data" << endl;
	return Stder(m_enumTemplate,m_contTemplate,dataByTrans);
}

VVfContainer CarrayStder::Stder( MiMiiContainer& enumTemplate, MistContainer& contTemplate, VViContainer& dataByTrans )
{
	m_enumTemplate = enumTemplate;
	m_contTemplate = contTemplate;
	int32_t row = dataByTrans.size();
	int32_t column;
	if(row != 0)
		column = dataByTrans[0].size();
	else
	{
		cout << "Empty Primary Data..." << endl;
		exit(0);
	}
	VVfContainer stdArray;
        clock_t beg = clock();
        clock_t end,cost;
	for( int32_t i=0; i<row; ++i )
	{
		if( m_dimTemplate[i] == "E" )
			stdArray.push_back(GetArrayByEnumTemplate(i,dataByTrans[i]));
		else if( m_dimTemplate[i] == "C" )
			stdArray.push_back(GetArrayByContTemplate(i,dataByTrans[i]));
		else
		{
			cout << i << " column miss template message ..." << endl;
			exit(0);
		}
		end = clock();
		cost = end - beg;
		beg = end;
		cout << i << "row cost : " << float(cost)/CLOCKS_PER_SEC << endl;
	}
	cout << "complete standarder data" << endl;
	cout << "Std array Sie is : " << stdArray.size() << endl;
	return TransformData(stdArray);
}

MiiContainer CarrayStder::CalEnumRel( ViContainer& dimData )
{
	MiiContainer enumRel;
	uint32_t n = 1;
	for( uint32_t i=0; i<dimData.size(); ++i )
	{
		if( enumRel.find(dimData[i]) == enumRel.end() )
		{
			enumRel[ dimData[i] ] = n;
			++n;
		}
	}
	return enumRel;
}

statIndexData CarrayStder::CalContStatIndex( ViContainer& dimData )
{
	statIndexData contStatIndex;
	uint32_t n = dimData.size();
	int32_t total = 0;
	for( uint32_t i=0; i<n; ++i )
	{
		total += dimData[i];
	}
	double mean = double(total)/double(n);
	contStatIndex.mean = float(mean);
	double dev = 0;
	for( uint32_t i=0; i<n; ++i )
	{
		dev += pow(double(dimData[i])-mean,2.0);
	}
	dev = dev/double(n-1);
	contStatIndex.stdev = float(sqrt(dev));

	return contStatIndex;
}

void CarrayStder::TrainTemplate( VViContainer& dataByTrans )
{
	for( uint32_t i=0; i<dataByTrans.size(); ++i )
	{
		if( m_dimTemplate[i] == "E" )
			m_enumTemplate[i] = CalEnumRel(dataByTrans[i]);
		else if( m_dimTemplate[i] == "C" )
			m_contTemplate[i] = CalContStatIndex(dataByTrans[i]);
		else
		{
			cout << i << " column miss template message ..." << endl;
			exit(0);
		}
	}
}

VViContainer CarrayStder::TransformData()
{
	uint32_t row = m_primData.size();
	uint32_t column;
	if(row != 0)
		column = m_primData[0].size();
	else
	{
		cout << "Empty Primary Data..." << endl;
		exit(0);
	}
	VViContainer dataByTrans;
	for( uint32_t i=0; i<column; ++i )
	{
		ViContainer tempColumnData(row);
		for( uint32_t j=0; j<row; ++j )
		{
			tempColumnData[j] = m_primData[j][i]; 
		}
		dataByTrans.push_back(tempColumnData);
	}
	return dataByTrans;
}

float CarrayStder::GetValueByEnumTemplate( int32_t ID, int32_t val )
{
	MiiContainer relationList = m_enumTemplate[ID];	
	int32_t enumValue = relationList[val];
        return float(enumValue);
	//int32_t len = relationList.size();
	//VfContainer result(len);
	//result[len-enumValue] = float(1);
}

float CarrayStder::GetValueByContTemplate( int32_t ID, int32_t val )
{
	statIndexData statIndex = m_contTemplate[ID];
	if( statIndex.stdev == float(0) )
		return float(0);
	else
		return (float(val)-statIndex.mean)/statIndex.stdev;
}

MiiContainer CarrayStder::GetEnumTemplateLenPerDim()
{
        MiiContainer sizeResult;
        MiMiiIter MiMii_it = m_enumTemplate.begin();
        while( MiMii_it != m_enumTemplate.end() )
        {
                sizeResult[MiMii_it->first] = MiMii_it->second.size();
                ++MiMii_it;
        }
        return sizeResult;
}

VfContainer CarrayStder::GetArrayByEnumTemplate( int32_t ID, ViContainer& array )
{
	MiiContainer relationList = m_enumTemplate[ID];	
	uint32_t len = array.size();
	VfContainer result(len);
	for( uint32_t i=0; i<len; ++i )
	{
		result[i] = float(relationList[array[i]]);
	}
	return result;
}

VfContainer CarrayStder::GetArrayByContTemplate( int32_t ID, ViContainer& array )
{
	statIndexData statIndex = m_contTemplate[ID];
	uint32_t len = array.size();
	VfContainer result(len);
	for( uint32_t i=0; i<len; ++i )
	{
		if( statIndex.stdev == float(0) )
			result[i] = float(0);
		else
			result[i] = (float(array[i])-statIndex.mean)/statIndex.stdev;
	}
	return result;
}

VVfContainer CarrayStder::TransformData( VVfContainer& stdData )
{
	uint32_t row = stdData.size();
	uint32_t column;
	if(row != 0)
		column = stdData[0].size();
	else
	{
		cout << "Empty Primary Data..." << endl;
		exit(0);
	}
	VVfContainer dataByTrans(column);
	for( uint32_t i=0; i<column; ++i )
	{
		VfContainer tempColumnData(row);
		for( uint32_t j=0; j<row; ++j )
		{
			tempColumnData[j] = stdData[j][i]; 
		}
		dataByTrans[i] = tempColumnData;
	}
	return dataByTrans;
}
