// Figure out what to add at start

class MvcCounter
{
public:
	// Constructor Deconstructor
	MvcCounter();
	~MvcCounter();

	// Update value with a new sample
	void Update(double mean_rect,long nsamp);
	// Reset counter
	void Reset();
	// Get the current values
	void GetValues(double &aMvc,long &totSamp,long &lastBinSamp);
	// Get current mvc
	double GetCurrMvc() const
		{return mvc;}

private:
	// Values	
	double bin_sum;
	long bin_nsamp;
	long last_bin_nsamp;
	long bin_bound;
	long total_nsamp;
	long total_bound;
	double mvc;
};

