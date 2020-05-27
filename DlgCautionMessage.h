#if !defined(AFX_DLGCAUTIONMESSAGE_H__8D9E3E7C_53EC_426A_A6B5_0BF08BD09DAB__INCLUDED_)
#define AFX_DLGCAUTIONMESSAGE_H__8D9E3E7C_53EC_426A_A6B5_0BF08BD09DAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCautionMessage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCautionMessage dialog

class CDlgCautionMessage : public CDialog
{
// Construction
public:
	CDlgCautionMessage(CWnd* pParent = NULL);   // standard constructor
	~CDlgCautionMessage();
	CString		strAfxMessage;
	CString		strAfxTitle;
	CString		strAfxYES;
	CString		strAfxNO;
	BOOL		bYesNo;
	CBrush		m_brush;
// Dialog Data
	//{{AFX_DATA(CDlgCautionMessage)
	enum { IDD = IDD_DIALOG_CAUTION_MESSAGE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCautionMessage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCautionMessage)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCAUTIONMESSAGE_H__8D9E3E7C_53EC_426A_A6B5_0BF08BD09DAB__INCLUDED_)
