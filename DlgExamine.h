//{{AFX_INCLUDES()

//}}AFX_INCLUDES
#if !defined(AFX_DLGEXAMINE_H__BCE82897_4647_4D8A_96EB_6C7F193FB2EA__INCLUDED_)
#define AFX_DLGEXAMINE_H__BCE82897_4647_4D8A_96EB_6C7F193FB2EA__INCLUDED_
#include "displayctrl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UniButton.h"
//#include "AlarmDll.h"
// DlgExamine.h : header file
//
#define WM_UPDATEINPUT WM_USER+100			//诊断画面更新输入点WIN消息

/////////////////////////////////////////////////////////////////////////////
// CDlgExamine dialog

class CDlgExamine : public CDialog
{
// Construction
public:
	CDlgExamine(CWnd* pParent = NULL);   // standard constructor
	~CDlgExamine();
	CBrush m_brush;

	
	pPARAALARM		m_pRTAlarm;		/* 实时报警 */
	int				m_nAlarmCounts;	/* 实时报警计数 */
	pALARM			m_pHistoryAlarm;/* 历史报警 */
	
// Dialog Data
	//{{AFX_DATA(CDlgExamine)
	enum { IDD = IDD_DLG_EXAMINE };
	CListCtrl	m_listAlarm;
	CDisplayCtrl	m_ctlDisplayIn1;
	CDisplayCtrl	m_ctlDisplayIn2;
	CDisplayCtrl	m_ctlDisplayIn3;
	CDisplayCtrl	m_ctlDisplayOut1;
	CDisplayCtrl	m_ctlDisplayIn4;
	CDisplayCtrl	m_ctlDisplayIn5;
	CDisplayCtrl	m_ctlDisplayIn6;
	CDisplayCtrl	m_ctlDisplayOut2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgExamine)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
protected:
	
	void InitBtn();				//初始化主界面按钮
	void InitList();			//报警列表初始化
	void InitDisplay();			//初始化Display控件
	void ShowAlam(BOOL bCurrAlarm);	//显示报警函数


	//////////////////////////////////////////////////////////////////////////
	
	// Generated message map functions
	//{{AFX_MSG(CDlgExamine)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT UpdateInput(WPARAM wParam, LPARAM lParam);			//WIN消息，当输入点输入时，控件变化消息
	afx_msg void OnDblClickDisplayctrlctrlOut1();						//双击输出点
	afx_msg void OnBtnHistoryAlarm();	//历史报警按钮
	afx_msg void OnBtnBackE();			//返回按钮
	afx_msg void OnBtnAlam();			//查看报警按钮
	afx_msg void OnBtnIOput();			//IO点按钮
	afx_msg DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CUniButton m_cBackE;
	CUniButton m_cAlam;
	CUniButton m_cIOput;
	CUniButton m_cHistoryAlarm;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEXAMINE_H__BCE82897_4647_4D8A_96EB_6C7F193FB2EA__INCLUDED_)
