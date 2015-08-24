/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayBalancer : arrayBalancer.cpp
////
//// v1.0 - 2015.05.21 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "arrayBalancer.h"

CarrayBalancer::CarrayBalancer()
{
}

CarrayBalancer::~CarrayBalancer()
{
}

/////////////////////////////////////////////////////////////////////
//operator

//
void CarrayBalancer::Balancer( VVfContainer& posArraySample, VVfContainer& negArraySample, const float& ratio, const string& method )
{
	if(method == "random_downsampling")
	{
		uint32_t samplingNum = uint32_t(float(posArraySample.size())*ratio);
		RandomDownsampling(negArraySample,samplingNum);
	}
}

void CarrayBalancer::RandomDownsampling( VVfContainer& negArraySample, uint32_t samplingNum )
{
	VVfContainer result;
	SiContainer choicedNum;
	uint32_t negArraySampleSize = negArraySample.size();
	uint32_t choicedCount = 0;
	srand(time(NULL));
	while( choicedCount < samplingNum )
	{
		int32_t num = rand()%negArraySampleSize;
		if(choicedNum.find(num) == choicedNum.end())
		{
			choicedNum.insert(num);
			result.push_back(negArraySample[num]);
			++choicedCount;
		}
	}
	negArraySample = result;
}
