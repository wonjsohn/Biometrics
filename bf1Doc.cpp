// bf1Doc.cpp : implementation of the CBf1Doc class
//

#include "stdafx.h"
#include "bf1.h"

#include "bf1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBf1Doc

IMPLEMENT_DYNCREATE(CBf1Doc, CDocument)

BEGIN_MESSAGE_MAP(CBf1Doc, CDocument)
	//{{AFX_MSG_MAP(CBf1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBf1Doc construction/destruction

CBf1Doc::CBf1Doc()
{
	// TODO: add one-time construction code here

}

CBf1Doc::~CBf1Doc()
{
}

BOOL CBf1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBf1Doc serialization

void CBf1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBf1Doc diagnostics

#ifdef _DEBUG
void CBf1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBf1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBf1Doc commands
