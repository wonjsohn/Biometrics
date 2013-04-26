// bf1View.cpp : implementation of the CBf1View class
//

#include "stdafx.h"
#include "bf1.h"
#include <vector>
using std::vector;

#include "Constants.h"
#include "bf1Doc.h"
#include "bf1View.h"
#include "SettingsDialog.h"
#include "1DCCSettings.h"

// Adding in stream libraries added by Claudia
#include <iostream>
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Import Biometrics DLL and refer to pointer to interface instance created in App class
#import "C:\\Program Files (x86)\\Biometrics Ltd\\DataLog\\OnLineInterface.dll" no_namespace
extern	IOnLine *pOnline;

//ofstream outfile;
//ofstream outfile1;



/////////////////////////////////////////////////////////////////////////////
// CBf1View

IMPLEMENT_DYNCREATE(CBf1View, CView)

BEGIN_MESSAGE_MAP(CBf1View, CView)
	//{{AFX_MSG_MAP(CBf1View)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_COMMAND(ID_SAMPLE_START, OnSampleStart)
	ON_COMMAND(ID_SAMPLE_STOP, OnSampleStop)
	ON_UPDATE_COMMAND_UI(ID_SAMPLE_START, OnUpdateSampleStart)
	ON_UPDATE_COMMAND_UI(ID_SAMPLE_STOP, OnUpdateSampleStop)
	ON_COMMAND(ID_BF_OPEN, OnBfOpen)
	ON_COMMAND(ID_BF_CLOSE, OnBfClose)
	ON_COMMAND(ID_BF_0, OnBfSet0)
	ON_COMMAND(ID_BF_100, OnBfSet100)
	ON_COMMAND(ID_BF_50, OnBfSet50)
	ON_UPDATE_COMMAND_UI(ID_BF_OPEN, OnUpdateBfOpen)
	ON_UPDATE_COMMAND_UI(ID_BF_CLOSE, OnUpdateBfClose)
	ON_COMMAND(ID_SETTINGS_DIALOG, OnSettingsDialog)
	ON_COMMAND(ID_BF_DRIVE_MEAN, OnBfDriveMean)
	ON_COMMAND(ID_BF_DRIVE_BAYES, OnBfDriveBayes)
	ON_UPDATE_COMMAND_UI(ID_BF_DRIVE_MEAN, OnUpdateBfDriveMean)
	ON_UPDATE_COMMAND_UI(ID_BF_DRIVE_BAYES, OnUpdateBfDriveBayes)
	ON_COMMAND(ID_MVC_RESET, OnMvcReset)
	ON_COMMAND(ID_CCSETTINGS_DIALOG, OnCCSettingsDialog)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_BF_STUDY, &CBf1View::OnBfStudy)
	ON_UPDATE_COMMAND_UI(ID_BF_STUDY, &CBf1View::OnUpdateBfStudy)
	ON_COMMAND(ID_CC_PRACTICE, &CBf1View::OnCcPractice)
	ON_UPDATE_COMMAND_UI(ID_CC_PRACTICE, &CBf1View::OnUpdateCcPractice)
	ON_COMMAND(ID_CC_STUDY1, &CBf1View::OnCcStudy1)
	ON_UPDATE_COMMAND_UI(ID_CC_STUDY1, &CBf1View::OnUpdateCcStudy1)
	ON_COMMAND(ID_RC_PRACTICE, &CBf1View::OnRcPractice)
	ON_UPDATE_COMMAND_UI(ID_RC_PRACTICE, &CBf1View::OnUpdateRcPractice)
	ON_COMMAND(ID_RC_STUDY1, &CBf1View::OnRcStudy1)
	ON_UPDATE_COMMAND_UI(ID_RC_STUDY1, &CBf1View::OnUpdateRcStudy1)
	ON_COMMAND(ID_SPEECH_STUDY1, &CBf1View::OnSpeechStudy1)
	ON_UPDATE_COMMAND_UI(ID_SPEECH_STUDY1, &CBf1View::OnUpdateSpeechStudy1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBf1View construction/destruction

CBf1View::CBf1View()
	: err_return(-99)
	, error_status(-99)
	, enable_status(-99)
	, rate_status(-99)
	, samples_status(-99)
	, value_status(-99)
	, data_return(-99)
	, actual_samples(-99)
	, mean_rect(-99)
	, mean_norm(-99)
	, bSampleTimer(false)
	, ba_filt()
	, serial()
	, bBfOpenandSet(false)
	, emg_chan(INIT_CHANNEL)
	, emg_sens(INIT_SENS)
	, emg_samp_period(INIT_SAMP_PERIOD)
	, vib_com(INIT_VIB_COM)
	, vib_bay_max0(INIT_VIB_BAY_MAX0)
	, vib_bay_min100(INIT_VIB_BAY_MIN100)
	, vib_mean_mvc(INIT_VIB_MEAN_MVC)
	, vib_mean_max0(INIT_VIB_MEAN_MAX0)
	, vib_mean_min100(INIT_VIB_MEAN_MIN100)
	, vib_drive_signal(VIB_DRIVE_MEAN)
	, motor_speed(0)
	, motor_speed_prev(0)
	, mvc_count()
	, viewMode(VIEW_BF)
	, CC_task(CC_1D_1DOF)
	, CC_targetmode(CC_STAT_TARGETS)
	, CC_filter(CC_BAYES_FILT)
	, CC_display_time(CC_INIT_TIME)
	, CC_rest_time(CC_INIT_TIME)
    , sock(31405)
{
}

CBf1View::~CBf1View()
{
}

BOOL CBf1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBf1View drawing


void CBf1View::OnDraw(CDC* pDC)
{
	CBf1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// EMG Status values
	//DrawEMGStatus(pDC,0,0);
	//DrawEMGDataStatus(pDC,120,0);

	switch(viewMode)
	{
	case VIEW_BF:
	case VIEW_ROBOT_PRACTICE:
		// EMG info
		DrawEMGInfo(pDC,0,0);
		DrawBFInfo(pDC,0,300);
		DrawMVCInfo(pDC,0,600);
		break;
	case VIEW_CC_PRACTICE:
		break;
	case VIEW_CC_STUDY1:
		break;
	default:
		// EMG info
		DrawEMGInfo(pDC,0,0);
		DrawBFInfo(pDC,0,300);
		DrawMVCInfo(pDC,0,600);
	}
}


void CBf1View::DrawEMGStatus(CDC* pDC,int startRow,int startCol)
{
	// Print status
	CString text1;

	pDC->TextOut(startCol,startRow+0,"EMG Status");
	text1.Format("err_return: %ld",err_return);
	pDC->TextOut(startCol,startRow+15,text1);
	text1.Format("error: %ld",error_status);
	pDC->TextOut(startCol,startRow+30,text1);
	text1.Format("enable: %ld",enable_status);
	pDC->TextOut(startCol,startRow+45,text1);
	text1.Format("rate: %ld",rate_status);
	pDC->TextOut(startCol,startRow+60,text1);
	text1.Format("samples: %ld",samples_status);
	pDC->TextOut(startCol,startRow+75,text1);
	text1.Format("value: %ld",value_status);
	pDC->TextOut(startCol,startRow+90,text1);
}

void CBf1View::DrawEMGDataStatus(CDC* pDC,int startRow,int startCol)
{
	CString text1;

	pDC->TextOut(startCol,startRow+0,"EMG Data Status");
	text1.Format("data_return: %ld",data_return);
	pDC->TextOut(startCol,startRow+15,text1);
	text1.Format("actual samples: %ld",actual_samples);
	pDC->TextOut(startCol,startRow+30,text1);
}

void CBf1View::DrawEMGInfo(CDC* pDC,int startRow,int startCol)
{
	CString text1;

	pDC->TextOut(startCol,startRow+0,"EMG Information");
	text1.Format("Channel: %ld",emg_chan);
	pDC->TextOut(startCol,startRow+20,text1);
	bSampleTimer ? (text1 = "Sampling") : (text1 = "Not Sampling");
	pDC->TextOut(startCol,startRow+40,text1);
	text1.Format("sample period (ms): %ld",emg_samp_period);
	pDC->TextOut(startCol,startRow+60,text1);
	text1.Format("actual samples: %ld",actual_samples);
	pDC->TextOut(startCol,startRow+80,text1);
	text1.Format("mean: %5.5f",mean_rect);
	pDC->TextOut(startCol,startRow+100,text1);
	text1.Format("mvc: %5.5f",vib_mean_mvc);
	pDC->TextOut(startCol,startRow+120,text1);
	text1.Format("mean norm: %5.5f",mean_norm);
	pDC->TextOut(startCol,startRow+140,text1);
	text1.Format("dCurrEst: %5.5f",ba_filt.GetCurrEst());
	pDC->TextOut(startCol,startRow+160,text1);
}
	
	
void CBf1View::DrawBFInfo(CDC* pDC,int startRow,int startCol)
{
	CString text1;

	pDC->TextOut(startCol,startRow+0,"Biofeedback Information");
	text1.Format("COM Port: %ld",vib_com);
	pDC->TextOut(startCol,startRow+20,text1);
	bBfOpenandSet ? (text1 = "Port Open and Set") : (text1 = "Port Closed");
	pDC->TextOut(startCol,startRow+40,text1);
	
	if(vib_drive_signal == VIB_DRIVE_MEAN)
		text1 = "Driven by mean EMG";
	else if(vib_drive_signal == VIB_DRIVE_BAYES)
		text1 = "Driven by bayesian filter";
	else
		text1 = "Error: incorrect drive signal";
	pDC->TextOut(startCol,startRow+60,text1);

	text1.Format("Mean EMG motor start: %2.3f",vib_mean_max0);
	pDC->TextOut(startCol,startRow+80,text1);
	text1.Format("Mean EMG motor maximum: %2.3f",vib_mean_min100);
	pDC->TextOut(startCol,startRow+100,text1);
	text1.Format("motor speed: %ld",motor_speed);
	pDC->TextOut(startCol,startRow+120,text1);
}


void CBf1View::DrawMVCInfo(CDC* pDC,int startRow,int startCol)
{
	CString text1;
	double curr_mvc(0);
	long total_samp(0);
	long last_bin_samp(0);

	pDC->TextOut(startCol,startRow+0,"MVC Counter");
	mvc_count.GetValues(curr_mvc,total_samp,last_bin_samp);
	text1.Format("Current MVC: %5.4f",curr_mvc);
	pDC->TextOut(startCol,startRow+20,text1);
	text1.Format("Total MVC samples: %ld",total_samp);
	pDC->TextOut(startCol,startRow+40,text1);
	text1.Format("Last MVC bin samples: %ld",last_bin_samp);
	pDC->TextOut(startCol,startRow+60,text1);
}


	

/////////////////////////////////////////////////////////////////////////////
// CBf1View diagnostics

#ifdef _DEBUG
void CBf1View::AssertValid() const
{
	CView::AssertValid();
}

void CBf1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBf1Doc* CBf1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBf1Doc)));
	return (CBf1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBf1View message handlers

void CBf1View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
		
}



