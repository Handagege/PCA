#include "defType.h"
#include "uFeatTemplateParser.h"
#include "arrayStder.h"
#include "arrayFixer.h"
#include "arrayFilter.h"
#include "arrayBalancer.h"
#include <string.h>
#include <time.h>
#include <FengyoungAPI/fengyoung_api.h>
#include <algorithm>
#include <iterator>
using namespace fengyoung;

MisContainer GetDimTemplate( ifstream& fcin );
VViContainer GetPrimData( ifstream& fcin );
//put off the enum type data's printed time
void PrintStdArray( ofstream& fout, VVfContainer& stdArray, MisContainer dimTemplate, MiiContainer enumTemplateLenPerDim );

int main()
{
	clock_t beg = clock();
	clock_t end;
	clock_t cost;
	//parse conf file
	ConfigFile cf;
        bool success = cf.ReadFromConfigFile("../conf/getStdArray.ini");
	string jsonTemplatePath;
	string NoClickPath;
	string YesClickNoRelPath;
	string YesClickYesRelPath;
	string resultPath;
	string handleExceptionMethod;
	float balancerRatio;
        if(success)
        {
		jsonTemplatePath = cf.GetValueAsString("JSON_TEMPLATE_PATH");
		NoClickPath = cf.GetValueAsString("N_CLICK_PATH");
		YesClickNoRelPath = cf.GetValueAsString("Y_CLICK_N_REL_PATH");
		YesClickYesRelPath = cf.GetValueAsString("Y_CLICK_Y_REL_PATH");
		resultPath = cf.GetValueAsString("STD_ARRAY_PATH");
		handleExceptionMethod = cf.GetValueAsString("H_EXCEPTION_M");
		balancerRatio = cf.GetValueAsFloat("BALANCER_RATIO");
        }
        else
                printf("config read exception!");

	//get dimTemplate
	ifstream fcin(jsonTemplatePath.c_str());
	MisContainer dimTemplate = GetDimTemplate(fcin);
	fcin.close();
	fcin.clear();
	end = clock();
	cost = end - beg;
	cout << "[01] complete json parser ... cost " << float(cost)/CLOCKS_PER_SEC << endl;
	beg = end;
	//get primary array
	fcin.open(NoClickPath.c_str());
	VViContainer NoClickData = GetPrimData(fcin);
	uint32_t NoclickSize = NoClickData.size();
	cout << "Noclick Size is : " << NoclickSize << endl;
	fcin.close();
	fcin.clear();
	fcin.open(YesClickNoRelPath.c_str());
	VViContainer YesClickNoRelData = GetPrimData(fcin);
	uint32_t YesClickNoRelSize = YesClickNoRelData.size();
	cout << "YesClickNoRel Size is : " << YesClickNoRelSize << endl;
	fcin.close();
	fcin.clear();
	fcin.open(YesClickYesRelPath.c_str());
	VViContainer YesClickYesRelData = GetPrimData(fcin);
	uint32_t YesClickYesRelSize = YesClickYesRelData.size();
	cout << "YesClickYesRel Size is : " << YesClickYesRelSize << endl;
	fcin.close();
	fcin.clear();
	VViContainer primData(NoClickData.begin(),NoClickData.end());
	primData.insert(primData.end(),YesClickNoRelData.begin(),YesClickNoRelData.end());
	primData.insert(primData.end(),YesClickYesRelData.begin(),YesClickYesRelData.end());
	end  = clock();
	cost = end -beg;
	cout << "[02] complete parser primary data ... cost " << float(cost)/CLOCKS_PER_SEC << endl;
	beg = end;
	//get standard array
	CarrayStder arrayStder;
	arrayStder.Init(primData,dimTemplate);
	VVfContainer stdArray = arrayStder.Stder();
        MiiContainer enumTemplateLenPerDim = arrayStder.GetEnumTemplateLenPerDim(); 
	primData.clear();
	end = clock();
	cost = end -beg;
	cout << "[03] complete array standard ... cost " << float(cost)/CLOCKS_PER_SEC << endl;
	beg = end;
	cost = end - beg;
	VVfContainer std_NoClickData(stdArray.begin(),stdArray.begin()+NoclickSize);
	VVfContainer std_YesClickNoRelData(stdArray.begin()+NoclickSize,stdArray.begin()+NoclickSize+YesClickNoRelSize);
	VVfContainer std_YesClickYesRelData(stdArray.begin()+NoclickSize+YesClickNoRelSize,stdArray.end());
	cout << "Std array Sie is : " << stdArray.size() << endl;
        stdArray.clear();
	cout << "after stdandard :" << endl;
	cout << "Noclick Size is : " << std_NoClickData.size() << endl;
	cout << "YesClickNoRel Size is : " << std_YesClickNoRelData.size() << endl;
	cout << "YesClickYesRel Size is : " << std_YesClickYesRelData.size() << endl;

	VVfContainer fstd_NoClickData;
	VVfContainer fstd_YesClickNoRelData;
	VVfContainer fstd_YesClickYesRelData;
	if( handleExceptionMethod == "Filter" )
	{
		//filter standard array	
		CarrayFilter arrayFilter;
		fstd_NoClickData =  arrayFilter.Filter(std_NoClickData,dimTemplate);
		fstd_YesClickNoRelData = arrayFilter.Filter(std_YesClickNoRelData,dimTemplate);
		fstd_YesClickYesRelData = arrayFilter.Filter(std_YesClickYesRelData,dimTemplate);
		end = clock();
		cost = end - beg;
		cout << "[04] after filter ... cost " << float(cost)/CLOCKS_PER_SEC << endl;
		beg = end;
		cout << "Noclick Size is : " << fstd_NoClickData.size() << endl;
		cout << "YesClickNoRel Size is : " << fstd_YesClickNoRelData.size() << endl;
		cout << "YesClickYesRel Size is : " << fstd_YesClickYesRelData.size() << endl;
	}
	else if( handleExceptionMethod == "Fix" )
	{
		//fix standard array
		CarrayFixer arrayFixer;
		fstd_NoClickData =  arrayFixer.Fixer(std_NoClickData,dimTemplate);
		fstd_YesClickNoRelData = arrayFixer.Fixer(std_YesClickNoRelData,dimTemplate);
		fstd_YesClickYesRelData = arrayFixer.Fixer(std_YesClickYesRelData,dimTemplate);
		end = clock();
		cost = end - beg;
		cout << "[04] after fixer ... cost " << float(cost)/CLOCKS_PER_SEC << endl;
		beg = end;
		cout << "Noclick Size is : " << fstd_NoClickData.size() << endl;
		cout << "YesClickNoRel Size is : " << fstd_YesClickNoRelData.size() << endl;
		cout << "YesClickYesRel Size is : " << fstd_YesClickYesRelData.size() << endl;
	}

	//get balance array
	//ctr data
	CarrayBalancer arrayBalancer;
	VVfContainer ctr_bfstd_NoClickData = fstd_NoClickData;
	VVfContainer ctr_bfstd_YesClickData = fstd_YesClickNoRelData;
	ctr_bfstd_YesClickData.insert(ctr_bfstd_YesClickData.end(),
		fstd_YesClickYesRelData.begin(),fstd_YesClickYesRelData.end());
	arrayBalancer.Balancer(ctr_bfstd_YesClickData,ctr_bfstd_NoClickData,balancerRatio);
	end = clock();
	cost = end -beg;
	beg = end;
	uint32_t ctrNegArraySize = ctr_bfstd_NoClickData.size();
	uint32_t ctrPosArraySize = ctr_bfstd_YesClickData.size();
	cout << "Noclick Size is : " << ctrNegArraySize << endl;
	cout << "YesClick Size is : " << ctrPosArraySize << endl;
	//rpm data
	VVfContainer rpm_bfstd_NoRelData = fstd_NoClickData;
	VVfContainer rpm_bfstd_YesRelData = fstd_YesClickYesRelData;
	rpm_bfstd_NoRelData.insert(rpm_bfstd_NoRelData.end(),
		fstd_YesClickNoRelData.begin(),fstd_YesClickNoRelData.end());
	arrayBalancer.Balancer(rpm_bfstd_YesRelData,rpm_bfstd_NoRelData);
	uint32_t rpmNegArraySize = rpm_bfstd_NoRelData.size();
	uint32_t rpmPosArraySize = rpm_bfstd_YesRelData.size();
	cout << "NoRel Size is : " << rpmNegArraySize << endl;
	cout << "YesRel Size is : " << rpmPosArraySize << endl;
	cout << endl;
	cout << "[05] after balancer ... cost :" << float(cost)/CLOCKS_PER_SEC << endl;

	//print table and result
	string ctrArrayPath = cf.GetValueAsString("CTR_TABLE_TARGET_PATHI");
	string ctrResultPath = cf.GetValueAsString("CTR_RESULT_TARGET_PATH");
	string rpmArrayPath = cf.GetValueAsString("RPM_TABLE_TARGET_PATH");
	string rpmResultPath = cf.GetValueAsString("RPM_RESULT_TARGET_PATH");
	ofstream fout(ctrArrayPath.c_str(),ofstream::out);
	VVfContainer ctrArrayTable = ctr_bfstd_YesClickData;
	ctrArrayTable.insert(ctrArrayTable.begin(),
		ctr_bfstd_NoClickData.begin(),ctr_bfstd_NoClickData.end());
	PrintStdArray(fout,ctrArrayTable,dimTemplate,enumTemplateLenPerDim);
	fout.close();
	fout.clear();
	cout << "1" << endl;
	fout.open(ctrResultPath.c_str(),ofstream::out);
	for( uint32_t i=0; i<ctrPosArraySize; ++i )
		fout << 1 << endl;
	for( uint32_t i=0; i<ctrNegArraySize; ++i )
		fout << 0 << endl;
	fout.close();
	fout.clear();
	cout << "2" << endl;
	fout.open(rpmArrayPath.c_str(),ofstream::out);
	VVfContainer rpmArrayTable = rpm_bfstd_YesRelData;
	rpmArrayTable.insert(rpmArrayTable.begin(),
		rpm_bfstd_NoRelData.begin(),rpm_bfstd_NoRelData.end());
	cout << "2.1" << endl;
	PrintStdArray(fout,rpmArrayTable,dimTemplate,enumTemplateLenPerDim);
	fout.close();
	fout.clear();
	cout << "3" << endl;
	fout.open(rpmResultPath.c_str(),ofstream::out);
	for( uint32_t i=0; i<rpmPosArraySize; ++i )
		fout << 1 << endl;
	for( uint32_t i=0; i<rpmNegArraySize; ++i )
		fout << 0 << endl;
	fout.close();
	fout.clear();
	cout << "4" << endl;
	end = clock();
	cout << "complete array print to ../result/ cost" << float(cost)/CLOCKS_PER_SEC << endl;

	return 1;
}

