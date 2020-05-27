#if !defined(AFX_DLGHAND_H__760D8AAA_F4E5_41CB_A0B5_52EAFB3D231C__INCLUDED_)
#define AFX_DLGHAND_H__760D8AAA_F4E5_41CB_A0B5_52EAFB3D231C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UniButton.h"
#include "EditDoubleClick.h"
#include "Dlg_KeyNumber.h"
// DlgHand.h : header file
//
#define   WM_MOUSEDN     WM_USER+100		//鼠标按下时发送的消息
/////////////////////////////////////////////////////////////////////////////
// CDlgHand dialog

class CDlgHand : public CDialog
{
// Construction
public:

	CDlgHand(CWnd* pParent = NULL);   // standard constructor
	~CDlgHand();
	CBrush m_brush;

// Dialog Data
	//{{AFX_DATA(CDlgHand)
	enum { IDD = IDD_DLG_HAND };
	CEditDoubleClick	m_ctlPRZ;
	CEditDoubleClick	m_ctlPRY;
	CEditDoubleClick	m_ctlPRX;
	CEditDoubleClick	m_ctlPRC;
	CEditDoubleClick	m_ctlPRB;
	CEditDoubleClick	m_ctlPRA;
	CUniButton m_cHandXF;
	CUniButton m_cHandXR;
	CUniButton m_cHandYF;
	CUniButton m_cHandYR;
	CUniButton m_cHandZF;
	CUniButton m_cHandZR;
	CUniButton m_cHandAF;
	CUniButton m_cHandAR;
	CUniButton m_cHandBF;
	CUniButton m_cHandBR;
	CUniButton m_cHandCF;
	CUniButton m_cHandCR;
	CUniButton m_cHandMotionStyle;
	CUniButton m_cHandBegan;
	CUniButton m_cHandStop;
	double	m_dPRA;
	double	m_dPRB;
	double	m_dPRC;
	double	m_dPRX;
	double	m_dPRY;
	double	m_dPRZ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgHand)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InitBtn();					//初始化按钮
	void InitData();				//初始化手动按钮界面的数据

	// Generated message map functions
	//{{AFX_MSG(CDlgHand)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnHandXF();
	afx_msg void OnBtnHandXR();
	afx_msg void OnBtnHandYF();
	afx_msg void OnBtnHandYR();
	afx_msg void OnBtnHandZF();
	afx_msg void OnBtnHandZR();
	afx_msg void OnBtnHandAF();
	afx_msg void OnBtnHandAR();
	afx_msg void OnBtnHandBF();
	afx_msg void OnBtnHandBR();
	afx_msg void OnBtnHandCF();
	afx_msg void OnBtnHandCR();
	afx_msg void OnBtnHandMotionStyle();
	afx_msg void OnBtnHandBagen();
	afx_msg void OnBtnHandStop();
	afx_msg LRESULT OnMouseDn(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEditDouble(WPARAM wParam, LPARAM lParam);			//点编辑框时会发送是否弹触摸屏的消息
	
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int l_iHandMotionStyle;		//手动界面里1：0.1）2：1）3：5）4：10）5：连续）	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGHAND_H__760D8AAA_F4E5_41CB_A0B5_52EAFB3D231C__INCLUDED_)
