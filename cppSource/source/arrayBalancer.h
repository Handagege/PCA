/////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// CarrayBalancer : arrayBalancer.h
////
//// v1.0 - 2015.05.22 by (zhanghan5@staff.weibo.com) 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "defType.h"
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <time.h>

#ifndef _ARRAYBALANCER_H
#define _ARRAYBALANCER_H

using namespace std;

class CarrayBalancer
{
public:
	CarrayBalancer();
	virtual ~CarrayBalancer();

	virtual void Balancer( VVfContainer& negArraySample, VVfContainer& posArraySample,
		const float& ratio = 3.0, const string& method = "random_downsampling" );
private:
	void RandomDownsampling( VVfContainer& negArraySample, uint32_t samplingNum );

};

#endif