void CBf1View::OnTimer(UINT nIDEvent) 
{
	// Do this for sampling emg
	if (nIDEvent == ID_TIMER_VIEW)
	{
		// Get all status values, also get error return value from one call
		err_return = pOnline->OnLineStatus(0, ONLINE_GETERROR, &error_status);
		pOnline->OnLineStatus(0, ONLINE_GETENABLE, &enable_status);
		pOnline->OnLineStatus(0, ONLINE_GETRATE, &rate_status);
		pOnline->OnLineStatus(0, ONLINE_GETSAMPLES, &samples_status);
		pOnline->OnLineStatus(0, ONLINE_GETVALUE, &value_status);

		// Get values from data transfer
		SAFEARRAY *pSafeArrayZeroDim = SafeArrayCreate(VT_I2, 0, 0);
		SAFEARRAY *pSafeArray = pSafeArrayZeroDim;  
        
        // read up to 100mS of data as values -4000 to +4000
		// for channel use emg_chan-1 b/c stored in 1:8 but called in 0:7 format
		data_return = pOnline->OnLineGetData(emg_chan-1,100,&pSafeArray,&actual_samples);

		// Get mean if we read in data ok
		if ((data_return == ONLINE_OK) && (actual_samples > 0))
		{
			// Create pointer for iterating through array
			short *pValue;

			if (SafeArrayAccessData(pSafeArray,(LPVOID *)&pValue) == S_OK)
			{
				// Go through all EMG values
				long aSum(0);
				vector<long> emgVec;
				for (int sample = 0; sample < actual_samples; sample++, pValue++)
				{
					// Get sum of all rectified values
					aSum += (*pValue >= 0 ? *pValue : -(*pValue));  // Add rectified value
					// Add all emg to the vector
					emgVec.push_back(*pValue);
				}
				// Get mean of rectified (in floating point)
				mean_rect = (static_cast<double>(aSum) / 
							 static_cast<double>(actual_samples)) *
							(emg_sens / 4000.0);
				// Get normalized mean
				mean_norm = mean_rect / vib_mean_mvc;

				// Update filter
				ba_filt.UpdateEst(mean_rect);

				// Send value to motor and write values
				if(bBfOpenandSet)
				{
					// Choose correct driving signal
					if(vib_drive_signal == VIB_DRIVE_MEAN)
						VibDriveMean();
					// Write emg and motor speed to file
					//WriteToFile(emgVec);
				}
				// Send values to the mvc counter
				mvc_count.Update(mean_rect,actual_samples);

            }

        }		

        // Write UDP socket no matter if mean_rect is valid
        {             
            const int ECHOMAX = 255;          
            //char* echoString = "Hello";
            char echoString[1024];
            float foo = (float) mean_rect;
            sprintf(echoString, "%f", foo);
            string servAddress = "192.168.0.116";
            int echoStringLen = strlen(echoString);
            sock.sendTo(echoString, echoStringLen, servAddress, 6005);

        }
		
		// Destroy the array and pointers
		SafeArrayDestroy(pSafeArray);
		SafeArrayDestroy(pSafeArrayZeroDim);

		// Update the view to show most recent values
		GetDocument()->UpdateAllViews(NULL);	
	}
	
	CView::OnTimer(nIDEvent);
}


