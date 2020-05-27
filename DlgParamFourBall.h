#if !defined(AFX_DLGPARAMFOURBALL_H__1D0A0496_DA68_4E9C_B334_CDA1E85D0167__INCLUDED_)
#define AFX_DLGPARAMFOURBALL_H__1D0A0496_DA68_4E9C_B334_CDA1E85D0167__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgParamFourBall.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgParamFourBall dialog

class CDlgParamFourBall : public CDialog
{
// Construction
public:
	CDlgParamFourBall(CWnd* pParent = NULL);   // standard constructor
	~CDlgParamFourBall();
// Dialog Data
	//{{AFX_DATA(CDlgParamFourBall)
	enum { IDD = IDD_DLG_FOUR_BALL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgParamFourBall)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgParamFourBall)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickBtnSaveFourBall();
	afx_msg void OnClickBtnCancleFourBall();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG

private:
	CBrush m_brush;//刷背景色
	void InitParam();//初始化数据，在打开对话框时给编辑框负上值
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMFOURBALL_H__1D0A0496_DA68_4E9C_B334_CDA1E85D0167__INCLUDED_)
