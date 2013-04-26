// bf1.h : main header file for the BF1 application
//

#if !defined(AFX_BF1_H__5D3DF1A9_A87A_482A_B2E5_0A12E7FD4736__INCLUDED_)
#define AFX_BF1_H__5D3DF1A9_A87A_482A_B2E5_0A12E7FD4736__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBf1App:
// See bf1.cpp for the implementation of this class
//

class CBf1App : public CWinApp
{
public:
	CBf1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBf1App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBf1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BF1_H__5D3DF1A9_A87A_482A_B2E5_0A12E7FD4736__INCLUDED_)