void CBf1View::WriteToFile(vector<long> aVec)	
{
	// Write out to file
	CString fName = "C:\\MotorSpeedFiles\\motorSpeed.txt";
	//outfile.open (fName, ios::app);

	// Iterate through vector
	for(vector<long>::const_iterator iter = aVec.begin();
		iter != aVec.end(); iter++)
		{
			/*outfile<< static_cast<double>(*iter) * (emg_sens / 4000.0)
				   << " " << motor_speed_prev<<endl;*/
		}
		
    //outfile.close();
}

	
	
void CBf1View::OnDestroy() 
{
	// When window is being destroyed
	CView::OnDestroy();
	// kill the timer if still running
	OnSampleStop();
}

void CBf1View::OnSampleStart() 
{
	// only do something if sampling not already on
	if(!bSampleTimer)
	{
		// Create the timer for collecting samples, set variable
		//freopen( "output_bf1_extra.txt", "w", stdout );
		//cout << "test out here\n";
		//cout <<  emg_samp_period;

		// trigger start in HandInSpace for synchronized data acquisition
		//C:\Program Files\CyberGlove Systems\VirtualHand SDK\demos\bin\winnt_x64\Debug
		//ShellExecute(NULL, "open", "C:\\Program Files (x86)\\Biometrics Ltd\\DataLog\\Config.exe", NULL, NULL, SW_SHOWNORMAL);
		//ShellExecute(NULL,"open","C:\\Program Files\\CyberGlove Systems\\VirtualHand SDK\\demos\\bin\\winnt_x64\\Debug\\HandInSpace.exe",NULL,NULL,SW_SHOWNORMAL);
		ShellExecute(NULL,"open","C:\\Program Files\\CyberGlove Systems\\VirtualHand SDK\\demos\\bin\\winnt_x64\\Debug\\GetGloveData.exe",NULL,"C:\\Program Files\\CyberGlove Systems\\VirtualHand SDK\\demos\\bin\\winnt_x64\\Debug",SW_SHOWNORMAL);
		

		long pStatus;
		pOnline->OnLineStatus(emg_chan-1, ONLINE_START, &pStatus);
		SetTimer(ID_TIMER_VIEW,emg_samp_period,NULL);	
		bSampleTimer = true;
	}
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
	cout << "\nbSampleTimer true\n";
}