MisContainer GetDimTemplate( ifstream& fcin )
{
	CuFeatTemplateParser FTParser;
	VuContainer uFeatTemplate;
	FTParser.ParserFromFile(fcin,uFeatTemplate);
	MisContainer dimTemplate;
	for(VuIter Vu_it = uFeatTemplate.begin(); Vu_it != uFeatTemplate.end(); ++Vu_it)
	{
		dimTemplate[atoi(Vu_it->id.c_str())] = Vu_it->type;
	}
	return dimTemplate;
}

VViContainer GetPrimData( ifstream& fcin )
{
	if(!fcin.is_open())
	{
		cerr << "error:Can not open input file." << endl;
		exit(0);
	}
	string str;
	const char* delimiters = ",";
	VViContainer primData;
	while( getline( fcin, str) )
	{
		//cout << str << endl;
		ViContainer primRowData;
		char* pch;
		char tempStr[1000];
		strcpy(tempStr,str.c_str());
		pch  = strtok(tempStr,delimiters);
		primRowData.push_back(atoi(pch));
		while(true)
		{
			pch = strtok(NULL,delimiters);
			if(NULL != pch)
				primRowData.push_back(atoi(pch));
			else
				break;
		}
		primData.push_back(primRowData);
	}
	return primData;
}

void PrintStdArray( ofstream& fout, VVfContainer& stdArray, MisContainer dimTemplate, MiiContainer enumTemplateLenPerDim )
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(4);
	int32_t row = stdArray.size();
	int32_t column;
	if(row != 0)
		column = stdArray[0].size();
	else
		cout << "attention : stdArray is empty! " << endl;
	for( int32_t i=0; i<row; ++i )
	{
		int32_t j = 0;
		for( ; j<column; ++j )
		{
                        if( dimTemplate[j] == "E" )
                        {
                                int32_t len = enumTemplateLenPerDim[j];
                                VfContainer result(len);
                                result[len-int(stdArray[i][j])] = float(1);
                                copy(result.begin(),result.end(),ostream_iterator<float>(fout,","));
                        }
                        else
                                fout << stdArray[i][j] << ",";
		}
		fout << endl;
	}
}
