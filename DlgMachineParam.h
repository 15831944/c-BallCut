#if !defined(AFX_DLGMACHINEPARAM_H__DDAE8B75_5442_4F62_872C_9556EBBE9C15__INCLUDED_)
#define AFX_DLGMACHINEPARAM_H__DDAE8B75_5442_4F62_872C_9556EBBE9C15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UniButton.h"
#include "DlgAdjust.h"
#include "EditDoubleClick.h"
#include "Dlg_KeyNumber.h"
// DlgMachineParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMachineParam dialog

class CDlgMachineParam : public CDialog
{
// Construction
public:
	CDlgMachineParam(CWnd* pParent = NULL);   // standard constructor
	~CDlgMachineParam();
	
	CBrush m_brush;
	double m_dKeyName[25];			//在INI文件中的键名
//////////////////////////////////////////////////////////////////////////

// Dialog Data
	//{{AFX_DATA(CDlgMachineParam)
	enum { IDD = IDD_DIALOG_MACHINE_PARAM };
	double	m_dHandAddA;
	double	m_dHandAddB;
	double	m_dHandAddC;
	double	m_dHandAddX;
	double	m_dHandAddY;
	double	m_dHandAddZ;
	double	m_dHandSpeedA;
	double	m_dHandSpeedB;
	double	m_dHandSpeedC;
	double	m_dHandSpeedX;
	double	m_dHandSpeedY;
	double	m_dHandSpeedZ;
	double	m_dHandSubA;
	double	m_dHandSubB;
	double	m_dHandSubC;
	double	m_dHandSubX;
	double	m_dHandSubY;
	double	m_dHandSubZ;
	double	m_dPulseB;
	double	m_dPulseC;
	double	m_dPulseX;
	double	m_dPulseY;
	double	m_dPulseZ;
	double	m_dPulseA;
	double	m_dZeroSpeedA;
	double	m_dZeroSpeedB;
	double	m_dZeroSpeedC;
	double	m_dZeroSpeedX;
	double	m_dZeroSpeedY;
	double	m_dZeroSpeedZ;
	long	m_lLimitFB;
	long	m_lLimitFC;
	long	m_lLimitFA;
	long	m_lLimitFX;
	long	m_lLimitFY;
	long	m_lLimitFZ;
	long	m_lLimitRA;
	long	m_lLimitRB;
	long	m_lLimitRC;
	long	m_lLimitRX;
	long	m_lLimitRY;
	long	m_lLimitRZ;
	double	m_dEditZeroOffSetA;
	double	m_dEditZeroOffSetB;
	double	m_dEditZeroOffSetC;
	double	m_dEditZeroOffSetY;
	double	m_dEditZeroOffSetZ;
	double	m_dEditZeroOffSetX;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMachineParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
protected:

	
	void InitData();				//打开工艺参数时读出参数
	void InitBtn();					//初始化主界面按钮

	// Generated message map functions
	//{{AFX_MSG(CDlgMachineParam)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnSaveM();				//按下保存按钮的函数
	afx_msg void OnBtnBackM();
	afx_msg void OnBtnAdjust();
	afx_msg LRESULT OnEditDouble(WPARAM wParam, LPARAM lParam);			//点编辑框时会发送是否弹触摸屏的消息
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CUniButton m_cBackM;
	CUniButton m_cSaveM;
	CUniButton m_cAdjust;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMACHINEPARAM_H__DDAE8B75_5442_4F62_872C_9556EBBE9C15__INCLUDED_)
