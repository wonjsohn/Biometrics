// bf1View.h : interface of the CBf1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BF1VIEW_H__80C01C64_D04D_416F_959C_B94AF9AC5764__INCLUDED_)
#define AFX_BF1VIEW_H__80C01C64_D04D_416F_959C_B94AF9AC5764__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

# include "BayesFilter.h"
# include "LinearFilter.h"
# include "MvcCounter.h"
# include "Serial.h"
# include "1DCCSettings.h"
# include <vector>
# include "PracticalSocket.h"
using std::vector;

class CBf1View : public CView
{
protected: // create from serialization only
	CBf1View();
	DECLARE_DYNCREATE(CBf1View)

// Attributes
public:
	CBf1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBf1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBf1View();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CString StatusLine();
	CString DataLine();
	int ShowError(LONG lError, LPCTSTR lptszMessage);
	LONG OpenPort();
	LONG ClosePort();
	LONG SetPort();
	LONG SetDevice();
	LONG SetSpeed(int speed);
	void SetMotorSpeedMembers(int speed);
	void VibDriveMean();
	void DrawEMGStatus(CDC* pDC,int StartRow,int StartCol);
	void DrawEMGDataStatus(CDC* pDC,int StartRow,int StartCol);
	void DrawEMGInfo(CDC* pDC,int StartRow,int StartCol);
	void DrawBFInfo(CDC* pDC,int StartRow,int StartCol);
	void DrawMVCInfo(CDC* pDC,int StartRow,int StartCol);
	void WriteToFile(vector<long> aVec);

// Data members
protected:
	// EMG
	// Settings
	int emg_chan;
	double emg_sens;  // Sensitivity (V at 4000 input)
	int emg_samp_period;
	// From OnLineStatus function
	int err_return;					// Error return code
	long error_status;
	long enable_status;
	long rate_status;
	long samples_status;
	long value_status;
	// From OnlineGetData function
	int data_return;				// Return value
	long actual_samples;
	// Calculated
	double mean_rect;
	double mean_norm;
	// Timer
	bool bSampleTimer;
	// Bayesian Filter
	BayesFilter ba_filt;
	// Linear filter
	LinearFilter lin_filt;
	// Biofeedback
    CSerial serial;
	bool bBfOpenandSet;
	int	vib_com;
	double vib_bay_max0;
	double vib_bay_min100;
	double vib_mean_mvc;
	double vib_mean_max0;
	double vib_mean_min100;
	int vib_drive_signal;
	int motor_speed;
	int motor_speed_prev;
	// mvc
	MvcCounter mvc_count;
	int viewMode;
	int CC_task;
	int CC_targetmode;
	int CC_filter;
	double CC_display_time;
	double CC_rest_time;
	C1DCCSettings CCdialog;
    // UDP socket
    UDPSocket sock;

// Generated message map functions
protected:
	//{{AFX_MSG(CBf1View)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnSampleStart();
	afx_msg void OnSampleStop();
	afx_msg void OnUpdateSampleStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSampleStop(CCmdUI* pCmdUI);
	afx_msg void OnBfOpen();
	afx_msg void OnBfClose();
	afx_msg void OnBfSet0();
	afx_msg void OnBfSet100();
	afx_msg void OnBfSet50();
	afx_msg void OnUpdateBfOpen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBfClose(CCmdUI* pCmdUI);
	afx_msg void OnSettingsDialog();
	afx_msg void OnBfDriveMean();
	afx_msg void OnBfDriveBayes();
	afx_msg void OnUpdateBfDriveMean(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBfDriveBayes(CCmdUI* pCmdUI);
	afx_msg void OnMvcReset();
	afx_msg void OnCCSettingsDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBfStudy();
	afx_msg void OnUpdateBfStudy(CCmdUI *pCmdUI);
	afx_msg void OnCcPractice();
	afx_msg void OnUpdateCcPractice(CCmdUI *pCmdUI);
	afx_msg void OnCcStudy1();
	afx_msg void OnUpdateCcStudy1(CCmdUI *pCmdUI);
	afx_msg void OnRcPractice();
	afx_msg void OnUpdateRcPractice(CCmdUI *pCmdUI);
	afx_msg void OnRcStudy1();
	afx_msg void OnUpdateRcStudy1(CCmdUI *pCmdUI);
	afx_msg void OnSpeechStudy1();
	afx_msg void OnUpdateSpeechStudy1(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in bf1View.cpp
inline CBf1Doc* CBf1View::GetDocument()
   { return (CBf1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BF1VIEW_H__80C01C64_D04D_416F_959C_B94AF9AC5764__INCLUDED_)
