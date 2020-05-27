#if !defined(AFX_DLGPARAMTHREEBALL_H__FFE54268_0C41_4487_BC62_10668836E79D__INCLUDED_)
#define AFX_DLGPARAMTHREEBALL_H__FFE54268_0C41_4487_BC62_10668836E79D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgParamThreeBall.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgParamThreeBall dialog

class CDlgParamThreeBall : public CDialog
{
// Construction
public:
	CDlgParamThreeBall(CWnd* pParent = NULL);   // standard constructor
	~CDlgParamThreeBall();
// Dialog Data
	//{{AFX_DATA(CDlgParamThreeBall)
	enum { IDD = IDD_DLG_THREE_BALL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgParamThreeBall)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgParamThreeBall)
	afx_msg void OnClickBtnSaveThreeBall();
	afx_msg void OnClickBtnCancleThreeBall();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG

private:
	CBrush m_brush;//刷背景色
	void InitParam();//初始化界面参数
	

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMTHREEBALL_H__FFE54268_0C41_4487_BC62_10668836E79D__INCLUDED_)
