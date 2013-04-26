// 1DCCSettings.cpp : implementation file
//

#include "stdafx.h"
#include "bf1.h"
#include "1DCCSettings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C1DCCSettings dialog


C1DCCSettings::C1DCCSettings(CWnd* pParent /*=NULL*/)
	: CDialog(C1DCCSettings::IDD, pParent)
{
	//{{AFX_DATA_INIT(C1DCCSettings)
	bayes_drift = 0.0;
	bayes_max = 0.0;
	bayes_switch = 0.0;
	bayes_thresh = 0.0;
	display_time = 0.0;
	rest_time = 0.0;
	emg_samp_period = 0.0;
	emg_sens = 0.0;
	cc_task = 0;
	cc_target_state = 0;
	cc_filter = 0;
	m_EMGin1 = 1;
	m_EMGin2 = 2;
	m_EMGin3 = 3;
	m_EMGin4 = 4;
	//}}AFX_DATA_INIT
}


void C1DCCSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C1DCCSettings)
	DDX_Text(pDX, IDC_BAYES_DRIFT, bayes_drift);
	DDX_Text(pDX, IDC_BAYES_MAX, bayes_max);
	DDX_Text(pDX, IDC_BAYES_SWITCH, bayes_switch);
	DDX_Text(pDX, IDC_BAYES_THRESH, bayes_thresh);
	DDX_Text(pDX, IDC_CC_STATDISPLAY, display_time);
	DDX_Text(pDX, IDC_CC_STATREST, rest_time);
	DDX_Text(pDX, IDC_EMG_PERIOD, emg_samp_period);
	DDX_Text(pDX, IDC_EMG_SENS, emg_sens);
	DDX_Radio(pDX, IDC_RADIO1, cc_task);
	DDX_Radio(pDX, IDC_RADIO4, cc_target_state);
	DDX_Radio(pDX, IDC_RADIO6, cc_filter);
	DDX_Text(pDX, IDC_EDIT1, m_EMGin1);
	DDV_MinMaxInt(pDX, m_EMGin1, 1, 8);
	DDX_Text(pDX, IDC_EDIT2, m_EMGin2);
	DDV_MinMaxInt(pDX, m_EMGin2, 1, 8);
	DDX_Text(pDX, IDC_EDIT3, m_EMGin3);
	DDV_MinMaxInt(pDX, m_EMGin3, 1, 8);
	DDX_Text(pDX, IDC_EDIT4, m_EMGin4);
	DDV_MinMaxInt(pDX, m_EMGin4, 1, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C1DCCSettings, CDialog)
	//{{AFX_MSG_MAP(C1DCCSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C1DCCSettings message handlers




