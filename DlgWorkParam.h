//{{AFX_INCLUDES()
#include "btnctl.h"
//}}AFX_INCLUDES
#if !defined(AFX_DLGWORKPARAM_H__AED38496_729C_4105_8C5D_DA02B58A3164__INCLUDED_)
#define AFX_DLGWORKPARAM_H__AED38496_729C_4105_8C5D_DA02B58A3164__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UniButton.h"
#include "EditDoubleClick.h"
#include "Dlg_KeyNumber.h"
// DlgWorkParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgWorkParam dialog

class CDlgWorkParam : public CDialog
{
// Construction
public:
	CDlgWorkParam(CWnd* pParent = NULL);   // standard constructor
	~CDlgWorkParam();
	
	CBrush m_brush;
	double m_dKeyName[25];		//在INI文件中的键名

// Dialog Data
	//{{AFX_DATA(CDlgWorkParam)
	enum { IDD = IDD_DLG_WORK_PARAM };
	BOOL	m_ctlOrTouch;
	double	m_dBallRadius;
	double	m_dCutAdd;
	double	m_dCutSpeed;
	double	m_dCutSub;
	double	m_dThick;
	double	m_dBAuxRadius;
	double	m_dOverCut;
	double	m_dCenterOffset;
	double	m_dPOS400;
	double	m_dPOS3000;
	double	m_dPOS650;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgWorkParam)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgWorkParam)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnEditDouble(WPARAM wParam, LPARAM lParam);			//点编辑框时会发送是否弹触摸屏的消息
	afx_msg void OnBtnBackW();
	afx_msg void OnBtnSaveW();
	afx_msg void OnBtnMachineParam();		//打开机械参数对话框的按钮	
	afx_msg void InitData();				//打开工艺参数时读出参数
	afx_msg void InitBtn();				//初始化主界面按钮
	afx_msg void OnClickBtnThreeBall();
	afx_msg void OnClickBtnFoueBall();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDlgWorkParam)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	CUniButton m_cBackW;
	CUniButton m_cMachineParam;
	CUniButton m_cSaveW;


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWORKPARAM_H__AED38496_729C_4105_8C5D_DA02B58A3164__INCLUDED_)
