// DlgMachineParam.cpp : implementation file
//

#include "stdafx.h"
#include "BallCut.h"
#include "BallCutDlg.h"
#include "DlgMachineParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMachineParam dialog


CDlgMachineParam::CDlgMachineParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMachineParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMachineParam)
	m_lLimitFB = 0;
	m_lLimitFC = 0;
	m_lLimitFA = 0;
	m_lLimitFX = 0;
	m_lLimitFY = 0;
	m_lLimitFZ = 0;
	m_lLimitRA = 0;
	m_lLimitRB = 0;
	m_lLimitRC = 0;
	m_lLimitRX = 0;
	m_lLimitRY = 0;
	m_lLimitRZ = 0;
	m_dEditZeroOffSetA = 0.0;
	m_dEditZeroOffSetB = 0.0;
	m_dEditZeroOffSetC = 0.0;
	m_dEditZeroOffSetY = 0.0;
	m_dEditZeroOffSetZ = 0.0;
	m_dEditZeroOffSetX = 0.0;
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));   //控件背景色的刷子
}

CDlgMachineParam::~CDlgMachineParam()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}
void CDlgMachineParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMachineParam)
	DDX_Text(pDX, IDC_EDIT_HAND_ADDA, m_dHandAddA);
	DDX_Text(pDX, IDC_EDIT_HAND_ADDB, m_dHandAddB);
	DDX_Text(pDX, IDC_EDIT_HAND_ADDC, m_dHandAddC);
	DDX_Text(pDX, IDC_EDIT_HAND_ADDX, m_dHandAddX);
	DDX_Text(pDX, IDC_EDIT_HAND_ADDY, m_dHandAddY);
	DDX_Text(pDX, IDC_EDIT_HAND_ADDZ, m_dHandAddZ);
	DDX_Text(pDX, IDC_EDIT_HAND_SPEEDA, m_dHandSpeedA);
	DDX_Text(pDX, IDC_EDIT_HAND_SPEEDB, m_dHandSpeedB);
	DDX_Text(pDX, IDC_EDIT_HAND_SPEEDC, m_dHandSpeedC);
	DDX_Text(pDX, IDC_EDIT_HAND_SPEEDX, m_dHandSpeedX);
	DDX_Text(pDX, IDC_EDIT_HAND_SPEEDY, m_dHandSpeedY);
	DDX_Text(pDX, IDC_EDIT_HAND_SPEEDZ, m_dHandSpeedZ);
	DDX_Text(pDX, IDC_EDIT_HAND_SUBA, m_dHandSubA);
	DDX_Text(pDX, IDC_EDIT_HAND_SUBB, m_dHandSubB);
	DDX_Text(pDX, IDC_EDIT_HAND_SUBC, m_dHandSubC);
	DDX_Text(pDX, IDC_EDIT_HAND_SUBX, m_dHandSubX);
	DDX_Text(pDX, IDC_EDIT_HAND_SUBY, m_dHandSubY);
	DDX_Text(pDX, IDC_EDIT_HAND_SUBZ, m_dHandSubZ);
	DDX_Text(pDX, IDC_EDIT_PULSEB, m_dPulseB);
	DDX_Text(pDX, IDC_EDIT_PULSEC, m_dPulseC);
	DDX_Text(pDX, IDC_EDIT_PULSEX, m_dPulseX);
	DDX_Text(pDX, IDC_EDIT_PULSEY, m_dPulseY);
	DDX_Text(pDX, IDC_EDIT_PULSEZ, m_dPulseZ);
	DDX_Text(pDX, IDC_EDIT_PULSEA, m_dPulseA);
	DDX_Text(pDX, IDC_EDIT_ZERO_SPEEDA, m_dZeroSpeedA);
	DDX_Text(pDX, IDC_EDIT_ZERO_SPEEDB, m_dZeroSpeedB);
	DDX_Text(pDX, IDC_EDIT_ZERO_SPEEDC, m_dZeroSpeedC);
	DDX_Text(pDX, IDC_EDIT_ZERO_SPEEDX, m_dZeroSpeedX);
	DDX_Text(pDX, IDC_EDIT_ZERO_SPEEDY, m_dZeroSpeedY);
	DDX_Text(pDX, IDC_EDIT_ZERO_SPEEDZ, m_dZeroSpeedZ);
	DDX_Text(pDX, IDC_EDIT_LIMITFB, m_lLimitFB);
	DDX_Text(pDX, IDC_EDIT_LIMITFC, m_lLimitFC);
	DDX_Text(pDX, IDC_EDIT_LIMITFA, m_lLimitFA);
	DDX_Text(pDX, IDC_EDIT_LIMITFX, m_lLimitFX);
	DDX_Text(pDX, IDC_EDIT_LIMITFY, m_lLimitFY);
	DDX_Text(pDX, IDC_EDIT_LIMITFZ, m_lLimitFZ);
	DDX_Text(pDX, IDC_EDIT_LIMITRA, m_lLimitRA);
	DDX_Text(pDX, IDC_EDIT_LIMITRB, m_lLimitRB);
	DDX_Text(pDX, IDC_EDIT_LIMITRC, m_lLimitRC);
	DDX_Text(pDX, IDC_EDIT_LIMITRX, m_lLimitRX);
	DDX_Text(pDX, IDC_EDIT_LIMITRY, m_lLimitRY);
	DDX_Text(pDX, IDC_EDIT_LIMITRZ, m_lLimitRZ);
	DDX_Text(pDX, IDC_EDIT_ZORE_OFFSETA, m_dEditZeroOffSetA);
	DDX_Text(pDX, IDC_EDIT_ZORE_OFFSETB, m_dEditZeroOffSetB);
	DDX_Text(pDX, IDC_EDIT_ZORE_OFFSETC, m_dEditZeroOffSetC);
	DDX_Text(pDX, IDC_EDIT_ZORE_OFFSETY, m_dEditZeroOffSetY);
	DDX_Text(pDX, IDC_EDIT_ZORE_OFFSETZ, m_dEditZeroOffSetZ);
	DDX_Text(pDX, IDC_EDIT_ZORE_OFFSETX, m_dEditZeroOffSetX);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMachineParam, CDialog)
	//{{AFX_MSG_MAP(CDlgMachineParam)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_BACKM,OnBtnBackM)
	ON_BN_CLICKED(IDC_BTN_SAVEM,OnBtnSaveM)
