// DlgParamFourBall.cpp : implementation file
//

#include "stdafx.h"
#include "ballcut.h"
#include "DlgParamFourBall.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgParamFourBall dialog


CDlgParamFourBall::CDlgParamFourBall(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgParamFourBall::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgParamFourBall)
		// NOTE: the ClassWizard will add member initialization here
	m_brush.CreateSolidBrush(RGB(203,211,237));
	//}}AFX_DATA_INIT
	
}

CDlgParamFourBall::~CDlgParamFourBall()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}

void CDlgParamFourBall::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgParamFourBall)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgParamFourBall, CDialog)
	//{{AFX_MSG_MAP(CDlgParamFourBall)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgParamFourBall message handlers

BOOL CDlgParamFourBall::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowPos(&CWnd::wndTop, 0, 0, 1024, 788, SWP_SHOWWINDOW);
	InitParam();//给界面上的编辑框负上值
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_EVENTSINK_MAP(CDlgParamFourBall, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgParamFourBall)
	ON_EVENT(CDlgParamFourBall, IDC_BTN_SAVE_FOUR_BALL, -600 /* Click */, OnClickBtnSaveFourBall, VTS_NONE)
	ON_EVENT(CDlgParamFourBall, IDC_BTN_CANCLE_FOUR_BALL, -600 /* Click */, OnClickBtnCancleFourBall, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDlgParamFourBall::OnClickBtnSaveFourBall() 
{
	// TODO: Add your control notification handler code here
	CString l_strFlieName(FILE_PATH_OF_D);
	l_strFlieName = l_strFlieName + "4BallParam.ini";
	
	CString l_strDataName;			//保存用的中间数据一个是数据，一个是键名
	//赤道
	GetDlgItemText(IDC_EDIT_4EA,l_strDataName);
	WritePrivateProfileString("4BallParam","4EA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EG,l_strDataName);
	WritePrivateProfileString("4BallParam","4EG",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EG = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EAA,l_strDataName);
	WritePrivateProfileString("4BallParam","4EAA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EAA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EGA,l_strDataName);
	WritePrivateProfileString("4BallParam","4EGA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EGA = atof(l_strDataName);
	//极中
	GetDlgItemText(IDC_EDIT_4CA,l_strDataName);
	WritePrivateProfileString("4BallParam","4CA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4CA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4CG,l_strDataName);
	WritePrivateProfileString("4BallParam","4CG",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4CG = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4CAA,l_strDataName);
	WritePrivateProfileString("4BallParam","4CAA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4CAA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4CGA,l_strDataName);
	WritePrivateProfileString("4BallParam","4CGA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4CGA = atof(l_strDataName);
	//极侧
	GetDlgItemText(IDC_EDIT_4EDA,l_strDataName);
	WritePrivateProfileString("4BallParam","4EDA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EDA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EDG,l_strDataName);
	WritePrivateProfileString("4BallParam","4EDG",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EDG = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EDE,l_strDataName);
	WritePrivateProfileString("4BallParam","4EDE",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EDE = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EDAA,l_strDataName);
	WritePrivateProfileString("4BallParam","4EDAA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EDAA = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EDGA,l_strDataName);
	WritePrivateProfileString("4BallParam","4EDGA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EDGA = atof(l_strDataName);
	//极侧
	GetDlgItemText(IDC_EDIT_4SG,l_strDataName);
	WritePrivateProfileString("4BallParam","4SG",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4SG = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4SB,l_strDataName);
	WritePrivateProfileString("4BallParam","4SB",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4SB = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4SE,l_strDataName);
	WritePrivateProfileString("4BallParam","4SE",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4SE = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4EDB,l_strDataName);
	WritePrivateProfileString("4BallParam","4EDB",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4EDB = atof(l_strDataName);
	GetDlgItemText(IDC_EDIT_4SGA,l_strDataName);
	WritePrivateProfileString("4BallParam","4SGA",l_strDataName,l_strFlieName);
	g_pMainDlg->m_stcParamFourBall.Ball4SGA = atof(l_strDataName);
	
	CDlgParamFourBall::OnOK();
}

void CDlgParamFourBall::OnClickBtnCancleFourBall() 
{
	// TODO: Add your control notification handler code here

	CDlgParamFourBall::OnCancel();
	
}

HBRUSH CDlgParamFourBall::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

/*
 *	初始化数据 
 */
void CDlgParamFourBall::InitParam()
{
	CString l_strFlieName(FILE_PATH_OF_D);
	l_strFlieName = l_strFlieName + "4BallParam.ini";
	char l_chDataName[30]={0};
	//赤道
	GetPrivateProfileString("4BallParam","4EA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EA,l_chDataName);
	GetPrivateProfileString("4BallParam","4EG","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EG,l_chDataName);
	GetPrivateProfileString("4BallParam","4EAA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EAA,l_chDataName);
	GetPrivateProfileString("4BallParam","4EGA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EGA,l_chDataName);
	//极中
	GetPrivateProfileString("4BallParam","4CA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4CA,l_chDataName);
	GetPrivateProfileString("4BallParam","4CG","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4CG,l_chDataName);
	GetPrivateProfileString("4BallParam","4CAA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4CAA,l_chDataName);
	GetPrivateProfileString("4BallParam","4CGA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4CGA,l_chDataName);
	//极侧
	GetPrivateProfileString("4BallParam","4EDA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EDA,l_chDataName);
	GetPrivateProfileString("4BallParam","4EDG","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EDG,l_chDataName);
	GetPrivateProfileString("4BallParam","4EDE","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EDE,l_chDataName);
	GetPrivateProfileString("4BallParam","4EDAA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EDAA,l_chDataName);	
	GetPrivateProfileString("4BallParam","4EDGA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EDGA,l_chDataName);	
	//极侧
	GetPrivateProfileString("4BallParam","4SG","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4SG,l_chDataName);
	GetPrivateProfileString("4BallParam","4SB","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4SB,l_chDataName);
	GetPrivateProfileString("4BallParam","4SE","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4SE,l_chDataName);
	GetPrivateProfileString("4BallParam","4EDB","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4EDB,l_chDataName);	
	GetPrivateProfileString("4BallParam","4SGA","-1",l_chDataName,20,l_strFlieName);
	SetDlgItemText(IDC_EDIT_4SGA,l_chDataName);
}