void CBf1View::OnSampleStop() 
{
	// only do something if sampling 
	if(bSampleTimer)
	{
		// kill the timer and set variable
		KillTimer(ID_TIMER_VIEW);
		bSampleTimer = false;
		long pStatus;
		pOnline->OnLineStatus(emg_chan-1, ONLINE_STOP, &pStatus);
		fclose (stdout);
	}
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}


void CBf1View::OnUpdateSampleStart(CCmdUI* pCmdUI) 
{
	// Check item if sampling
	pCmdUI->SetCheck(bSampleTimer);
}

void CBf1View::OnUpdateSampleStop(CCmdUI* pCmdUI) 
{
	// Check item if not sampling
	pCmdUI->SetCheck(!bSampleTimer);
}


int CBf1View::ShowError(LONG lError, LPCTSTR lptszMessage)
{
	// Generate a message text
	TCHAR tszMessage[256];
	wsprintf(tszMessage,_T("%s\n(error code %d)"), lptszMessage, lError);

	// Display message-box and return with an error-code
	::MessageBox(0,tszMessage,_T("Biofeedback Device"), MB_ICONSTOP|MB_OK);
	return 1;
}

void CBf1View::OnBfOpen() 
{
	// Only do something if port not already open
	if(bBfOpenandSet)
		MessageBox("Port already open and set");
	else
	{
		LONG lLastError = ERROR_SUCCESS;
		// Open serial port
		lLastError = OpenPort();
		// 2012 01 20: bug with this now: OpenPort return doesn't set var
		// Will not deal with now.
		// 2012 01 23: changed == to =.  That might have fixed it.
 		if(lLastError == ERROR_SUCCESS)
		{
			// Set port
			lLastError = SetPort();
			if(lLastError == ERROR_SUCCESS)
			{
				// Set all things up on biofeedback
				lLastError = SetDevice();
				if(lLastError == ERROR_SUCCESS)
					bBfOpenandSet = true;
				else
					ClosePort();
			}
			else
				ClosePort();
		}
	}
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}