//	ON_BN_CLICKED(IDC_BTN_ADJUST,OnBtnAdjust)
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_EDITDOUBLE,OnEditDouble)					//系统消息
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMachineParam message handlers

void CDlgMachineParam::OnPaint() 
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

BOOL CDlgMachineParam::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowPos(&CWnd::wndTop, 0, 0, 1024, 788, SWP_SHOWWINDOW);
	InitBtn();					//初始化主界面按钮
	InitData();				//打开机械参数界面时读取参数的函数

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMachineParam::InitBtn()
{
	HRGN c;	
	c = CreateRectRgn(0, 0, 0, 0);
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_BACK2);		
	//返回
	m_cBackM.SetFont(&g_cFontEdit);
	m_cBackM.SetBitMapID(IDB_BITMAP_BACK1,IDB_BITMAP_BACK2);	
	m_cBackM.Create("返回", WS_CHILD | WS_VISIBLE, CPoint(877, 714), c, this, IDC_BTN_BACKM); 
	//保存
	m_cSaveM.SetFont(&g_cFontEdit);
	m_cSaveM.SetBitMapID(IDB_BITMAP_SAVE1,IDB_BITMAP_SAVE2);	
	m_cSaveM.Create("保存", WS_CHILD | WS_VISIBLE, CPoint(707, 714), c, this, IDC_BTN_SAVEM);
	//龙门校正
//	m_cAdjust.SetFont(&g_cFontEdit);
//	m_cAdjust.SetBitMapID(IDB_BITMAP_ADJUST1,IDB_BITMAP_ADJUST2);	
//	m_cAdjust.Create("龙门校正", WS_CHILD | WS_VISIBLE, CPoint(537, 714), c, this, IDC_BTN_ADJUST);
	
	DeleteObject(c);
	//初始化静态控件的字体
/*
		for(int i=1064;i<1080;i++)		//让机械参数界面的静态控件的底色跟窗口色一样
		{
			GetDlgItem(i)->SetFont(&g_cFontStatic);
		}*/
	
}

/*
*	反回按钮的函数
*/
void CDlgMachineParam::OnBtnBackM()
{
	CDlgMachineParam::OnOK();
}


/*
*	龙门校正按钮的函数
*/
void CDlgMachineParam::OnBtnAdjust()
{
	CDlgAdjust OpenDlg;
	OpenDlg.DoModal();
}

