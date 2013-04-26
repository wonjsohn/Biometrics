// Figure out what to add

#include "stdafx.h"
#include "Constants.h"
#include "MvcCounter.h"

// Constructor
MvcCounter::MvcCounter()
	: bin_sum(0.0)
	, bin_nsamp(0)
	, bin_bound(200)
	, last_bin_nsamp(0)
	, total_nsamp(0)
	, total_bound(300e3)
	, mvc(0.0)
{
}

// Destructor
MvcCounter::~MvcCounter()
{
}

// Get current values
void MvcCounter::GetValues(double &aMvc,long &totSamp,long &lastBinSamp)
{
	aMvc = mvc;
	totSamp = total_nsamp;
	lastBinSamp = last_bin_nsamp;
}

// Updating estimate
void MvcCounter::Update(double mean_rect,long nsamp)
	// Updates the mvc counter with current mvc values from bin
{
	// Add to running totals
	bin_sum += (mean_rect * nsamp);
	bin_nsamp += nsamp;

	// Get mvc if bin gets large enough
	if(bin_nsamp >= bin_bound)
	{
		// Get mvc
		double bin_avg;
		bin_avg = bin_sum / static_cast<double>(bin_nsamp);

		// Set mvc
		if(bin_avg > mvc)
			mvc = bin_avg;

		// Set last nsamp
		last_bin_nsamp = bin_nsamp;

		// Add to total samp
		total_nsamp += bin_nsamp;

		// Reset values
		bin_sum = 0;
		bin_nsamp = 0;
	}
	else if(total_nsamp >= total_bound)
		Reset();
}


void MvcCounter::Reset()
{
	// Resets all values to zero
	bin_sum = 0;
	bin_nsamp = 0;
	last_bin_nsamp = 0;
	total_nsamp = 0;
	mvc = 0;
}