// DlgParamThreeBall.cpp : implementation file
//

#include "stdafx.h"
#include "ballcut.h"
#include "DlgParamThreeBall.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgParamThreeBall dialog


CDlgParamThreeBall::CDlgParamThreeBall(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgParamThreeBall::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgParamThreeBall)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));
	
}


CDlgParamThreeBall::~CDlgParamThreeBall()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}


void CDlgParamThreeBall::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgParamThreeBall)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgParamThreeBall, CDialog)
	//{{AFX_MSG_MAP(CDlgParamThreeBall)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgParamThreeBall message handlers

BEGIN_EVENTSINK_MAP(CDlgParamThreeBall, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgParamThreeBall)
	ON_EVENT(CDlgParamThreeBall, IDC_BTN_SAVE_THREE_BALL, -600 /* Click */, OnClickBtnSaveThreeBall, VTS_NONE)
	ON_EVENT(CDlgParamThreeBall, IDC_BTN_CANCLE_THREE_BALL, -600 /* Click */, OnClickBtnCancleThreeBall, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDlgParamThreeBall::OnClickBtnSaveThreeBall() 
{
	// TODO: Add your control notification handler code here
	CString l_strFlieName(FILE_PATH_OF_D);
	l_strFlieName = l_strFlieName + "3BallParam.ini";
	
	CString l_strDataName;			//保存用的中间数据一个是数据，一个是键名
	//赤道
	GetDlgItemText(IDC_EDIT_3EA,l_strDataName);
	WritePrivateProfileString("3BallParam","3EA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3EA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3EB,l_strDataName);
	WritePrivateProfileString("3BallParam","3EB",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3EB = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3EAA,l_strDataName);
	WritePrivateProfileString("3BallParam","3EAA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3EAA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3EBA,l_strDataName);
	WritePrivateProfileString("3BallParam","3EBA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3EBA = atof(l_strDataName);
	//极中
	GetDlgItemText(IDC_EDIT_3CA,l_strDataName);
	WritePrivateProfileString("3BallParam","3CA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3CA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3CB,l_strDataName);
	WritePrivateProfileString("3BallParam","3CB",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3CB = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3CG,l_strDataName);
	WritePrivateProfileString("3BallParam","3CG",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3CG = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3CBA,l_strDataName);
	WritePrivateProfileString("3BallParam","3CBA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3CBA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3CGA,l_strDataName);
	WritePrivateProfileString("3BallParam","3CGA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3CGA = atof(l_strDataName);
	//极边
	GetDlgItemText(IDC_EDIT_3SA,l_strDataName);
	WritePrivateProfileString("3BallParam","3SA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3SA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3SB,l_strDataName);
	WritePrivateProfileString("3BallParam","3SB",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3SB = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3SG,l_strDataName);
	WritePrivateProfileString("3BallParam","3SG",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3SG = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_3SAA,l_strDataName);
	WritePrivateProfileString("3BallParam","3SAA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamThreeBall.Ball3SAA = atof(l_strDataName);

	CDlgParamThreeBall::OnOK();	
}

/*
 *	初始化界面参数
 */
void CDlgParamThreeBall::InitParam()
{
	CString l_strFlieName(FILE_PATH_OF_D);
	l_strFlieName = l_strFlieName + "3BallParam.ini";
	char l_chDataName[30]={0};
	//赤道
	GetPrivateProfileString("3BallParam","3EA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3EA,l_chDataName);
	GetPrivateProfileString("3BallParam","3EB","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3EB,l_chDataName);
	GetPrivateProfileString("3BallParam","3EAA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3EAA,l_chDataName);
	GetPrivateProfileString("3BallParam","3EBA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3EBA,l_chDataName);
	//极中
	GetPrivateProfileString("3BallParam","3CA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3CA,l_chDataName);
	GetPrivateProfileString("3BallParam","3CB","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3CB,l_chDataName);
	GetPrivateProfileString("3BallParam","3CG","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3CG,l_chDataName);
	GetPrivateProfileString("3BallParam","3CBA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3CBA,l_chDataName);
	GetPrivateProfileString("3BallParam","3CGA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3CGA,l_chDataName);
	//极侧
	GetPrivateProfileString("3BallParam","3SA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3SA,l_chDataName);
	GetPrivateProfileString("3BallParam","3SB","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3SB,l_chDataName);
	GetPrivateProfileString("3BallParam","3SG","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3SG,l_chDataName);	
	GetPrivateProfileString("3BallParam","3SAA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_3SAA,l_chDataName);
}

void CDlgParamThreeBall::OnClickBtnCancleThreeBall() 
{
	// TODO: Add your control notification handler code here
	CDlgParamThreeBall::OnCancel();
}

BOOL CDlgParamThreeBall::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowPos(&CWnd::wndTop, 0, 0, 1024, 788, SWP_SHOWWINDOW);
	InitParam();//初始化界面参数
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDlgParamThreeBall::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
