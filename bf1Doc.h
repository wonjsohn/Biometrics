// bf1Doc.h : interface of the CBf1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BF1DOC_H__D2D08BF1_8547_4C22_8AE9_C0DCFC0056BF__INCLUDED_)
#define AFX_BF1DOC_H__D2D08BF1_8547_4C22_8AE9_C0DCFC0056BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBf1Doc : public CDocument
{
protected: // create from serialization only
	CBf1Doc();
	DECLARE_DYNCREATE(CBf1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBf1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBf1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBf1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BF1DOC_H__D2D08BF1_8547_4C22_8AE9_C0DCFC0056BF__INCLUDED_)
