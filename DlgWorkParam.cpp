// DlgWorkParam.cpp : implementation file
//

#include "stdafx.h"
#include "BallCut.h"
#include "BallCutDlg.h"
#include "DlgWorkParam.h"
#include "DlgMachineParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgWorkParam dialog


CDlgWorkParam::CDlgWorkParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgWorkParam::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CDlgWorkParam)
	m_ctlOrTouch = FALSE;
	m_dBallRadius = 0.0;
	m_dCutAdd = 0.0;
	m_dCutSpeed = 0.0;
	m_dCutSub = 0.0;
	m_dThick = 0.0;
	m_dBAuxRadius = 0.0;
	m_dOverCut = 0.0;
	m_dCenterOffset = 0.0;
	m_dPOS400 = 0.0;
	m_dPOS3000 = 0.0;
	m_dPOS650 = 0.0;
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));   //控件背景色的刷子
}

CDlgWorkParam::~CDlgWorkParam()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}

void CDlgWorkParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgWorkParam)
	DDX_Check(pDX, IDC_CHECK_OR_TOUCH, m_ctlOrTouch);
	DDX_Text(pDX, IDC_EDIT_BALL_RADIUS, m_dBallRadius);
	DDX_Text(pDX, IDC_EDIT_CUT_ADD, m_dCutAdd);
	DDX_Text(pDX, IDC_EDIT_CUT_SPEED, m_dCutSpeed);
	DDX_Text(pDX, IDC_EDIT_CUT_SUB, m_dCutSub);
	DDX_Text(pDX, IDC_EDIT_THICK, m_dThick);
	DDX_Text(pDX, IDC_EDIT_BAUX_RADIUS, m_dBAuxRadius);
	DDX_Text(pDX, IDC_EDIT_OVER_CUT, m_dOverCut);
	DDX_Text(pDX, IDC_EDIT_CENTER_OFFSET, m_dCenterOffset);
	DDX_Text(pDX, IDC_EDIT_POS_400, m_dPOS400);
	DDX_Text(pDX, IDC_EDIT_POS_3000, m_dPOS3000);
	DDX_Text(pDX, IDC_EDIT_POS_650, m_dPOS650);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgWorkParam, CDialog)
	//{{AFX_MSG_MAP(CDlgWorkParam)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_BACKW, OnBtnBackW)
	ON_BN_CLICKED(IDC_BTN_SAVEW, OnBtnSaveW)
	ON_BN_CLICKED(IDC_BTN_MACHINE_PARAM, OnBtnMachineParam)
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_EDITDOUBLE,OnEditDouble)					//系统消息	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDlgWorkParam, CDialog)
	//{{AFX_DISPATCH_MAP(CDlgWorkParam)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDlgWorkParam to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {6460DA60-27E7-4076-B481-B924898774B9}
static const IID IID_IDlgWorkParam =
{ 0x6460da60, 0x27e7, 0x4076, { 0xb4, 0x81, 0xb9, 0x24, 0x89, 0x87, 0x74, 0xb9 } };

BEGIN_INTERFACE_MAP(CDlgWorkParam, CDialog)
	INTERFACE_PART(CDlgWorkParam, IID_IDlgWorkParam, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgWorkParam message handlers

void CDlgWorkParam::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDC  MemDc;
	CBitmap bitmap;	
	MemDc.CreateCompatibleDC(&dc);
	bitmap.LoadBitmap(IDB_BITMAP_DIALOG);
	CBitmap *pOldBit = MemDc.SelectObject(&bitmap);
	dc.BitBlt(0,0,1024,768,&MemDc,0,0,SRCCOPY);
	MemDc.SelectObject(pOldBit);
	bitmap.DeleteObject();
	MemDc.DeleteDC();
	CDialog::OnPaint();	
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CDlgWorkParam::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowPos(&CWnd::wndTop, 0, 0, 1024, 788, SWP_SHOWWINDOW);
	InitBtn();				//初始化主界面按钮
	InitData();				//读取参数的函数

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*
 *	初始化主界面按钮和静态控件字体大小
 */
void CDlgWorkParam::InitBtn()
{
	HRGN c;
	c = CreateRectRgn(0, 0, 0, 0);
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_MACHINE_PARAM1);	
	//机械参数
	m_cMachineParam.SetFont(&g_cFontEdit);
	m_cMachineParam.SetBitMapID(IDB_BITMAP_MACHINE_PARAM1,IDB_BITMAP_MACHINE_PARAM2);	
	m_cMachineParam.Create("机械参数", WS_CHILD | WS_VISIBLE, CPoint(537, 714), c, this,IDC_BTN_MACHINE_PARAM); 
	//保存
	m_cSaveW.SetFont(&g_cFontEdit);
	m_cSaveW.SetBitMapID(IDB_BITMAP_SAVE1,IDB_BITMAP_SAVE2);	
	m_cSaveW.Create("保存", WS_CHILD | WS_VISIBLE, CPoint(707, 714), c, this, IDC_BTN_SAVEW); 
	//返回
	m_cBackW.SetFont(&g_cFontEdit);
	m_cBackW.SetBitMapID(IDB_BITMAP_BACK1,IDB_BITMAP_BACK2);	
	m_cBackW.Create("返回", WS_CHILD | WS_VISIBLE, CPoint(877, 714), c, this, IDC_BTN_BACKW); 
	DeleteObject(c);
	//初始化静态控件的字体
/*
	for(int i=1065;i<1079;i++)			//让工艺参数界面的静态控件的底色跟窗口色一样
	{
		GetDlgItem(i)->SetFont(&g_cFontStatic);
	}	
*/
}

