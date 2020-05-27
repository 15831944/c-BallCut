#if !defined(AFX_DLGZERO_H__3C490C4E_0723_4D4E_8756_140B08901B09__INCLUDED_)
#define AFX_DLGZERO_H__3C490C4E_0723_4D4E_8756_140B08901B09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UniButton.h"
// DlgZero.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgZero dialog

class CDlgZero : public CDialog
{
// Construction
public:

	CDlgZero(CWnd* pParent = NULL);   // standard constructor
	~CDlgZero();

	CBrush m_brush;//刷背景色


// Dialog Data
	//{{AFX_DATA(CDlgZero)
	enum { IDD = IDD_DLG_ZERO };

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgZero)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgZero)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	//}}AFX_MSG
	void InitBtn();
	afx_msg void OnBtnHomeMachine();
	afx_msg void OnBtnHomeSoft();
	afx_msg void OnBtnHomeAll();
	afx_msg void OnBtnHomeStop();
	afx_msg void OnBtnHomeX();
	afx_msg void OnBtnHomeY();
	afx_msg void OnBtnHomeZ();
	afx_msg void OnBtnHomeA();
	afx_msg void OnBtnHomeB();
	afx_msg void OnBtnHomeC();
		
/************************************************************************/
/*								*_*		                                */
/************************************************************************/
	CUniButton m_cZeroX;		//以下是cUniButtom按钮
	CUniButton m_cZeroY;
	CUniButton m_cZeroZ;
	CUniButton m_cZeroA;
	CUniButton m_cZeroB;
	CUniButton m_cZeroC;
	CUniButton m_cZeroMachine;
	CUniButton m_cZeroSofe;
	CUniButton m_cZeroAll;
	CUniButton m_cZeroStop;
	int m_iMachineOrSoft;		//当为0时是机械回零当为1时是PA回零

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGZERO_H__3C490C4E_0723_4D4E_8756_140B08901B09__INCLUDED_)
