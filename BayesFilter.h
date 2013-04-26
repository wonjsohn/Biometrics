// Figure out what to add at start

#include <vector>
using std::vector;

class BayesFilter
{
public:
	// Constructor Deconstructor
	BayesFilter();
	BayesFilter(double thresh,double maxv,double switchv,double drift);
	~BayesFilter();

	// Update value with a new sample
	void UpdateEst(double samp);
	// Get the current estimate
	double GetCurrEst() const
		{return dCurrEst;}
	// Return current settings
	void GetSettings(double &thresh,double &maxv,double &switchv,double &drift);

private:
	// Values	
	int PROBPOINTS;			// Number of points to use in estimate
	double dEmgThreshold;	// center of raw data
	double dMaxv;			// Highest observed value.normalize to 1 on this value.
	double dSwitchVal;		// Added to each prior to 'blur' over time
	double dDriftVal;		// blur's adjacent priors.
	double dCurrEst;		// The current estimate of the filter
	vector<double> prior;	// vector of prior
	vector<double> expx;	// vector of exponential distribution
};

