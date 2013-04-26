// LinearFilter.cpp: implementation of the LinearFilter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bf1.h"
#include "LinearFilter.h"
#include <vector>
#include <deque>
#include "math.h"
#include "Constants.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LinearFilter::LinearFilter()
{
	int n;
	IsFirstCall=true;\
	bcoef.push_back(0.15332455235995e-8);
   	bcoef.push_back(0.61329820943978e-8);
	bcoef.push_back(0.91994731415967e-8);
	bcoef.push_back(0.61329820943978e-8);
	bcoef.push_back(0.15332455235995e-8);
	acoef.push_back(1);
	acoef.push_back(-3.96716259594885);
  	acoef.push_back(5.90202586149089);
	acoef.push_back(-3.90255878482325);
	acoef.push_back(0.96769554381314);
	for(n=0;n<4;n++)
	{
		xvalue.push_back(0);
		yvalue.push_back(0);
	}
}

LinearFilter::LinearFilter(const int ibOrder, const int iaOrder, const double* fb, const double* fa)
{
	int n;
	IsFirstCall=true;
	bcoef.clear();
	acoef.clear();
	xvalue.clear();
	yvalue.clear();
	for(n=0;n!=(ibOrder+1);n++)
	{
		bcoef.push_back(fb[n]);
		xvalue.push_back(0);
	}
	for(n=0;n!=(iaOrder+1);n++)
	{
		acoef.push_back(fa[n]);
		yvalue.push_back(0);
	}

}

LinearFilter::~LinearFilter()
{

}
