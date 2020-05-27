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
#define WM_UPDATEINPUT WM_USER+100			//��ϻ�����������WIN��Ϣ

/////////////////////////////////////////////////////////////////////////////
// CDlgExamine dialog

class CDlgExamine : public CDialog
{
// Construction
public:
	CDlgExamine(CWnd* pParent = NULL);   // standard constructor
	~CDlgExamine();
	CBrush m_brush;

	
	pPARAALARM		m_pRTAlarm;		/* ʵʱ���� */
	int				m_nAlarmCounts;	/* ʵʱ�������� */
	pALARM			m_pHistoryAlarm;/* ��ʷ���� */
	
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
	
	void InitBtn();				//��ʼ�������水ť
	void InitList();			//�����б��ʼ��
	void InitDisplay();			//��ʼ��Display�ؼ�
	void ShowAlam(BOOL bCurrAlarm);	//��ʾ��������


	//////////////////////////////////////////////////////////////////////////
	
	// Generated message map functions
	//{{AFX_MSG(CDlgExamine)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT UpdateInput(WPARAM wParam, LPARAM lParam);			//WIN��Ϣ�������������ʱ���ؼ��仯��Ϣ
	afx_msg void OnDblClickDisplayctrlctrlOut1();						//˫�������
	afx_msg void OnBtnHistoryAlarm();	//��ʷ������ť
	afx_msg void OnBtnBackE();			//���ذ�ť
	afx_msg void OnBtnAlam();			//�鿴������ť
	afx_msg void OnBtnIOput();			//IO�㰴ť
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
