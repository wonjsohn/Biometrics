// SettingsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "bf1.h"
#include "SettingsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog dialog


CSettingsDialog::CSettingsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingsDialog)
	emg_channel = 0;
	emg_samp_period = 0;
	emg_sens = 0.0;
	bayes_max = 0.0;
	bayes_switch = 0.0;
	bayes_drift = 0.0;
	bayes_thresh = 0.0;
	vib_com = 0;
	vib_bay_max0 = 0.0;
	vib_bay_min100 = 0.0;
	vib_mean_max0 = 0.0;
	vib_mean_min100 = 0.0;
	vib_mean_mvc = 0.0;
	//}}AFX_DATA_INIT
}


void CSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingsDialog)
	DDX_Text(pDX, IDC_EMG_CHANNEL, emg_channel);
	DDV_MinMaxInt(pDX, emg_channel, 1, 8);
	DDX_Text(pDX, IDC_EMG_PERIOD, emg_samp_period);
	DDV_MinMaxInt(pDX, emg_samp_period, 10, 50);
	DDX_Text(pDX, IDC_EMG_SENS, emg_sens);
	DDX_Text(pDX, IDC_BAYES_MAX, bayes_max);
	DDV_MinMaxDouble(pDX, bayes_max, 0., 5.);
	DDX_Text(pDX, IDC_BAYES_SWITCH, bayes_switch);
	DDX_Text(pDX, IDC_BAYES_DRIFT, bayes_drift);
	DDX_Text(pDX, IDC_BAYES_THRESH, bayes_thresh);
	DDV_MinMaxDouble(pDX, bayes_thresh, 0., 0.5);
	DDX_Text(pDX, IDC_VIB_COM, vib_com);
	DDV_MinMaxInt(pDX, vib_com, 1, 9);
	DDX_Text(pDX, IDC_VIB_BAY_MAX0, vib_bay_max0);
	DDV_MinMaxDouble(pDX, vib_bay_max0, 0., 1.);
	DDX_Text(pDX, IDC_VIB_BAY_MIN100, vib_bay_min100);
	DDV_MinMaxDouble(pDX, vib_bay_min100, 0., 1.);
	DDX_Text(pDX, IDC_VIB_MEAN_MAX0, vib_mean_max0);
	DDV_MinMaxDouble(pDX, vib_mean_max0, 0., 5.);
	DDX_Text(pDX, IDC_VIB_MEAN_MIN100, vib_mean_min100);
	DDV_MinMaxDouble(pDX, vib_mean_min100, 0., 5.);
	DDX_Text(pDX, IDC_VIB_MEAN_MVC, vib_mean_mvc);
	DDV_MinMaxDouble(pDX, vib_mean_mvc, 1.e-002, 10.);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
	//{{AFX_MSG_MAP(CSettingsDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog message handlers
