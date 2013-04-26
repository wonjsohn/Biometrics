// bf1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "bf1.h"

#include "MainFrm.h"
#include "bf1Doc.h"
#include "bf1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBf1App

BEGIN_MESSAGE_MAP(CBf1App, CWinApp)
	//{{AFX_MSG_MAP(CBf1App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBf1App construction

CBf1App::CBf1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBf1App object

CBf1App theApp;

// Import Biometrics DLL and create a pointer to an instance of the interface class
#import "C:\\Program Files (x86)\\Biometrics Ltd\\DataLog\\OnLineInterface.dll" no_namespace
IOnLine *pOnline;	

/////////////////////////////////////////////////////////////////////////////
// CBf1App initialization

BOOL CBf1App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Enable OLE support to access DLL content
	AfxOleInit();
	// To use the interface class, create an instance:
	CoCreateInstance(__uuidof(OnLine), NULL, CLSCTX_INPROC_SERVER, __uuidof(IOnLine), (void**)&pOnline);
	if (pOnline == NULL)
	{
		AfxMessageBox("Cannot find OnLineInterface.dll.\n\n"
					  "Please ensure that DataLINK was correctly installed from\n"
					  "the original CD as this also registers the DLL with Windows.");
		return FALSE;
	}
	

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings(2);  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CBf1Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CBf1View));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	// Tried setting position, but I don't know the correct parameters to send
/*	int xPos(100);
	int yPos(100);
	int cX(200);
	int cY(200);
	m_pMainWnd->SetWindowPos(HWND_TOPMOST,xPos,yPos,cX,cY,SWP_SHOWWINDOW);  */
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


int CBf1App::ExitInstance() 
{
	// Release interface class instance when stop application
	if (pOnline != NULL)
		pOnline->Release();	
	
	// Call base class
	return CWinApp::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CBf1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBf1App message handlers