LONG CBf1View::OpenPort()
{
	LONG lLastError = ERROR_SUCCESS;
	CString aString;
	aString.Format("COM%ld",vib_com);
	lLastError = serial.Open(aString,0,0,false);
	if(lLastError != ERROR_SUCCESS)
		ShowError(serial.GetLastError(), _T("Unable to open COM-port"));
	return lLastError;
}


LONG CBf1View::ClosePort()
{
	LONG lLastError = ERROR_SUCCESS;
	lLastError = serial.Close();
	if (lLastError == ERROR_SUCCESS)
		bBfOpenandSet = false;
	else
		ShowError(serial.GetLastError(), _T("Unable to close COM-port"));
	return lLastError;
}


LONG CBf1View::SetPort()
{
	LONG lLastError = ERROR_SUCCESS;
	// Set port
	lLastError = serial.Setup(CSerial::EBaudrate(230400),
							  CSerial::EDataBits(8),
						      CSerial::EParity(NOPARITY),
						      CSerial::EStopBits(ONESTOPBIT));
	if(lLastError != ERROR_SUCCESS)
		ShowError(serial.GetLastError(), _T("Unable to set COM-port setting"));
	return lLastError;
}

LONG CBf1View::SetDevice()
{
	LONG lLastError = ERROR_SUCCESS;
	LONG nonSuccessError(ERROR_SUCCESS);
	char buf1[1];

	// Turn off EMG
	buf1[0] = COMMAND_EMG_OFF;
 	lLastError = serial.Write(buf1);
	if (lLastError != ERROR_SUCCESS)
	{
		ShowError(serial.GetLastError(), _T("Unable to turn EMG off"));
		nonSuccessError = lLastError;
	}

	// Turn off bluetooth
	buf1[0] = COMMAND_BLUETOOTH_OFF;
 	lLastError = serial.Write(buf1);
	if (lLastError != ERROR_SUCCESS)
	{
		ShowError(serial.GetLastError(), _T("Unable to turn Bluetooth off"));
		nonSuccessError = lLastError;
	}

	// Turn on motor
	buf1[0] = COMMAND_MOTOR_ON;
 	lLastError = serial.Write(buf1);
	if (lLastError != ERROR_SUCCESS)
	{
		ShowError(serial.GetLastError(), _T("Unable to turn motor on"));
		nonSuccessError = lLastError;
	}


	// Turn on slave mode
	buf1[0] = COMMAND_SET_MOTOR_SPEED;
 	lLastError = serial.Write(buf1);
	if (lLastError != ERROR_SUCCESS)
	{
		ShowError(serial.GetLastError(), _T("Unable to turn slave mode on"));
		nonSuccessError = lLastError;
	}

	// Set speed to zero (don't call SetSpeed b/c haven't set port active yet)
	buf1[0] = 0;
 	lLastError = serial.Write(buf1);
	if (lLastError != ERROR_SUCCESS)
	{
		ShowError(serial.GetLastError(),_T("Unable to set speed to 0"));
	}
	else
		SetMotorSpeedMembers(0);

	return nonSuccessError;
}


