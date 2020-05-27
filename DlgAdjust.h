#if !defined(AFX_DLGADJUST_H__058F8E47_9412_44F3_B799_4AC1A877260C__INCLUDED_)
#define AFX_DLGADJUST_H__058F8E47_9412_44F3_B799_4AC1A877260C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAdjust.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAdjust dialog

class CDlgAdjust : public CDialog
{
// Construction
public:
	CDlgAdjust(CWnd* pParent = NULL);   // standard constructor
	~CDlgAdjust();
	int m_iM1;

// Dialog Data
	//{{AFX_DATA(CDlgAdjust)
	enum { IDD = IDD_DIALOG_ADJUST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAdjust)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBrush m_brush;
	// Generated message map functions
	//{{AFX_MSG(CDlgAdjust)
	afx_msg void OnBtnAdjustBegan();
	afx_msg void OnBtnAdjustBack();
	afx_msg void OnBtnAdjustStop();
	afx_msg void OnBtnAdjustSet();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADJUST_H__058F8E47_9412_44F3_B799_4AC1A877260C__INCLUDED_)
