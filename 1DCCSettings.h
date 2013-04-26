#if !defined(AFX_1DCCSETTINGS_H__3CBFA05B_FDEA_4DDF_B134_C46516FCBFC2__INCLUDED_)
#define AFX_1DCCSETTINGS_H__3CBFA05B_FDEA_4DDF_B134_C46516FCBFC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 1DCCSettings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// C1DCCSettings dialog

class C1DCCSettings : public CDialog
{
// Construction
public:
	C1DCCSettings(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(C1DCCSettings)
	enum { IDD = IDD_DIALOG_CCSETTINGS };
	double	bayes_drift;
	double	bayes_max;
	double	bayes_switch;
	double	bayes_thresh;
	double	display_time;
	double	rest_time;
	double	emg_samp_period;
	double	emg_sens;
	int		cc_task;
	int		cc_target_state;
	int		cc_filter;
	int		m_EMGin1;
	int		m_EMGin2;
	int		m_EMGin3;
	int		m_EMGin4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C1DCCSettings)
	//}}AFX_VIRTUAL
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(C1DCCSettings)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1DCCSETTINGS_H__3CBFA05B_FDEA_4DDF_B134_C46516FCBFC2__INCLUDED_)
