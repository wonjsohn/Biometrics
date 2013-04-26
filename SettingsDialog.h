#if !defined(AFX_SETTINGSDIALOG_H__753AE34F_2DF1_473A_AFCC_0327476B564E__INCLUDED_)
#define AFX_SETTINGSDIALOG_H__753AE34F_2DF1_473A_AFCC_0327476B564E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog dialog

class CSettingsDialog : public CDialog
{
// Construction
public:
	CSettingsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingsDialog)
	enum { IDD = IDD_DIALOG_SETTINGS };
	int		emg_channel;
	int		emg_samp_period;
	double	emg_sens;
	double	bayes_max;
	double	bayes_switch;
	double	bayes_drift;
	double	bayes_thresh;
	int		vib_com;
	double	vib_bay_max0;
	double	vib_bay_min100;
	double	vib_mean_max0;
	double	vib_mean_min100;
	double	vib_mean_mvc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingsDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGSDIALOG_H__753AE34F_2DF1_473A_AFCC_0327476B564E__INCLUDED_)