/*
 *	返回按键
 */
void CDlgWorkParam::OnBtnBackW()
{
	CDlgWorkParam::OnOK();
}

/*
 *	打开机械参数对话框
 */
void CDlgWorkParam::OnBtnMachineParam()
{
	CDlgMachineParam OpenDlg;
	OpenDlg.DoModal();
}

/*
 *	打开三个壳的球参数对话框
 */
/*
void CDlgWorkParam::OnBtnOpenThreeBall()
{

}
*/

/*
 *	打开四个壳的球参数对话框
 */
/*
void CDlgWorkParam::OnBtnOpenFourBall()
{

}
*/

/*
 *	保存按键
 */
void CDlgWorkParam::OnBtnSaveW()
{
	CString l_strDataName;			//保存用的中间数据一个是数据，一个是键名
	GetDlgItemText(IDC_EDIT_THICK,l_strDataName);
	WritePrivateProfileString("WorkParam","THICK",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_BALL_RADIUS,l_strDataName);
	WritePrivateProfileString("WorkParam","BALL_RADIUS",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_CUT_SPEED,l_strDataName);
	WritePrivateProfileString("WorkParam","CUT_SPEED",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_CUT_ADD,l_strDataName);
	WritePrivateProfileString("WorkParam","CUT_ADD",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_CUT_SUB,l_strDataName);
	WritePrivateProfileString("WorkParam","CUT_SUB",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_BAUX_RADIUS,l_strDataName);
	WritePrivateProfileString("WorkParam","BAuxRadius",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_OVER_CUT,l_strDataName);
	WritePrivateProfileString("WorkParam","OverCut",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_CENTER_OFFSET,l_strDataName);
	WritePrivateProfileString("WorkParam","CenterOffSet",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");

	GetDlgItemText(IDC_EDIT_POS_400,l_strDataName);
	WritePrivateProfileString("WorkParam","Postion400",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_POS_650,l_strDataName);
	WritePrivateProfileString("WorkParam","Postion650",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	GetDlgItemText(IDC_EDIT_POS_3000,l_strDataName);
	WritePrivateProfileString("WorkParam","Postion3000",l_strDataName,"D:\\Program Files\\BallCut\\WorkParam.ini");
	
	UpdateData(TRUE);
	g_ctlOrTouch = m_ctlOrTouch;
	g_dThick =	m_dThick;
	g_dBallRadius =	m_dBallRadius;
	g_dCutAdd =	m_dCutAdd;
	g_dCutSpeed = m_dCutSpeed;
	g_dCutSub =	m_dCutSub;
	g_dBigShakeRadiuas = m_dBAuxRadius;
	g_pMainDlg->m_stcParamWork.OverCut = m_dOverCut;
	g_pMainDlg->m_stcParamWork.CenterOffset = m_dCenterOffset;
	g_pMainDlg->m_stcParamWork.Position400 = m_dPOS400;
	g_pMainDlg->m_stcParamWork.Position650 = m_dPOS650;
	g_pMainDlg->m_stcParamWork.Position3000 = m_dPOS3000;
	
	CDlgWorkParam::OnOK();
}

/*
 *	读取参数函数
 */
void CDlgWorkParam::InitData()
{
	 m_ctlOrTouch = g_ctlOrTouch;
	 m_dThick =	g_dThick;
	 m_dBallRadius =	g_dBallRadius;
	 m_dCutAdd =	g_dCutAdd;
	 m_dCutSpeed =	g_dCutSpeed;
	 m_dCutSub =	g_dCutSub;
	 m_dBAuxRadius = g_dBigShakeRadiuas ;
	 m_dOverCut = g_pMainDlg->m_stcParamWork.OverCut;
	 m_dCenterOffset = g_pMainDlg->m_stcParamWork.CenterOffset;
	 m_dPOS400 = g_pMainDlg->m_stcParamWork.Position400;
	 m_dPOS650 = g_pMainDlg->m_stcParamWork.Position650;
	 m_dPOS3000 = g_pMainDlg->m_stcParamWork.Position3000;
	 UpdateData(FALSE);	
}

HBRUSH CDlgWorkParam::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
 *	触摸屏WIN消息函数触发
 */
LRESULT CDlgWorkParam::OnEditDouble(WPARAM wParam, LPARAM lParam) 
{
	CString				strTmp;
	CDlg_KeyNumber		KeyNum;
	
	if(lParam==1)/* 无触摸屏 */
	{
		((CEdit *)GetDlgItem(wParam))->SetSel(0,-1);
		return 0;
	}
	
	CWnd::GetDlgItemText(wParam,strTmp);
	KeyNum.m_strNew = KeyNum.m_strOld = strTmp;
	
	if(KeyNum.DoModal()==IDOK)
		CWnd::SetDlgItemText(wParam,KeyNum.m_strNew);
	
	return 0;
}

BEGIN_EVENTSINK_MAP(CDlgWorkParam, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgWorkParam)
	ON_EVENT(CDlgWorkParam, IDC_BTN_THREE_BALL, -600 /* Click */, OnClickBtnThreeBall, VTS_NONE)
	ON_EVENT(CDlgWorkParam, IDC_BTN_FOUE_BALL, -600 /* Click */, OnClickBtnFoueBall, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDlgWorkParam::OnClickBtnThreeBall() 
{
	// TODO: Add your control notification handler code here
	CDlgParamThreeBall dlg;
	dlg.DoModal();
}

void CDlgWorkParam::OnClickBtnFoueBall() 
{
	// TODO: Add your control notification handler code here
	CDlgParamFourBall dlg;
	dlg.DoModal();
}
