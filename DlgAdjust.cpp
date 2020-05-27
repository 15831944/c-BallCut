// DlgAdjust.cpp : implementation file
//

#include "stdafx.h"
#include "ballcut.h"
#include "DlgAdjust.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAdjust dialog


CDlgAdjust::CDlgAdjust(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdjust::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAdjust)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));
	
}

CDlgAdjust::~CDlgAdjust()
{

}

void CDlgAdjust::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAdjust)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAdjust, CDialog)
	//{{AFX_MSG_MAP(CDlgAdjust)
	ON_BN_CLICKED(IDC_BTN_ADJUST_BEGAN, OnBtnAdjustBegan)
	ON_BN_CLICKED(IDC_BTN_ADJUST_BACK, OnBtnAdjustBack)
	ON_BN_CLICKED(IDC_BTN_ADJUST_STOP, OnBtnAdjustStop)
	ON_BN_CLICKED(IDC_BTN_ADJUST_SET, OnBtnAdjustSet)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAdjust message handlers

void CDlgAdjust::OnBtnAdjustBegan() 
{
	// TODO: Add your control notification handler code here
	g_cController.DownloadFile("F:\\BallCut\\Adjust.dmc");
	Sleep(100);
	g_cController.Command("XQ");
}

void CDlgAdjust::OnBtnAdjustBack() 
{
	// TODO: Add your control notification handler code here
	CDlgAdjust::OnOK();
	
}

void CDlgAdjust::OnBtnAdjustStop() 
{
	// TODO: Add your control notification handler code here
	g_cController.Command("ST");
	Sleep(40);
	g_cController.Command("STXYZWEFG");	
}

void CDlgAdjust::OnBtnAdjustSet() 
{
	// TODO: Add your control notification handler code here
	char l_cDmcResponse[15]={0};
	int l_iResult;
	CString l_strResult;
	g_cController.Command("TPG",l_cDmcResponse,sizeof(l_cDmcResponse));
	l_iResult = atoi(l_cDmcResponse);
	l_strResult.Format("%d",l_iResult);
	WritePrivateProfileString("AdjustParam","M1",l_strResult,	\
		"D:\\Program Files\\BallCut\\AdjustParam.ini");
}

HBRUSH CDlgAdjust::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if (nCtlColor==CTLCOLOR_DLG || nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)m_brush.GetSafeHandle();
	}	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgAdjust::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (1 == nIDEvent) 
	{
		CString l_strResult;
		char l_cDmcResponse[15]={0};
		g_cController.Command("TPA",l_cDmcResponse,sizeof(l_cDmcResponse));
		SetDlgItemText(IDC_STATIC_GMTPX,l_cDmcResponse);
		g_cController.Command("TPG",l_cDmcResponse,sizeof(l_cDmcResponse));
		SetDlgItemText(IDC_STATIC_GMTPG,l_cDmcResponse);

	}
	CDialog::OnTimer(nIDEvent);
}

BOOL CDlgAdjust::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
