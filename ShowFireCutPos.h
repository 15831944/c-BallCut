#if !defined(AFX_SHOWFIRECUTPOS_H__C895BDFA_5CE4_410E_8800_BE1274B6C9FC__INCLUDED_)
#define AFX_SHOWFIRECUTPOS_H__C895BDFA_5CE4_410E_8800_BE1274B6C9FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowFireCutPos.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowFireCutPos dialog

class CShowFireCutPos : public CDialog
{
// Construction
public:
	CShowFireCutPos(CWnd* pParent = NULL);   // standard constructor
	int m_a,m_b;
// Dialog Data
	//{{AFX_DATA(CShowFireCutPos)
	enum { IDD = IDD_DIALOG_SHOW_FIRE_CUT_POS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowFireCutPos)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowFireCutPos)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWFIRECUTPOS_H__C895BDFA_5CE4_410E_8800_BE1274B6C9FC__INCLUDED_)
