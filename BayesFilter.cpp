// Figure out what to add

#include "stdafx.h"
#include <vector>
#include <math.h>
#include "Constants.h"
#include "BayesFilter.h"

// Constructor
BayesFilter::BayesFilter()
	: PROBPOINTS(128)
	, dEmgThreshold(INIT_BAYES_THRESH)
	, dMaxv(INIT_BAYES_MAXV)
	, dSwitchVal(INIT_BAYES_SWITCH)    
	, dDriftVal(INIT_BAYES_DRIFT)
	, dCurrEst(-99)
{
	// Fill vectors
	int i;
	for (i=0;i<PROBPOINTS;i++)
	{
		prior.push_back((double)(1.0/PROBPOINTS));
		expx.push_back(exp(-(double)i/PROBPOINTS));
	}
}

BayesFilter::BayesFilter(double thresh,double maxv,double switchv,double drift)
	: PROBPOINTS(128)
	, dEmgThreshold(thresh)
	, dMaxv(maxv)
	, dSwitchVal(switchv)    
	, dDriftVal(drift)
	, dCurrEst(-99)
{
	// Fill vectors
	int i;
	for (i=0;i<PROBPOINTS;i++)
	{
		prior.push_back((double)(1.0/PROBPOINTS));
		expx.push_back(exp(-(double)i/PROBPOINTS));
	}
}



// Destructor
BayesFilter::~BayesFilter()
{
}

// Return settings
void BayesFilter::GetSettings(double &thresh,double &maxv,
							  double &switchv,double &drift)
{
	thresh = dEmgThreshold;
	maxv = dMaxv;
	switchv = dSwitchVal;
	drift = dDriftVal;
}


// Updating estimate
void BayesFilter::UpdateEst(double samp)
	// Updates the filter with new measurement
{
	int i(0);
	double v(0);
	double total_pdf(0);
	double max_pdf_val(0);
	int max_pdf_index(0);

	// Normalize or zero the value
	v = samp;
	if(v < dEmgThreshold) 
		v = 0.0;
	v /= dMaxv;
	v *= 4; 

	// Do the propagation steps
	// blurring NECESSARY FOR SMOOTH MOVEMENT
	for (i=0; i<PROBPOINTS ; i++) 
		if (i>0 && i < PROBPOINTS-1)
			prior[i] += dDriftVal * (prior[i-1] + prior[i+1])/100.0;  
	//constant shift   NECESSARY FOR JUMPS
	for (i=0; i<PROBPOINTS ; i++) 
		prior[i] += dSwitchVal * 1.0E-12; 

	// Do estimation step, get sum	
	for (i=0; i<PROBPOINTS ; i++)
	{
		prior[i] *=  pow(((double) i) / PROBPOINTS, v) * expx[i];  //poisson
		total_pdf += prior[i];
	}

	// normalize
	for (i=0; i<PROBPOINTS ; i++) 
		prior[i] /= total_pdf; 
	
	//make prediction by finding highest point of pdf
	for (i=0; i<PROBPOINTS ; i++)  
		if (prior[i] > max_pdf_val)
		{
			max_pdf_val = prior[i]; 
			max_pdf_index = i;
		}
	
	// for some reason, it never becomes 0, so drop down by one
	max_pdf_index = max_pdf_index-1;  

	// Get new value, store in current value
	dCurrEst = ((double) max_pdf_index) / PROBPOINTS;
}