/*
 *	保存按钮的函数
 */
void CDlgMachineParam::OnBtnSaveM()
{
	CString l_strDataName,l_strKeyName;			//保存用的中间数据一个是数据，一个是键名
	for(int i=1015;i<1065;i++)
	{
		l_strKeyName.Format("m_dKeyName[%d]",i);
		GetDlgItemText(i,l_strDataName);
		WritePrivateProfileString("MachineParam",l_strKeyName,l_strDataName,	\
			"D:\\Program Files\\BallCut\\MachineParam.ini");
	}
	UpdateData(TRUE);	
	g_dHandAddA = m_dHandAddA;
	g_dHandAddB = m_dHandAddB;
	g_dHandAddC = m_dHandAddC;
	g_dHandAddX = m_dHandAddX;
	g_dHandAddY = m_dHandAddY;
	g_dHandAddZ = m_dHandAddZ;
	g_dHandSpeedA =	m_dHandSpeedA;
	g_dHandSpeedB = m_dHandSpeedB;
	g_dHandSpeedC = m_dHandSpeedC;
	g_dHandSpeedX =	m_dHandSpeedX;
	g_dHandSpeedY = m_dHandSpeedY;
	g_dHandSpeedZ = m_dHandSpeedZ;
	g_dHandSubA = m_dHandSubA;
	g_dHandSubB = m_dHandSubB;
	g_dHandSubC = m_dHandSubC;
	g_dHandSubX = m_dHandSubX;
	g_dHandSubY = m_dHandSubY;
	g_dHandSubZ = m_dHandSubZ;
	g_lLimitFB = m_lLimitFB;
	g_lLimitFC = m_lLimitFC;
	g_lLimitFA = m_lLimitFA;
	g_lLimitFX = m_lLimitFX;
	g_lLimitFY = m_lLimitFY;
	g_lLimitFZ = m_lLimitFZ;
	g_lLimitRA = m_lLimitRA;
	g_lLimitRB = m_lLimitRB;
	g_lLimitRC = m_lLimitRC;
	g_lLimitRX = m_lLimitRX;
	g_lLimitRY = m_lLimitRY;
	g_lLimitRZ = m_lLimitRZ;
	g_dPulseB = m_dPulseB;
	g_dPulseC = m_dPulseC;
	g_dPulseX = m_dPulseX;
	g_dPulseY = m_dPulseY;
	g_dPulseZ = m_dPulseZ;
	g_dPulseA = m_dPulseA;
	g_dZeroSpeedA = m_dZeroSpeedA;
	g_dZeroSpeedB = m_dZeroSpeedB;
	g_dZeroSpeedC = m_dZeroSpeedC;
	g_dZeroSpeedX = m_dZeroSpeedX;
	g_dZeroSpeedY = m_dZeroSpeedY;
	g_dZeroSpeedZ =	m_dZeroSpeedZ;

	g_dZeroOffsetA = m_dEditZeroOffSetA;
	g_dZeroOffsetB = m_dEditZeroOffSetB;
	g_dZeroOffsetC = m_dEditZeroOffSetC;
	g_dZeroOffsetX = m_dEditZeroOffSetX;
	g_dZeroOffsetY = m_dEditZeroOffSetY;
	g_dZeroOffsetZ = m_dEditZeroOffSetZ;
	
	((CBallCutDlg*)GetParent())->InitAutoGalilParam();	
	CDlgMachineParam::OnOK();	
}

/*
 *	打开机械参数对话框时读取参数的函数
 */
void CDlgMachineParam::InitData()
{
	CString l_strKeyName;	//保存用的中间数据一个是数据，一个是键名
	char l_chDataName[20];
	memset(l_chDataName,0,sizeof(l_chDataName));
	for(int i=1015;i<1065;i++)
	{
		l_strKeyName.Format("m_dKeyName[%d]",i);
		GetPrivateProfileString("MachineParam",l_strKeyName,"-1",l_chDataName,20,	\
			"D:\\Program Files\\BallCut\\MachineParam.ini");
		SetDlgItemText(i,l_chDataName);
		UpdateData(TRUE);	
	}
}
//IDC_EDIT_BALL_RADIUS

HBRUSH CDlgMachineParam::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
LRESULT CDlgMachineParam::OnEditDouble(WPARAM wParam, LPARAM lParam) 
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