LONG CBf1View::SetSpeed(int speed)
{
	// Check port status and speed argument
	if(!bBfOpenandSet)
	{
		MessageBox("Biofeedback port not open and set");
		return -1;
	}
	else 
	{
		// Truncate speed if too high or low
		if(speed > 100)
			speed=100;
		else if(speed < 0)
			speed=0;

		// Set speed
		LONG lLastError = ERROR_SUCCESS;
		char buf1[1];
		buf1[0] = speed;
 		lLastError = serial.Write(buf1);
		if (lLastError != ERROR_SUCCESS)
		{
			ShowError(serial.GetLastError(),
				      _T("Unable to set speed"));
		}
		else
			SetMotorSpeedMembers(speed);

		return lLastError;
	}
}


void CBf1View::SetMotorSpeedMembers(int speed)
{
	// Set current to previous and new to current
	motor_speed_prev = motor_speed;
	motor_speed = speed;
}


void CBf1View::OnBfClose() 
{
	// Only do something if port open and set
	if(!bBfOpenandSet)
		MessageBox("Port already closed");
	else
	{
		LONG lLastError = ERROR_SUCCESS;
		char buf1[1];
		
		// Set speed to zero
		int speed = 0;
		lLastError = SetSpeed(speed);
		
		// Turn off slave mode
		buf1[0] = COMMAND_RELEASE_MOTOR_SPEED;
		lLastError = serial.Write(buf1);
		if (lLastError != ERROR_SUCCESS)
			ShowError(serial.GetLastError(), _T("Unable to turn off slave mode"));
		
		// Turn off motor
		buf1[0] = COMMAND_MOTOR_OFF;
		lLastError = serial.Write(buf1);
		if (lLastError != ERROR_SUCCESS)
			ShowError(serial.GetLastError(), _T("Unable to turn off motor"));
		
		// Close the port
		ClosePort();
	}
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnBfSet0() 
{
	// Set speed to zero
	int speed(0);
	SetSpeed(speed);
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnBfSet100() 
{
	// Set speed to zero
	int speed(100);
	SetSpeed(speed);
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnBfSet50() 
{
	// Set speed to zero
	int speed(50);
	SetSpeed(speed);
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnUpdateBfOpen(CCmdUI* pCmdUI) 
{
	// Check item if Biofeedback port open and set
	pCmdUI->SetCheck(bBfOpenandSet);
}

void CBf1View::OnUpdateBfClose(CCmdUI* pCmdUI) 
{
	// Check item if Biofeedback port closed
	pCmdUI->SetCheck(!bBfOpenandSet);
}

void CBf1View::OnSettingsDialog() 
{
	// Create dialog object
	CSettingsDialog aDlg;

	// Set data members 
	// emg
	aDlg.emg_channel = emg_chan;
	aDlg.emg_sens = emg_sens;
    aDlg.emg_samp_period = emg_samp_period;
	// bayesian filter
	ba_filt.GetSettings(aDlg.bayes_thresh,aDlg.bayes_max,
						aDlg.bayes_switch,aDlg.bayes_drift);
	// vibration
	aDlg.vib_com = vib_com;
	aDlg.vib_bay_max0 = vib_bay_max0;
	aDlg.vib_bay_min100 = vib_bay_min100;
	aDlg.vib_mean_mvc = vib_mean_mvc;
	aDlg.vib_mean_max0 = vib_mean_max0;
	aDlg.vib_mean_min100 = vib_mean_min100;


	// Display the dialog modal, change things if okay
	if(aDlg.DoModal() == IDOK)
	{
		// Close port and stop sampling if these are happening
		if(bBfOpenandSet)
			OnBfClose();
		if(bSampleTimer)
			OnSampleStop();

		// Make changes
		// emg
		emg_chan = aDlg.emg_channel;
		emg_sens = aDlg.emg_sens;
		emg_samp_period = aDlg.emg_samp_period;
		// bayesian filter: create a new filter
		ba_filt = BayesFilter(aDlg.bayes_thresh,aDlg.bayes_max,
							  aDlg.bayes_switch,aDlg.bayes_drift);
		// vibration
		vib_com = aDlg.vib_com;
		vib_bay_max0 = aDlg.vib_bay_max0;
		vib_bay_min100 = aDlg.vib_bay_min100;
		vib_mean_mvc = aDlg.vib_mean_mvc;
		vib_mean_max0 = aDlg.vib_mean_max0;
		vib_mean_min100 = aDlg.vib_mean_min100;
	}
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnBfDriveMean() 
{
	vib_drive_signal = VIB_DRIVE_MEAN;
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnBfDriveBayes() 
{
	vib_drive_signal = VIB_DRIVE_BAYES;
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnUpdateBfDriveMean(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(vib_drive_signal == VIB_DRIVE_MEAN);
}

void CBf1View::OnUpdateBfDriveBayes(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(vib_drive_signal == VIB_DRIVE_BAYES);
}

void CBf1View::VibDriveMean()
{
	// Set speed
	int aSpeed(0);
	if(mean_norm <= vib_mean_max0)
		aSpeed = 0;
	else if(mean_norm >= vib_mean_min100)
		aSpeed = 100;
	else
		aSpeed = static_cast<int>(100 * (mean_norm - vib_mean_max0) / 
									    (vib_mean_min100 - vib_mean_max0));
	// Send speed
	SetSpeed(aSpeed);
}
	

void CBf1View::OnMvcReset() 
{
	mvc_count.Reset();
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}

void CBf1View::OnCCSettingsDialog() 
{

	//targets
	CCdialog.cc_task = CC_task;
	CCdialog.cc_target_state = CC_targetmode;
	CCdialog.cc_filter = CC_filter;
	CCdialog.display_time = CC_display_time;
	CCdialog.rest_time = CC_rest_time;
	// emg


	CCdialog.emg_sens = emg_sens;
	CCdialog.emg_samp_period = emg_samp_period;
	// bayesian filter
	ba_filt.GetSettings(CCdialog.bayes_thresh,CCdialog.bayes_max,
						CCdialog.bayes_switch,CCdialog.bayes_drift);


	// Display the dialog modal, change things if okay
	if(CCdialog.DoModal() == IDOK)
	{
		// Close port and stop sampling if these are happening
		if(bBfOpenandSet)
			OnBfClose();
		if(bSampleTimer)
			OnSampleStop();

		// Make changes
		// targets
		CC_task = CCdialog.cc_task;
		CC_targetmode = CCdialog.cc_target_state;
		CC_filter = CCdialog.cc_filter;
		CC_display_time = CCdialog.display_time;
		CC_rest_time = CCdialog.rest_time;
		// emg
		emg_sens = CCdialog.emg_sens;
		emg_samp_period = CCdialog.emg_samp_period;
		// bayesian filter: create a new filter
		ba_filt = BayesFilter(CCdialog.bayes_thresh,CCdialog.bayes_max,
							  CCdialog.bayes_switch,CCdialog.bayes_drift);
	}
	// Update the view to show most recent values
	GetDocument()->UpdateAllViews(NULL);	
}


void CBf1View::OnBfStudy()
{
	viewMode =	VIEW_BF;
}


void CBf1View::OnUpdateBfStudy(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(viewMode == VIEW_BF);
}


void CBf1View::OnCcPractice()
{
	viewMode =	VIEW_CC_PRACTICE;
}


void CBf1View::OnUpdateCcPractice(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(viewMode == VIEW_CC_PRACTICE);
}


void CBf1View::OnCcStudy1()
{
	viewMode =	VIEW_CC_STUDY1;
}


void CBf1View::OnUpdateCcStudy1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(viewMode == VIEW_CC_STUDY1);
}


void CBf1View::OnRcPractice()
{
	viewMode =	VIEW_ROBOT_PRACTICE;
}


void CBf1View::OnUpdateRcPractice(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(viewMode == VIEW_ROBOT_PRACTICE);
}


void CBf1View::OnRcStudy1()
{
	viewMode =	VIEW_ROBOT_STUDY1;
}


void CBf1View::OnUpdateRcStudy1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(viewMode == VIEW_ROBOT_STUDY1);
}


void CBf1View::OnSpeechStudy1()
{
	viewMode =	VIEW_SPEECH_STUDY1;
}


void CBf1View::OnUpdateSpeechStudy1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(viewMode == VIEW_SPEECH_STUDY1);
}
