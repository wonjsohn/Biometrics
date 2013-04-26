// LinearFilter.h: interface for the LinearFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEARFILTER_H__48AD8B3E_30E2_46CB_84F2_7A0702A389AC__INCLUDED_)
#define AFX_LINEARFILTER_H__48AD8B3E_30E2_46CB_84F2_7A0702A389AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>
#include <deque>
#include "math.h"
#include <fstream>
using namespace std;


class LinearFilter  
{
private:
	vector<double> bcoef;
	vector<double> acoef;
	deque<double> xvalue;
	deque<double> yvalue;
	bool IsFirstCall;
public:
	LinearFilter();
	LinearFilter(const int ibOrder, const int iaOrder, const double* fb, const double* fa);
	virtual ~LinearFilter();

};

#endif // !defined(AFX_LINEARFILTER_H__48AD8B3E_30E2_46CB_84F2_7A0702A389AC__INCLUDED_)
