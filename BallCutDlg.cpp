// BallCutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BallCut.h"
#include "BallCutDlg.h"
#include "DlgWorkParam.h"
#include "math.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBallCutDlg dialog

CBallCutDlg::CBallCutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBallCutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBallCutDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	g_pMainDlg = this;
	m_CDlgZero = new CDlgZero;
	m_CDlgHand = new CDlgHand;
//	m_CDlgFireCutPos = new CShowFireCutPos;
	m_brush.CreateSolidBrush(RGB(203,211,237));   //控件背景色的刷子	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iIsSuspend=0;				//给暂停按钮设定初始状态
	m_iWhichProduct = 1;		//1赤道，2极中，3极侧，4极边
	m_bFlagSB6 = FALSE;
	m_bFlagSB7 = FALSE;
	m_bFlagSB8 = FALSE;
	m_bFlagSB17 = FALSE;
	//650容积的球体指针
	m_CBallCutDll = new CBallCutDll(650);
}

CBallCutDlg::~CBallCutDlg()
{
	if (m_CDlgZero->GetSafeHwnd() != NULL)
	{
		m_CDlgZero->DestroyWindow();
	}
	if (m_CDlgZero != NULL)
	{
		delete m_CDlgZero;
		m_CDlgZero = NULL;
	}
	if (m_CDlgHand->GetSafeHwnd() != NULL)
	{
		m_CDlgHand->DestroyWindow();
	}
	if (m_CDlgHand != NULL)
	{
		delete m_CDlgHand;
		m_CDlgHand = NULL;
	}
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}

void CBallCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBallCutDlg)
	DDX_Control(pDX, IDC_SLIDER_MULTIPLY, m_ctlSliderMultiply);
	DDX_Control(pDX, IDC_LAMP_STATEA, m_ctlLampStateA);
	DDX_Control(pDX, IDC_LAMP_STATEB, m_ctlLampStateB);
	DDX_Control(pDX, IDC_LAMP_STATEC, m_ctlLampStateC);
	DDX_Control(pDX, IDC_LAMP_STATEX, m_ctlLampStateX);
	DDX_Control(pDX, IDC_LAMP_STATEY, m_ctlLampStateY);
	DDX_Control(pDX, IDC_LAMP_STATEZ, m_ctlLampStateZ);
	DDX_Control(pDX, IDC_CAPTIONINFOCTRL_TIME, m_CapTime);
	DDX_Control(pDX, IDC_BTN_EQUTOR, m_ctl4Equtor);
	DDX_Control(pDX, IDC_BTN_4SIDE, m_ctl4Side);
	DDX_Control(pDX, IDC_BTN_4CENTER, m_ctl4Center);
	DDX_Control(pDX, IDC_BTN_POLE_EDGE, m_ctl4Edge);
	DDX_Control(pDX, IDC_BTN_3SIDE, m_ctl3Side);
	DDX_Control(pDX, IDC_BTN_3EQUTOR, m_ctl3Equtor);
	DDX_Control(pDX, IDC_BTN_3CENTER, m_ctl3Center);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBallCutDlg, CDialog)
	//{{AFX_MSG_MAP(CBallCutDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	ON_BN_CLICKED(IDC_BTN_AUTO, OnBtnAuto)
	ON_BN_CLICKED(IDC_BTN_HAND, OnBtnHand)
	ON_BN_CLICKED(IDC_BTN_ZERO, OnBtnZero)
	ON_BN_CLICKED(IDC_BTN_EXAMINE, OnBtnExamine)
	ON_BN_CLICKED(IDC_BTN_WORKPARAM, OnBtnWorkParam)
	ON_BN_CLICKED(IDC_BTN_CUT_SUSPEND, OnBtnCutSuspend)   //暂停 
	ON_BN_CLICKED(IDC_BTN_CUT_BEGAN, OnBtnCutBegan)//启动
	ON_BN_CLICKED(IDC_BTN_CUT_STOP, OnBtnCutStop)//停止 
	ON_BN_CLICKED(IDC_BTN_HOT_GAS, OnBtnHotGas)		//预热
	ON_BN_CLICKED(IDC_BTN_FIRE_GAS, OnBtnFireGas)   //乙炔
	ON_BN_CLICKED(IDC_BTN_CUT_GAS, OnBtnCutGas)//切割氧
	ON_BN_CLICKED(IDC_BTN_RELEASE_GAS, OnBtnReleaseGas)//放气

	ON_MESSAGE(WM_INPUT,OnMsgInput)							//自己定义的WIN消息
	ON_MESSAGE(WM_EDITDOUBLE,OnEditDouble)					//系统消息		
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBallCutDlg message handlers

BOOL CBallCutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
/************************************************************************/
/*打开控制器                                                            */
/************************************************************************/
	long l_lRes=g_cController.Open(1);
	if (0 != l_lRes)
	{
		CommunicationErrorMessage();
	}
	else
	{	
		g_cController.Command("SH");
		g_cController.Command("GM1,,,,,,1;GA,,,,,,CX;GR,,,,,,1");
	}
	g_cHandDll.handInit((long)(&g_cController));
/************************************************************************/
/*对话框初始化                                                          */
/************************************************************************/
	//设定窗口大小
	SetWindowPos(&CWnd::wndTop, 0, 0, 1024, 788, SWP_SHOWWINDOW);
	
	SetWindowText("PNC2000BC");
	InitBtn();											//初始化主界面按钮
	InitData();											//打开软件时读出参数
	InitAutoGalilParam();								//初始化自动界面的galil参数
	InitInterface();									//初始化手动和回零的界面
	
	FirstInputState();									//首次上电查看输入点状态
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);	
	m_ctl4Equtor.SetForeColor(255);						//让赤道变红色
	m_iBreakThread = 0;									//跳出线程的变量，当为1时跳出
/************************************************************************/
/* 报警初始化                                                           */
/************************************************************************/
	g_AlarmDll.InitDB("D:\\program files\\BallCut");
	g_AlarmDll.SetHisAlmTime(5);
	OnSystemTimer();			//时间显示
	
	SetTimer(1,200,NULL);
	SetTimer(2,1000,NULL);
	// TODO: Add extra initialization here
	//设定a旋转轴半径
	m_CBallCutDll->SetR2(g_dBigShakeRadiuas);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBallCutDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBallCutDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//贴背景图片
		CPaintDC dc(this);
		CDC  MemDc;
		CBitmap bitmap;	
		MemDc.CreateCompatibleDC(&dc);
		bitmap.LoadBitmap(IDB_BITMAP_BK);
		CBitmap *pOldBit = MemDc.SelectObject(&bitmap);
		dc.BitBlt(0,0,1024,768,&MemDc,0,0,SRCCOPY);
		MemDc.SelectObject(pOldBit);
		bitmap.DeleteObject();
		MemDc.DeleteDC();
		CDialog::OnPaint();
	}
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBallCutDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*	函数：按钮初始化
 *	
 */
void CBallCutDlg::InitBtn()
{
	HRGN c;	
	c = CreateRectRgn(0, 0, 0, 0);
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_AUTO2);		
	//自动
	m_cBtnAuto.SetFont(&g_cFontButton);
	m_cBtnAuto.SetBitMapID(IDB_BITMAP_AUTO1,IDB_BITMAP_AUTO2);	
	m_cBtnAuto.Create("自动", WS_CHILD | WS_VISIBLE, CPoint(37, 714), c, this, IDC_BTN_AUTO); 
	//手动
	m_cBtnHand.SetFont(&g_cFontButton);
	m_cBtnHand.SetBitMapID(IDB_BITMAP_HAND1,IDB_BITMAP_HAND2);	
	m_cBtnHand.Create("手动", WS_CHILD | WS_VISIBLE, CPoint(207, 714), c, this, IDC_BTN_HAND);
	//回零
	m_cBtnZero.SetFont(&g_cFontButton);
	m_cBtnZero.SetBitMapID(IDB_BITMAP_ZERO1,IDB_BITMAP_ZERO2);	
	m_cBtnZero.Create("回零", WS_CHILD | WS_VISIBLE, CPoint(377, 714), c, this,IDC_BTN_ZERO ); 
	//参数
	m_cBtnWorkParam.SetFont(&g_cFontButton);
	m_cBtnWorkParam.SetBitMapID(IDB_BITMAP_WORKPARAM1,IDB_BITMAP_WORKPARAM2);	
	m_cBtnWorkParam.Create("参数", WS_CHILD | WS_VISIBLE, CPoint(547, 714), c, this, IDC_BTN_WORKPARAM); 
	//诊断
	m_cBtnExamine.SetFont(&g_cFontButton);
	m_cBtnExamine.SetBitMapID(IDB_BITMAP_EXAMINE1,IDB_BITMAP_EXAMINE2);	
	m_cBtnExamine.Create("诊断", WS_CHILD | WS_VISIBLE, CPoint(717, 714), c, this,IDC_BTN_EXAMINE); 
	//退出
	m_cBtnClose.SetFont(&g_cFontButton);
	m_cBtnClose.SetBitMapID(IDB_BITMAP_CLOSE1,IDB_BITMAP_CLOSE2);	
	m_cBtnClose.Create("退出", WS_CHILD | WS_VISIBLE, CPoint(887, 714), c, this, IDC_BTN_CLOSE); 
	//切割启动
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_CUT_SUSPEND2);
	m_cCutBegan.SetFont(&g_cFontEdit);
	m_cCutBegan.SetBitMapID(IDB_BITMAP_CUT_BEGAN1,IDB_BITMAP_CUT_BEGAN2);	
	m_cCutBegan.Create("启动", WS_CHILD | WS_VISIBLE, CPoint(738, 340), c, this, IDC_BTN_CUT_BEGAN); 
	//切割暂停
	m_cCutSuspend.SetFont(&g_cFontEdit);
	m_cCutSuspend.SetBitMapID(IDB_BITMAP_CUT_SUSPEND2,IDB_BITMAP_CUT_SUSPEND1);	
	m_cCutSuspend.Create("暂停", WS_CHILD | WS_VISIBLE, CPoint(886, 340), c, this, IDC_BTN_CUT_SUSPEND); 
	//切割停止
	m_cCutStop.SetFont(&g_cFontEdit);
	m_cCutStop.SetBitMapID(IDB_BITMAP_CUT_STOP1,IDB_BITMAP_CUT_STOP2);	
	m_cCutStop.Create("停止", WS_CHILD | WS_VISIBLE, CPoint(886, 650), c, this, IDC_BTN_CUT_STOP); 

	//预热氧
	m_cBtnHotGas.SetFont(&g_cFontEdit);
	m_cBtnHotGas.SetBitMapID(IDB_BITMAP2,IDB_BITMAP1);	
	m_cBtnHotGas.Create("预热氧", WS_CHILD | WS_VISIBLE, CPoint(738, 430), c, this, IDC_BTN_HOT_GAS); 
	//燃气
	m_cBtnFireGas.SetFont(&g_cFontEdit);
	m_cBtnFireGas.SetBitMapID(IDB_BITMAP2,IDB_BITMAP1);	
	m_cBtnFireGas.Create("燃气", WS_CHILD | WS_VISIBLE, CPoint(886, 430), c, this, IDC_BTN_FIRE_GAS); 
	//切割氧
	m_cBtnCutGas.SetFont(&g_cFontEdit);
	m_cBtnCutGas.SetBitMapID(IDB_BITMAP2,IDB_BITMAP1);	
	m_cBtnCutGas.Create("切割氧", WS_CHILD | WS_VISIBLE, CPoint(738, 495), c, this, IDC_BTN_CUT_GAS);
	//放气
	m_cBtnReleaseGas.SetFont(&g_cFontEdit);
	m_cBtnReleaseGas.SetBitMapID(IDB_BITMAP2,IDB_BITMAP1);	
	m_cBtnReleaseGas.Create("放气", WS_CHILD | WS_VISIBLE, CPoint(886, 495), c, this, IDC_BTN_RELEASE_GAS);

	
	DeleteObject(c);
	//初始化静态控件的字体
}



/*
 *	自动按钮
 */
void CBallCutDlg::OnBtnAuto()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	m_CDlgHand->ShowWindow(SW_HIDE);
	m_CDlgZero->ShowWindow(SW_HIDE);
	m_cBtnAuto.SelectState(IDB_BITMAP_AUTO3);
	m_cBtnHand.SelectState(0);
	m_cBtnZero.SelectState(0);
}

/*
 *	手动按钮
 */

void CBallCutDlg::OnBtnHand()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)
	{
		DMCRuningMessage();
		return;
	}
	m_CDlgHand->ShowWindow(SW_SHOW);
	m_CDlgZero->ShowWindow(SW_HIDE);
	m_cBtnHand.SelectState(IDB_BITMAP_HAND3);
	m_cBtnAuto.SelectState(0);
	m_cBtnZero.SelectState(0);
}

/*
 *	回零按钮
 */
void CBallCutDlg::OnBtnZero()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	m_CDlgZero->ShowWindow(SW_SHOW);
	m_CDlgHand->ShowWindow(SW_HIDE);
	m_cBtnHand.SelectState(0);
	m_cBtnAuto.SelectState(0);
	m_cBtnZero.SelectState(IDB_BITMAP_ZERO3);
}

/*
 *	诊断按钮
 */
void CBallCutDlg::OnBtnExamine()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	CDlgExamine OpenDlg;
	OpenDlg.DoModal();
}

/*
 *	参数按钮
 */
void CBallCutDlg::OnBtnWorkParam()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	CDlgWorkParam OpenDlg;
	OpenDlg.DoModal();
}

/*
 *	退出按钮
 */
void CBallCutDlg::OnBtnClose()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)
	{
		DMCRuningMessage();
		return;
	}
	CBallCutDlg::OnOK();
}

/*
*	暂停按钮
*/
void CBallCutDlg::OnBtnCutSuspend()
{
	if (0 == m_iIsSuspend)
	{
		m_cCutSuspend.SelectState(IDB_BITMAP_CUT_SUSPEND3);
		m_iIsSuspend++;
		g_cController.Command("VR0");
	}
	else
	{
		m_cCutSuspend.SelectState(0);
		m_iIsSuspend=0;
		CString l_strDMCCmd;
		char l_chDMCCmd[20]={0};
		float iIndex = m_ctlSliderMultiply.GetValue();
		l_strDMCCmd.Format("VR%.2f",iIndex);
		strcpy(l_chDMCCmd,l_strDMCCmd);
		g_cController.Command(l_chDMCCmd);
	}
}

/*
*	启动按钮
*/
void CBallCutDlg::OnBtnCutBegan()
{  
	
	char chZero[80] = {0};
	g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
/*
	if (atoi(chZero) == 0)
	{
		NoHomeMessage();
		return;
	}
*/
	//创建线程
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0||m_iBreakThread == 2)		
	{															//m_iBreakThread == 2是判断线程是否在运行
		DMCRuningMessage();
		return;
	}
	m_iBreakThread = 0;			//跳出线程的变量，当为1时跳出
	m_hThreadOne = CreateThread(NULL,100,ThreadDownloadDMC,(void*)this,0,NULL);	
}

/*
*	停止按钮
*/
void CBallCutDlg::OnBtnCutStop()
{
	m_iBreakThread = 1;			//跳出线程的变量，当为1时跳出	
	Sleep(100);
	g_cController.Command("ST;STXYZWEFG;STS;CSS");	

}

/*
*	赤道按钮
*/
void CBallCutDlg::OnBtnEqutor()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);
	m_ctl4Equtor.SetForeColor(255);
	m_ctl4Side.SetForeColor(0);
	m_ctl4Center.SetForeColor(0);
	m_ctl4Edge.SetForeColor(0);
	m_ctl3Side.SetForeColor(0);
	m_ctl3Equtor.SetForeColor(0);
	m_ctl3Center.SetForeColor(0);
	m_iWhichProduct = 1;	
}

/*
*	极中按钮
*/
void CBallCutDlg::OnBtnPoleCenter()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);
	m_ctl4Equtor.SetForeColor(0);
	m_ctl4Side.SetForeColor(0);
	m_ctl4Center.SetForeColor(255);
	m_ctl4Edge.SetForeColor(0);
	m_ctl3Side.SetForeColor(0);
	m_ctl3Equtor.SetForeColor(0);
	m_ctl3Center.SetForeColor(0);
	m_iWhichProduct = 2;
}

/*
*	极侧按钮
*/
void CBallCutDlg::OnBtnPoleEdge()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);
	m_ctl4Equtor.SetForeColor(0);
	m_ctl4Side.SetForeColor(0);
	m_ctl4Center.SetForeColor(0);
	m_ctl4Edge.SetForeColor(255);
	m_ctl3Side.SetForeColor(0);
	m_ctl3Equtor.SetForeColor(0);
	m_ctl3Center.SetForeColor(0);
	m_iWhichProduct = 3;
}

/*
*	极边按钮
*/
void CBallCutDlg::OnBtnPoleSide()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);
	m_ctl4Equtor.SetForeColor(0);
	m_ctl4Side.SetForeColor(255);
	m_ctl4Center.SetForeColor(0);
	m_ctl4Edge.SetForeColor(0);
	m_ctl3Side.SetForeColor(0);
	m_ctl3Equtor.SetForeColor(0);
	m_ctl3Center.SetForeColor(0);
	m_iWhichProduct = 4;
}

/*
 *	初始化手动和回零的界面
 */
void CBallCutDlg::InitInterface()
{	

	m_CDlgHand->Create(IDD_DLG_HAND,this);
	m_CDlgZero->Create(IDD_DLG_ZERO,this);
//	m_CDlgFireCutPos->Create(IDD_DIALOG_SHOW_FIRE_CUT_POS,this);
//	m_CDlgFireCutPos->ShowWindow(SW_SHOW);
}

/*
 *	打开软件界面时，读取参数
 */
void CBallCutDlg::InitData()
{
	CString l_strFlieName(FILE_PATH_OF_D);
	l_strFlieName = l_strFlieName + "MainInterfaceParam.ini";
	char l_chDataName[30]={0};

	//主界面上的参数

	//以下都是机械界面上的参数。	
	l_strFlieName = FILE_PATH_OF_D;
	l_strFlieName = l_strFlieName + "MachineParam.ini";
	GetPrivateProfileString("MachineParam","m_dKeyName[1015]","-1",l_chDataName,20,l_strFlieName);//从文件中获得
	g_dPulseX = atof(l_chDataName);//获得完的值再给全局的值
	GetPrivateProfileString("MachineParam","m_dKeyName[1016]","-1",l_chDataName,20,l_strFlieName);
	g_dPulseY = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1017]","-1",l_chDataName,20,l_strFlieName);
	g_dPulseZ = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1018]","-1",l_chDataName,20,l_strFlieName);
	g_dPulseA = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1039]","-1",l_chDataName,20,l_strFlieName);
	g_dPulseB = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1040]","-1",l_chDataName,20,l_strFlieName);
	g_dPulseC = atof(l_chDataName);

	GetPrivateProfileString("MachineParam","m_dKeyName[1019]","-1",l_chDataName,20,l_strFlieName);
	g_dHandAddX = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1020]","-1",l_chDataName,20,l_strFlieName);
	g_dHandAddY = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1021]","-1",l_chDataName,20,l_strFlieName);
	g_dHandAddZ = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1022]","-1",l_chDataName,20,l_strFlieName);
	g_dHandAddA = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1047]","-1",l_chDataName,20,l_strFlieName);
	g_dHandAddB = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1048]","-1",l_chDataName,20,l_strFlieName);
	g_dHandAddC = atof(l_chDataName);

	GetPrivateProfileString("MachineParam","m_dKeyName[1023]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSubX = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1024]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSubY = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1025]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSubZ = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1026]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSubA = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1041]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSubB = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1042]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSubC = atof(l_chDataName);

	GetPrivateProfileString("MachineParam","m_dKeyName[1027]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSpeedX = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1028]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSpeedY = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1029]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSpeedZ = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1030]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSpeedA = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1043]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSpeedB = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1044]","-1",l_chDataName,20,l_strFlieName);
	g_dHandSpeedC = atof(l_chDataName);

	GetPrivateProfileString("MachineParam","m_dKeyName[1031]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroSpeedX = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1032]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroSpeedY = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1033]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroSpeedZ = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1034]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroSpeedA = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1049]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroSpeedB = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1050]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroSpeedC = atof(l_chDataName);

	GetPrivateProfileString("MachineParam","m_dKeyName[1035]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitFX = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1036]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitFY = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1037]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitFZ = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1038]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitFA = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1045]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitFB = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1046]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitFC = atoi(l_chDataName);

	GetPrivateProfileString("MachineParam","m_dKeyName[1051]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitRX = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1052]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitRY = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1053]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitRZ = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1054]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitRA = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1055]","-1",l_chDataName,20,	l_strFlieName);
	g_lLimitRB = atoi(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1056]","-1",l_chDataName,20,l_strFlieName);
	g_lLimitRC = atoi(l_chDataName);


	GetPrivateProfileString("MachineParam","m_dKeyName[1059]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroOffsetX = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1060]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroOffsetY = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1061]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroOffsetZ = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1062]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroOffsetA = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1063]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroOffsetB = atof(l_chDataName);
	GetPrivateProfileString("MachineParam","m_dKeyName[1064]","-1",l_chDataName,20,l_strFlieName);
	g_dZeroOffsetC = atof(l_chDataName);
//给龙门里的M1赋上值
	CString l_strDmcCommand;
	GetPrivateProfileString("AdjustParam","M1","0",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\AdjustParam.ini");
	l_strDmcCommand.Format("%s",l_chDataName);
	strcpy(l_chDataName,"M1="+l_strDmcCommand);
	g_cController.Command(l_chDataName);	

	///////////////////////////四壳球数据////////////////////////////////////
	l_strFlieName = FILE_PATH_OF_D;
	l_strFlieName = l_strFlieName + "4BallParam.ini";	
	//赤道
	GetPrivateProfileString("4BallParam","4EA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EA = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EG","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EG = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EAA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EAA = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EGA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EGA = atof(l_chDataName);
	//极中
	GetPrivateProfileString("4BallParam","4CA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4CA = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4CG","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4CG = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4CAA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4CAA = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4CGA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4CGA = atof(l_chDataName);
	//极侧
	GetPrivateProfileString("4BallParam","4EDA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EDA = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EDG","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EDG = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EDE","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EDE = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EDAA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EDAA = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EDGA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EDGA = atof(l_chDataName);
	//极侧
	GetPrivateProfileString("4BallParam","4SG","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4SG = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4SB","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4SB = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4SE","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4SE = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4EDB","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4EDB = atof(l_chDataName);
	GetPrivateProfileString("4BallParam","4SGA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamFourBall.Ball4SGA = atof(l_chDataName);
	///////////////////////////三壳球数据////////////////////////////////////
	l_strFlieName = FILE_PATH_OF_D;
	l_strFlieName = l_strFlieName + "3BallParam.ini";	
	//赤道
	GetPrivateProfileString("3BallParam","3EA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3EA = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3EB","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3EB = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3EAA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3EAA = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3EBA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3EBA = atof(l_chDataName);
	//极中
	GetPrivateProfileString("3BallParam","3CA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3CA = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3CB","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3CB = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3CG","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3CG = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3CGA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3CGA = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3CBA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3CBA = atof(l_chDataName);
	//极侧
	GetPrivateProfileString("3BallParam","3SA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3SA = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3SB","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3SB = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3SG","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3SG = atof(l_chDataName);
	GetPrivateProfileString("3BallParam","3SAA","-1",l_chDataName,20,l_strFlieName);
	m_stcParamThreeBall.Ball3SAA = atof(l_chDataName);	
	
//给工艺参数里的参数赋值	
	GetPrivateProfileString("WorkParam","THICK","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	g_dThick = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","BALL_RADIUS","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	g_dBallRadius = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","CUT_SPEED","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	g_dCutSpeed = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","CUT_ADD","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	g_dCutAdd = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","CUT_SUB","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	g_dCutSub = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","BAuxRadius","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	g_dBigShakeRadiuas = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","OverCut","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	m_stcParamWork.OverCut = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","CenterOffSet","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	m_stcParamWork.CenterOffset = atof(l_chDataName);

	GetPrivateProfileString("WorkParam","Postion400","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	m_stcParamWork.Position400 = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","Postion650","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	m_stcParamWork.Position650 = atof(l_chDataName);
	GetPrivateProfileString("WorkParam","Postion3000","-1",l_chDataName,20,	\
		"D:\\Program Files\\BallCut\\WorkParam.ini");
	m_stcParamWork.Position3000 = atof(l_chDataName);
}

/*
 *	//初始化自动界面的galil参数
 */
void CBallCutDlg::InitAutoGalilParam()
{
	g_cHandDll.ResolutionSet(g_dPulseX,g_dPulseY,g_dPulseZ,		\
		g_dPulseA,g_dPulseB,g_dPulseC,g_dPulseX,g_dPulseX);		//初始化脉冲当量

	g_cHandDll.handSpeedACSet(g_dHandAddX,g_dHandAddY,g_dHandAddZ,		\
		g_dHandAddA,g_dHandAddB,g_dHandAddC,g_dHandAddX,g_dHandAddX);//设定手动加速度

	g_cHandDll.handSpeedDCSet(g_dHandSubX,g_dHandSubY,g_dHandSubZ,		\
		g_dHandSubA,g_dHandSubB,g_dHandSubC,g_dHandSubX,g_dHandSubX);//设定手动减速度

	g_cHandDll.handSpeedSet(g_dHandSpeedX,g_dHandSpeedY,g_dHandSpeedZ,		\
		g_dHandSpeedA,g_dHandSpeedB,g_dHandSpeedC,g_dHandSpeedX,g_dHandSpeedX);//设定手动速度
	
	g_cHandDll.SetJourneyNegetive(g_lLimitRX,g_lLimitRY,g_lLimitRZ,		\
		g_lLimitRA,g_lLimitRB,g_lLimitRC,g_lLimitRX,g_lLimitRX);//设定手动负软行程

	g_cHandDll.SetJourneyPositive(g_lLimitFX,g_lLimitFY,g_lLimitFZ,		\
		g_lLimitFA,g_lLimitFB,g_lLimitFC,g_lLimitFX,g_lLimitFX);//设定手动正软行程

	g_cHandDll.zoneSpeedSet(g_dZeroSpeedX,g_dZeroSpeedY,g_dZeroSpeedZ,
		g_dZeroSpeedA,g_dZeroSpeedB,g_dZeroSpeedC,g_dZeroSpeedX,g_dZeroSpeedX);//设定回零的速度

	g_cHandDll.zoneOffset(g_dZeroOffsetX,g_dZeroOffsetY,g_dZeroOffsetZ,
		g_dZeroOffsetA,g_dZeroOffsetB,g_dZeroOffsetC,g_dZeroOffsetX,g_dZeroOffsetX);//设定回零偏置
	CString		strTemp;
	char szCmd[80]={0};
	strTemp.Format("nSFLX=%ld;nSFLY=%ld;nSFLZ=%ld",
		g_lLimitFX*(long)g_dPulseX,g_lLimitFY*(long)g_dPulseY,g_lLimitFZ*(long)g_dPulseZ);
	strcpy(szCmd,strTemp);
	LONG l_Rec = g_cController.Command(szCmd);
	strTemp.Format("nSFLA=%ld;nSFLB=%ld;nSFLC=%ld",		\
		g_lLimitFA*(long)g_dPulseA,g_lLimitFB*(long)g_dPulseB,g_lLimitFC*(long)g_dPulseC);
	strcpy(szCmd,strTemp);
	g_cController.Command(szCmd);
	
	strTemp.Format("nSBLX=%d;nSBLY=%d;nSBLZ=%d",		\
		g_lLimitRX*(long)g_dPulseX,g_lLimitRY*(long)g_dPulseY,g_lLimitRZ*(long)g_dPulseZ);
	strcpy(szCmd,strTemp);
	g_cController.Command(szCmd);
	strTemp.Format("nSBLA=%d;nSBLB=%d;nSBLC=%d",		\
		g_lLimitRA*(long)g_dPulseA,g_lLimitRB*(long)g_dPulseB,g_lLimitRC*(long)g_dPulseC);
	strcpy(szCmd,strTemp);
	g_cController.Command(szCmd);
	//初始化回零状态
	g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
}	
			
HBRUSH CBallCutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if (nCtlColor==CTLCOLOR_DLG || nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)m_brush.GetSafeHandle();
	}	
//	}	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BEGIN_EVENTSINK_MAP(CBallCutDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CBallCutDlg)
	ON_EVENT(CBallCutDlg, IDC_SLIDER_MULTIPLY, -600 /* Click */, OnClickSliderMultiply, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_3CENTER, -600 /* Click */, OnClickBtn3center, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_3SIDE, -600 /* Click */, OnClickBtn3side, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_EQUTOR, -600 /* Click */, OnBtnEqutor, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_POLE_EDGE, -600 /* Click */, OnBtnPoleEdge, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_4CENTER, -600 /* Click */, OnBtnPoleCenter, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_4SIDE, -600 /* Click */, OnBtnPoleSide, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_3EQUTOR, -600 /* Click */, OnClickBtn3equtor, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_SET_ZORE, -600 /* Click */, OnClickBtnSetZore, VTS_NONE)
	ON_EVENT(CBallCutDlg, IDC_BTN_POS_650, -600 /* Click */, OnClickBtnPos650, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CBallCutDlg::OnClickSliderMultiply() 
{
	// TODO: Add your control notification handler code here
	float iIndex = m_ctlSliderMultiply.GetClickIndex();
	m_ctlSliderMultiply.SetValue((float)iIndex);
	CString l_strDmc;
	char l_chDmc[10];
	l_strDmc.Format("VR%.2f",iIndex);
	strcpy(l_chDmc,l_strDmc);
	g_cController.Command(l_chDmc);
}

void CBallCutDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		WhenInputingDone();			//扫描输入点是否有输入，有输入的话的发送消息
		AskAuxSpeed();				//问电机速度
		AskAuxPosition();			//问电机位置
		
		break;
	case 2:
		OnSystemTimer();			//时间显示
		break;
	default:
		break;
	}

	CDialog::OnTimer(nIDEvent);
}

/*
 *	问电机速度
 */
void CBallCutDlg::AskAuxSpeed()
{
	CString l_strRes; 
	double l_dValueActual,l_dValueTV,l_dPulse;	
	char szResponse[30]={0},l_cTv[4]={0};
	long l_iStateCommicatiom = g_cController.Command("MG(_BGX|_BGY|_BGZ|_BGW|_BGE|_BGF)",szResponse,sizeof(szResponse));
	if (l_iStateCommicatiom == 0)
	{
		for(int j=0;j<6;j++)
		{
			l_cTv[0]=84;	l_cTv[1]=86;	l_cTv[2]=65+j;		//84=T;86=V;65=A	
			LONG lRc = g_cController.Command(l_cTv,szResponse,sizeof(szResponse));
			switch(j) 
			{
				case 0:		l_dPulse=g_dPulseX;
					break;
				case 1:		l_dPulse=g_dPulseY;
					break;
				case 2:		l_dPulse=g_dPulseZ;
					break;
				case 3:		l_dPulse=g_dPulseA;
					break;
				case 4:		l_dPulse=g_dPulseB;
					break;
				case 5:		l_dPulse=g_dPulseC;
					break;
				default:	break;
			}
			l_dValueTV = atof(szResponse);
			l_dValueActual=l_dValueTV/l_dPulse;
			l_strRes.Format("%.2f",l_dValueActual);
			SetDlgItemText(j+IDC_STATIC_SPX,l_strRes);
		}
	}
}

/*
 *	问电机位置
 */
void CBallCutDlg::AskAuxPosition()
{
	CString l_strRes; 
	double l_dValueActual,l_dValueTV,l_dPulse;	
	char szResponse[30]={0},l_cTv[4]={0};
	for(int j=0;j<6;j++)
	{
		l_cTv[0]=84;	l_cTv[1]=80;	l_cTv[2]=65+j;		//84=T;80=P;65=A	
		LONG lRc = g_cController.Command(l_cTv,szResponse,sizeof(szResponse));
		if (lRc != 0)
		{
			return;
		}
		switch(j) {  
		case 0:		l_dPulse=g_dPulseX;
			break;
		case 1:		l_dPulse=g_dPulseY;
			break;
		case 2:		l_dPulse=g_dPulseZ;
			break;
		case 3:		l_dPulse=g_dPulseA;
			break;
		case 4:		l_dPulse=g_dPulseB;
			break;
		case 5:		l_dPulse=g_dPulseC;
			break;
		default:	break;
		}
		l_dValueTV = atof(szResponse);
		if(j<3)
			l_dValueActual=l_dValueTV/l_dPulse/1000;
		else
			l_dValueActual=l_dValueTV/l_dPulse;
		l_strRes.Format("%.2f",l_dValueActual);
		SetDlgItemText(j+IDC_STATIC_PRX,l_strRes);
	}
}

/*
 *	触摸屏WIN消息函数触发
 */
LRESULT CBallCutDlg::OnEditDouble(WPARAM wParam, LPARAM lParam) 
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

/*
 *	输入点WIN消息函数触发
 */
LRESULT CBallCutDlg::OnMsgInput(WPARAM wParam, LPARAM lParam)
{
	if (1 == wParam)
	{
		switch(lParam)
		{
		case IN_EMG_STOP:	//急停后停止
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			OnBtnCutStop();
			g_AlarmDll.SetAlarm(EMERGENCY_STOP);
			break;
			//以下是断使能后停止，亮蓝灯
		case IN_SERVOX_STATE:
			OnBtnCutStop();
			m_ctlLampStateX.SetRgby(4);
			break;
		case IN_SERVOY_STATE:
			OnBtnCutStop();
			m_ctlLampStateY.SetRgby(4);
			break;
		case IN_SERVOZ_STATE:
			OnBtnCutStop();
			m_ctlLampStateZ.SetRgby(4);
			break;
		case IN_SERVOA_STATE:
			OnBtnCutStop();
			m_ctlLampStateA.SetRgby(4);
			break;
		case IN_SERVOB_STATE:
			OnBtnCutStop();
			m_ctlLampStateB.SetRgby(4);
			break;
		case IN_SERVOC_STATE:
			OnBtnCutStop();
			m_ctlLampStateC.SetRgby(4);
			break;
		case IN_SERVOG_STATE:
			OnBtnCutStop();
			m_ctlLampStateX.SetRgby(4);
			break;
			//负限位解除后，绿灯
		case IN_SERVOX_RLIMIT:	
			m_ctlLampStateX.SetRgby(1);
			break;
		case IN_SERVOY_RLIMIT:	
			m_ctlLampStateY.SetRgby(1);
			break;
		case IN_SERVOZ_RLIMIT:
			m_ctlLampStateZ.SetRgby(1);
			break;
		case IN_SERVOA_RLIMIT:
			m_ctlLampStateA.SetRgby(1);
			break;
		case IN_SERVOB_RLIMIT:	
			m_ctlLampStateB.SetRgby(1);
			break;
		case IN_SERVOC_RLIMIT:	
			m_ctlLampStateC.SetRgby(1);
			break;
		case IN_SERVOG_RLIMIT:
			m_ctlLampStateX.SetRgby(1);
			break;
		//正限位解除后，绿灯
		case IN_SERVOX_FLIMIT:
			m_ctlLampStateX.SetRgby(1);
			break;
		case IN_SERVOY_FLIMIT:
			m_ctlLampStateY.SetRgby(1);
			break;
		case IN_SERVOZ_FLIMIT:
			m_ctlLampStateZ.SetRgby(1);
			break;
		case IN_SERVOA_FLIMIT:	
			m_ctlLampStateA.SetRgby(1);
			break;
		case IN_SERVOB_FLIMIT:
			m_ctlLampStateB.SetRgby(1);
			break;
		case IN_SERVOC_FLIMIT:	
			m_ctlLampStateC.SetRgby(1);
			break;
		case IN_SERVOG_FLIMIT:	
			m_ctlLampStateX.SetRgby(1);
			break;
			//电机报警解除后，绿灯
		case IN_SERVOX_ALARM:
			m_ctlLampStateX.SetRgby(1);
			break;
		case IN_SERVOY_ALARM:
			m_ctlLampStateY.SetRgby(1);
			break;
		case IN_SERVOZ_ALARM:
			m_ctlLampStateZ.SetRgby(1);
			break;
		case IN_SERVOA_ALARM:	
			m_ctlLampStateA.SetRgby(1);
			break;
		case IN_SERVOB_ALARM:
			m_ctlLampStateB.SetRgby(1);
			break;
		case IN_SERVOC_ALARM:	
			m_ctlLampStateC.SetRgby(1);
			break;
		case IN_SERVOG_ALARM:	
			m_ctlLampStateX.SetRgby(1);
			break;
		}
	}		
	else//输入点从有到没有
	{
		switch(lParam)		
		{
		case IN_EMG_STOP:		//急停解除后使能
			g_cController.Command("SH");			
		case IN_SERVOX_STATE:
			m_ctlLampStateX.SetRgby(1);//急停解除后停止，亮绿灯
			break;
		case IN_SERVOY_STATE:
			m_ctlLampStateY.SetRgby(1);
			break;
		case IN_SERVOZ_STATE:
			m_ctlLampStateZ.SetRgby(1);
			break;
		case IN_SERVOA_STATE:
			m_ctlLampStateA.SetRgby(1);
			break;
		case IN_SERVOB_STATE:
			m_ctlLampStateB.SetRgby(1);
			break;
		case IN_SERVOC_STATE:
			m_ctlLampStateC.SetRgby(1);
			break;
		case IN_SERVOG_STATE:
			m_ctlLampStateX.SetRgby(1);
			break;
			//正限位后停止，黄灯
		case IN_SERVOX_FLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateX.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_X_FORVARDLIMIT);
			break;
		case IN_SERVOY_FLIMIT:
			OnBtnCutStop();
			m_ctlLampStateY.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_Y_FORVARDLIMIT);
			break;
		case IN_SERVOZ_FLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateZ.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_Z_FORVARDLIMIT);
			break;
		case IN_SERVOA_FLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateA.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_W_FORVARDLIMIT);
			break;
		case IN_SERVOB_FLIMIT:
			OnBtnCutStop();
			m_ctlLampStateB.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_E_FORVARDLIMIT);
			break;
		case IN_SERVOC_FLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateC.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_F_FORVARDLIMIT);
			break;
		case IN_SERVOG_FLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateX.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_G_FORVARDLIMIT);
			break;
				//以下是负限位后停止，黄灯
		case IN_SERVOX_RLIMIT:
			OnBtnCutStop();
			m_ctlLampStateX.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_X_REVERSELIMIT);
			break;
		case IN_SERVOY_RLIMIT:
			OnBtnCutStop();
			m_ctlLampStateY.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_Y_REVERSELIMIT);
			break;
		case IN_SERVOZ_RLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateZ.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_Z_REVERSELIMIT);
			break;
		case IN_SERVOA_RLIMIT:
			OnBtnCutStop();
			m_ctlLampStateA.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_W_REVERSELIMIT);
			break;
		case IN_SERVOB_RLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateB.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_E_REVERSELIMIT);
			break;
		case IN_SERVOC_RLIMIT:	
			OnBtnCutStop();
			m_ctlLampStateC.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_F_REVERSELIMIT);
			break;
		case IN_SERVOG_RLIMIT:
			OnBtnCutStop();
			m_ctlLampStateX.SetRgby(2);
			g_AlarmDll.SetAlarm(AXIS_G_REVERSELIMIT);
		default:
			break;
			//电机报警后，红灯
		case IN_SERVOX_ALARM:
			m_ctlLampStateX.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_X_SERVOALARM);
			break;
		case IN_SERVOY_ALARM:
			m_ctlLampStateY.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_Y_SERVOALARM);
			break;
		case IN_SERVOZ_ALARM:
			m_ctlLampStateZ.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_Z_SERVOALARM);
			break;
		case IN_SERVOA_ALARM:	
			m_ctlLampStateA.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_W_SERVOALARM);
			break;
		case IN_SERVOB_ALARM:
			m_ctlLampStateB.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_E_SERVOALARM);
			break;
		case IN_SERVOC_ALARM:	
			m_ctlLampStateC.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_F_SERVOALARM);
			break;
		case IN_SERVOG_ALARM:	
			m_ctlLampStateX.SetRgby(0);
			g_cController.Command("homecx=0;homecy=0;homecz=0;homecw=0;homece=0;homecf=0;ST;STS;CSS");
			g_AlarmDll.SetAlarm(AXIS_G_SERVOALARM);
			break;
		}

	}
	return 0;
}

/*
 *	扫描输入点是否有输入，有输入的话的发送消息
 */
void CBallCutDlg::WhenInputingDone()
{
	m_iNewInput[0] = g_cHandDll.GetGroupIn(0);				//1~8点的TI值
	m_iNewInput[1] = g_cHandDll.GetGroupIn(1);				//9~16点的TI值
	m_iNewInput[2] = g_cHandDll.GetGroupIn(2);				//17~24点的TI值，每个轴是否报警状态
	m_iNewInput[3] = g_cHandDll.EmergencyState();			//采集现在的急停状态
	m_iNewInput[4] = AskServoSHState();						//采集现在的伺服状态
	m_iNewInput[5] = AskMotorLimitF();						//采集现在的正限位状态
	m_iNewInput[6] = AskMotorLimitR();						//采集现在的负限位状态	
	m_iNewInput[7] = AskMotorHome();						//采集现在的机械零点开关状态
	m_iNewInput[8] = g_cHandDll.GetGroupOut(0);				
	//以下是看输入点开关是否改变，若改变发送WIN消息
 	CompareNumber(IN_INPUT_8+1,m_iOldInput[0],m_iNewInput[0]);		//1~8输入点
	CompareNumber(IN_INPUT_16+1,m_iOldInput[1],m_iNewInput[1]);		//9~16输入点
	CompareNumber(IN_SERVO_ALARM+1,m_iOldInput[2],m_iNewInput[2]);		//1~8轴报警状态
	CompareZeroOrOne(IN_EMG_STOP,m_iOldInput[3],m_iNewInput[3]);	//急停	
	CompareNumber(IN_SERVO_STATE+1,m_iOldInput[4],m_iNewInput[4]);	//使能
	CompareNumber(IN_SERVO_FLIMIT+1,m_iOldInput[5],m_iNewInput[5]);	//正限位
	CompareNumber(IN_SERVO_RLIMIT+1,m_iOldInput[6],m_iNewInput[6]);	//负限位
	CompareNumber(IN_HOME_STATE+1,m_iOldInput[7],m_iNewInput[7]);	//零点开关
	CompareNumber(300,m_iOldInput[8],m_iNewInput[8]);				//比较输出是否有变化
	
	for(int i=0;i<10;i++)
	{
		m_iOldInput[i] = m_iNewInput[i];
	}
}

/*
 *	刚上电时查看下输入点状态，然后跟运行时的输出 点比较。
 */
void CBallCutDlg::FirstInputState()
{
	m_iOldInput[0] = g_cHandDll.GetGroupIn(0);		//1~8点的TI值
	m_iOldInput[1] = g_cHandDll.GetGroupIn(1);		//9~16点的TI值
	m_iOldInput[2] = g_cHandDll.GetGroupIn(2);		//17~24点的TI值，每个轴是否报警状态
	m_iOldInput[3] = g_cHandDll.EmergencyState();	//急停输入点的状态
	m_iOldInput[4] = 0;							//电机是否使能的状态
	m_iOldInput[5] = 127;							//电机正限位状态
	m_iOldInput[6] = 127;							//电机负限位状态
	m_iOldInput[7] = AskMotorHome();				//初始化机械零点开关状态
	m_iOldInput[8] = g_cHandDll.GetGroupOut(0);		//初始化输出点的值
	
}

/*
 *	比较输入0，1的函数
 */
void CBallCutDlg::CompareNumber(int WhichInput,int Inputed,int Inputing)
{
	CString		strP;
	int		i,nPosition;
	char	chP[10],chB[10];
	if(Inputed<0||Inputing<0||Inputed==Inputing)
		return;	
	nPosition = Inputed ^ Inputing;
	itoa(nPosition + 256, chP, 2);
	itoa(Inputing + 256, chB, 2);
	for(i=1;i<9;i++)
	{
		if(chP[i]=='1')			//输入点有发生变化时
		{
			if(chB[i]=='1')		//当输入点从有到没
			{
				PostMessage(WM_INPUT, 1, WhichInput - i);
			}
			else				//当输入点从没到有
			{
				SendMessage(WM_INPUT, 0, WhichInput - i);
			}

		}
	}
	CWnd *l_pDlg;
	l_pDlg = FindWindow(NULL, "Examine");
	if(l_pDlg)
		l_pDlg->SendMessage(WM_UPDATEINPUT,WhichInput,Inputing);
}

/*
 *	比较0~255，就是TI值
 */
void CBallCutDlg::CompareZeroOrOne(int WhichInput,int Inputed,int Inputing)
{
	if(Inputed<0||Inputed>1||Inputing<0||Inputing>1||Inputed==Inputing)
		return;
	if(Inputed<Inputing)	//没有输入时
	{
		SendMessage(WM_INPUT, 1, WhichInput);				
	}
	else					//输入时
	{
		SendMessage(WM_INPUT, 0, WhichInput);				
	}
}	

/*
 *	问伺服使能状态
 */
int CBallCutDlg::AskServoSHState()
{
	int		l_iReturn = 0;
	int		l_iValueServoSH[8];
	int		i;
	//断使能为1,有使能为0：MG_MOX
	char szRes[80]={0};
	g_cController.Command("MG_MOX",szRes,sizeof(szRes));
	l_iValueServoSH[0] = atoi(szRes);
	g_cController.Command("MG_MOY",szRes,sizeof(szRes));
	l_iValueServoSH[1] = atoi(szRes);
	g_cController.Command("MG_MOZ",szRes,sizeof(szRes));
	l_iValueServoSH[2] = atoi(szRes);
	g_cController.Command("MG_MOW",szRes,sizeof(szRes));
	l_iValueServoSH[3] = atoi(szRes);
	g_cController.Command("MG_MOE",szRes,sizeof(szRes));
	l_iValueServoSH[4] = atoi(szRes);
	g_cController.Command("MG_MOF",szRes,sizeof(szRes));
	l_iValueServoSH[5] = atoi(szRes);
	g_cController.Command("MG_MOG",szRes,sizeof(szRes));
	l_iValueServoSH[6] = atoi(szRes);
	l_iValueServoSH[7] = 0;
	for(i=0; i<8; i++)
	{
		l_iReturn += (long)(pow(2, i) * l_iValueServoSH[i]);
	}
	return l_iReturn;
}

/*
 *	问电机正限位状态
 */
int CBallCutDlg::AskMotorLimitF()
{
	int		l_iReturn = 0;
	int		l_iValueServoSH[8];
	int		i;
	//没限位为1,有使能为0：MG_LFX
	char szRes[80]={0};
	g_cController.Command("MG_LFX",szRes,sizeof(szRes));
	l_iValueServoSH[0] = atoi(szRes);
	g_cController.Command("MG_LFY",szRes,sizeof(szRes));
	l_iValueServoSH[1] = atoi(szRes);
	g_cController.Command("MG_LFZ",szRes,sizeof(szRes));
	l_iValueServoSH[2] = atoi(szRes);
	g_cController.Command("MG_LFW",szRes,sizeof(szRes));
	l_iValueServoSH[3] = atoi(szRes);
	g_cController.Command("MG_LFE",szRes,sizeof(szRes));
	l_iValueServoSH[4] = atoi(szRes);
	g_cController.Command("MG_LFF",szRes,sizeof(szRes));
	l_iValueServoSH[5] = atoi(szRes);
	g_cController.Command("MG_LFG",szRes,sizeof(szRes));
	l_iValueServoSH[6] = atoi(szRes);
	l_iValueServoSH[7] = 0;
	for(i=0; i<8; i++)				
	{//算成TI值一样			哪一位点是1，并在那点剩其对应的值。就是把8个点的二进制转成十进制
		l_iReturn += (long)(pow(2, i) * l_iValueServoSH[i]);
	}
	return l_iReturn;
}

/*
 *	问电机负限位状态
 */
int CBallCutDlg::AskMotorLimitR()
{
	int		l_iReturn = 0;
	int		l_iValueServoSH[8];
	int		i;
	//没限位为1,有使能为0：MG_LFX
	char szRes[80]={0};
	g_cController.Command("MG_LRX",szRes,sizeof(szRes));
	l_iValueServoSH[0] = atoi(szRes);
	g_cController.Command("MG_LRY",szRes,sizeof(szRes));
	l_iValueServoSH[1] = atoi(szRes);
	g_cController.Command("MG_LRZ",szRes,sizeof(szRes));
	l_iValueServoSH[2] = atoi(szRes);
	g_cController.Command("MG_LRW",szRes,sizeof(szRes));
	l_iValueServoSH[3] = atoi(szRes);
	g_cController.Command("MG_LRE",szRes,sizeof(szRes));
	l_iValueServoSH[4] = atoi(szRes);
	g_cController.Command("MG_LRF",szRes,sizeof(szRes));
	l_iValueServoSH[5] = atoi(szRes);
	g_cController.Command("MG_LRG",szRes,sizeof(szRes));
	l_iValueServoSH[6] = atoi(szRes);
	l_iValueServoSH[7] = 0;
	for(i=0; i<8; i++)
	{//算成TI值一样			哪一位点是1，并在那点剩其对应的值。就是把8个点的二进制转成十进制
		l_iReturn += (long)(pow(2, i) * l_iValueServoSH[i]);
	}
	return l_iReturn;
}

/*
 *	问电机机械零点开关的值
 */		
int CBallCutDlg::AskMotorHome()
{
	int		l_iReturn = 0;
	int		l_iValueServoSH[8];
	int		i;
	//没限位为1,有使能为0：MG_LFX
	char szRes[80]={0};
	g_cController.Command("MG_HMX",szRes,sizeof(szRes));
	l_iValueServoSH[0] = atoi(szRes);
	g_cController.Command("MG_HMY",szRes,sizeof(szRes));
	l_iValueServoSH[1] = atoi(szRes);
	g_cController.Command("MG_HMZ",szRes,sizeof(szRes));
	l_iValueServoSH[2] = atoi(szRes);
	g_cController.Command("MG_HMW",szRes,sizeof(szRes));
	l_iValueServoSH[3] = atoi(szRes);
	g_cController.Command("MG_HME",szRes,sizeof(szRes));
	l_iValueServoSH[4] = atoi(szRes);
	g_cController.Command("MG_HMF",szRes,sizeof(szRes));
	l_iValueServoSH[5] = atoi(szRes);
	g_cController.Command("MG_HMG",szRes,sizeof(szRes));
	l_iValueServoSH[6] = atoi(szRes);
	l_iValueServoSH[7] = 0;
	for(i=0; i<8; i++)
	{//算成TI值一样			哪一位点是1，并在那点剩其对应的值。就是把8个点的二进制转成十进制
		l_iReturn += (long)(pow(2, i) * l_iValueServoSH[i]);
	}
	return l_iReturn;
}

/*
 *	线程1，下载DMC命令，让机器切割。
 */		
DWORD CBallCutDlg::ThreadDownloadDMC(LPVOID lpParam)
{
	CBallCutDlg* pDlg = (CBallCutDlg*)lpParam;	
	pDlg->m_iBreakThread = 2;			//线程运行标志
	//给球切割点数据的动态库，传参数
	pDlg->m_CBallCutDll->SetAglMore(pDlg->m_stcParamWork.OverCut);
	switch(pDlg->m_iWhichProduct)
	{
	case 1://四壳球赤道
		pDlg->Cut4StyleBall(1);
		break;	
	case 2://四壳球极中
		pDlg->Cut4StyleBall(2);
		break;
	case 3://四壳球极侧
		pDlg->Cut4StyleBall(3);
		break;
	case 4://四壳球极边
		pDlg->Cut4StyleBall(4);
		break;
	case 5://四壳球赤道
		pDlg->Cut4StyleBall(5);
		break;
	case 6://三壳球极中
		pDlg->Cut4StyleBall(6);
		break;
	case 7://三球壳极边
		pDlg->Cut4StyleBall(7);
		break;
	default:
		break;
	}
	pDlg->m_iBreakThread = 0;	
	return 0;
}

/*
 *	时间显示
 */
void CBallCutDlg::OnSystemTimer()
{
	SYSTEMTIME st;
	CString		strDate, strTime;	
	GetLocalTime(&st);	
	strTime.Format("%02d:%02d:%02d",st.wHour, st.wMinute, st.wSecond);
	m_CapTime.SetCaption(strTime);
}

/*
 *	得到插补速度
 */
double CBallCutDlg::GetSpeedVecter(double SX,double SY,double SZ,double SA,double SB,double SC)
{
	double l_dTime = sqrt(SX*SX + SY*SY + SZ*SZ)/g_dCutSpeed;//求每段插补用的时间
	//求ABC轴的速度 
	double l_dVA = SA/l_dTime;
	double l_dVB = SB/l_dTime;
	double l_dVC = SC/l_dTime;
	//求六轴的插补速度
	double l_dVCaBu = sqrt(g_dCutSpeed*g_dCutSpeed + l_dVC*l_dVC + l_dVB*l_dVB + l_dVA*l_dVA);
	//加完脉冲当量的插补速度 
	return l_dVCaBu*g_dPulseX;
}

/*
 *	得到钟表的头
 */
POSITION CBallCutDlg::GetHeadPos(int CutStyle)
{
	POSITION POS;	
	switch(CutStyle)
	{
	case 1://四赤道
		m_CBallCutDll->GetEquator();
		POS = m_CBallCutDll->m_lstEquator.GetHeadPosition();  
		break;
	case 2://四极中
		m_CBallCutDll->GetCenter();
		POS = m_CBallCutDll->m_lstCenter.GetHeadPosition();
		break;
	case 3://四极侧
		m_CBallCutDll->GetEdge();
		POS = m_CBallCutDll->m_lstEdge.GetHeadPosition();
		break;
	case 4://四极边   m_stcParamFourBall.Ball4SG没有用到
		m_CBallCutDll->GetSide();
		POS = m_CBallCutDll->m_lstSide.GetHeadPosition();
		
		break;
	case 5://三赤道
		m_CBallCutDll2.GetEquator(g_pMainDlg->m_stcParamThreeBall.Ball3EA,g_pMainDlg->m_stcParamThreeBall.Ball3EB,
			g_pMainDlg->m_stcParamThreeBall.Ball3EAA,g_pMainDlg->m_stcParamThreeBall.Ball3EBA);
		POS = m_CBallCutDll2.GetLstEquator()->GetHeadPosition();
		break;
	case 6://三极中
		m_CBallCutDll2.GetCenter(g_pMainDlg->m_stcParamThreeBall.Ball3CB,g_pMainDlg->m_stcParamThreeBall.Ball3CG,
			g_pMainDlg->m_stcParamThreeBall.Ball3CA,g_pMainDlg->m_stcParamThreeBall.Ball3CBA,
			g_pMainDlg->m_stcParamThreeBall.Ball3CGA);
		POS = m_CBallCutDll2.GetLstCenter()->GetHeadPosition();
		break;
	case 7://三极边
		m_CBallCutDll2.GetEdge(g_pMainDlg->m_stcParamThreeBall.Ball3SA,g_pMainDlg->m_stcParamThreeBall.Ball3SAA,
			g_pMainDlg->m_stcParamThreeBall.Ball3SG,g_pMainDlg->m_stcParamThreeBall.Ball3SB,
			g_pMainDlg->m_stcParamThreeBall.Ball3EA,g_pMainDlg->m_stcParamThreeBall.Ball3CG);
		POS = m_CBallCutDll2.GetLstEdge()->GetHeadPosition();
		break;
	default:
		break;
	}
	return POS;
}

/*
 *	切割球的工艺
 */
void CBallCutDlg::Cut4StyleBall(int CutStyle)
{
	//将赤道上点的数据写入文件
	CStdioFile file;
	file.Open(".\\基本面.txt", CStdioFile::modeCreate | CStdioFile::modeReadWrite);
	CString str;

	BALLDATA l_listDMCDate;		//数据链表里的对象
	memset(&l_listDMCDate,0,sizeof(l_listDMCDate));
	double l_dCmdX=0,l_dCmdY=0,l_dCmdZ=0,l_dCmdW=0,l_dCmdF=0,l_dCmdE=0,l_dSpeedCut;	
	double l_dCenterOffSet = m_stcParamWork.CenterOffset;
	//计数下到多少个开始BGS, 从第三个角开切
	int l_iBGSCount = 0,     l_iNseq = 3;	
	CString l_strDMCCommand;		
	char l_chDMCCommand[80]={0};
	POSITION pose = GetHeadPos(CutStyle);//链表的结点
	//得到数每个轴运动的点
	l_listDMCDate = GetPointData(CutStyle,pose);
	//链表出来的是绝对位置，以下是转成相对位置
	l_dCmdX=l_listDMCDate.ptPara.x;
	l_dCmdY=l_listDMCDate.ptPara.y;
	l_dCmdZ=l_listDMCDate.ptPara.z+l_dCenterOffSet;
	l_dCmdW=l_listDMCDate.aglPara.a;
	l_dCmdE=l_listDMCDate.aglPara.b;
	l_dCmdF=l_listDMCDate.aglPara.c;	//给GALIL发送命令：设定插补，加减速，速度，
	l_dSpeedCut = GetSpeedVecter(l_dCmdX,l_dCmdY,l_dCmdZ,l_dCmdW,l_dCmdE,l_dCmdF);
	l_strDMCCommand.Format("LMABCDEF;VS%d;VA%d;VD%d",(int)(l_dSpeedCut*5),(int)(g_dCutAdd*g_dPulseX),(int)(g_dCutSub*g_dPulseX));
	strcpy(l_chDMCCommand,l_strDMCCommand);
	g_cController.Command(l_chDMCCommand);
	//给GALIL发送命令：走到对刀点的位置
	l_strDMCCommand.Format("LI%d,%d,%d,%d,%d,%d", \
		(int)(l_dCmdX*g_dPulseX+0.5), (int)(l_dCmdY*g_dPulseY+0.5),(int)(l_dCmdZ*g_dPulseZ+0.5),\
		(int)(l_dCmdW*g_dPulseA+0.5), (int)(l_dCmdE*g_dPulseB+0.5),(int)(l_dCmdF*g_dPulseC+0.5));
	//以下是下对刀的LI命令
	strcpy(l_chDMCCommand,l_strDMCCommand);
	g_cController.Command(l_chDMCCommand);
	g_cController.Command("LE;BGS");
	//以下是：直到走到对刀点才向下走，若是切割模式的话要到对刀点开始输出两个点。
	while (1)	
	{
		if (m_iBreakThread == 1) //跳出线程的变量，当为1时跳出
		{
			break;
		}	
		g_cController.Command("MG_BGS",l_chDMCCommand,sizeof(l_chDMCCommand));
		if (0 == atoi(l_chDMCCommand))	//	切割完要关掉输出 点
		{
			break;
		}
		Sleep(100);
	}
	Sleep(2000);
	//到下一结点
	GetNextPos(CutStyle,pose);
	//以下是进入切割工件
	g_cController.Command("LMABCDEF");
	while (pose != NULL) 
	{
		l_iBGSCount++;
		if (m_iBreakThread == 1) //跳出线程的变量，当为1时跳出
		{
			break;
		}	
		//得到下一点的数据
		l_listDMCDate = GetPointData(CutStyle,pose);
		//链表出来的是绝对位置，以下是转成相对位置
		l_dCmdX=l_listDMCDate.ptPara.x;
		l_dCmdY=l_listDMCDate.ptPara.y;
		l_dCmdZ=l_listDMCDate.ptPara.z;
		l_dCmdW=l_listDMCDate.aglPara.a;
		l_dCmdE=l_listDMCDate.aglPara.b;
		l_dCmdF=l_listDMCDate.aglPara.c;
		l_dSpeedCut = GetSpeedVecter(l_dCmdX,l_dCmdY,l_dCmdZ,l_dCmdW,l_dCmdE,l_dCmdF);
		str.Format("%4d,%10.1f\r\n",l_iBGSCount,l_dSpeedCut);	
		file.WriteString(str);
		if(l_listDMCDate.nSeq == l_iNseq)//如果到边的最后一点时要转角
		{
			l_dSpeedCut = 20000;
			l_iNseq--;
		}
		l_strDMCCommand.Format("LI%d,%d,%d,%d,%d,%d<%d", \
			(int)(l_dCmdX*g_dPulseX+0.5), (int)(l_dCmdY*g_dPulseY+0.5),(int)(l_dCmdZ*g_dPulseZ+0.5),\
			(int)(l_dCmdW*g_dPulseA+0.5), (int)(l_dCmdE*g_dPulseB+0.5),(int)(l_dCmdF*g_dPulseC+0.5),(int)(l_dSpeedCut+0.5));
		strcpy(l_chDMCCommand,l_strDMCCommand);
		g_cController.Command(l_chDMCCommand);
		if (l_iBGSCount == 100)//下到100句时就要开始切割了
		{
			l_strDMCCommand.Format("LE;VS%d;BGS",(int)(l_dSpeedCut));
			strcpy(l_chDMCCommand,l_strDMCCommand);
			g_cController.Command(l_chDMCCommand);
		}
		g_cController.Command("MG_LM",l_chDMCCommand,sizeof(l_chDMCCommand));
		while (atoi(l_chDMCCommand)<100) //galil缓存多于400就要停止，不要再下了;
		{
			if (m_iBreakThread == 1) //跳出线程的变量，当为1时跳出
			{
				break;
			}	
			Sleep(500);
			g_cController.Command("MG_LM",l_chDMCCommand,sizeof(l_chDMCCommand));
		}			
		//到下一结点
		GetNextPos(CutStyle,pose);			
	}
	file.Close();
	//当走完所有的点时退出，若是切割模式的话要取消两个输出 
	while (1)	
	{
		if (m_iBreakThread == 1) //跳出线程的变量，当为1时跳出
			break;	
		g_cController.Command("MG_BGS",l_chDMCCommand,sizeof(l_chDMCCommand));
		if (0 == atoi(l_chDMCCommand))	//	切割完要关掉输出 点
		{
			break;
		}
		Sleep(200);
	}
	//走完所有的点然后回零动作
	l_strDMCCommand.Format("PA0,0,0,0,0,0;SP%d,%d,%d,%d,%d,%d;BGABCDEF",(int)(g_dZeroSpeedX*g_dPulseX),
		(int)(g_dZeroSpeedY*g_dPulseY),(int)(g_dZeroSpeedZ*g_dPulseZ),(int)(g_dZeroSpeedA*g_dPulseA),
		(int)(g_dZeroSpeedB*g_dPulseB),(int)(g_dZeroSpeedC*g_dPulseC));
	strcpy(l_chDMCCommand,l_strDMCCommand);
	if(m_iBreakThread != 1)
		g_cController.Command(l_chDMCCommand);	
	//当所有的轴都走完，退出线程
	while(1)
	{
		if (m_iBreakThread == 1) //跳出线程的变量，当为1时跳出
		{
			break;
		}
		g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chDMCCommand,sizeof(l_chDMCCommand));
		if(atoi(l_chDMCCommand) == 0)	
		{
			break;
		}
		Sleep(200);
	}
}

//根据不同的球壳，得到不同的点的数据
BALLDATA CBallCutDlg::GetPointData(int CutStyle,POSITION& POS)
{
	BALLDATA l_listDMCDate;		//数据链表里的对象
	memset(&l_listDMCDate,0,sizeof(l_listDMCDate));
	switch(CutStyle)
	{
	case 1://四赤道
		l_listDMCDate = m_CBallCutDll->m_lstEquator.GetAt(POS);			
		break;
	case 2://四极中
		l_listDMCDate = m_CBallCutDll->m_lstCenter.GetAt(POS);
		break;
	case 3://四极侧
		l_listDMCDate = m_CBallCutDll->m_lstEdge.GetAt(POS);
		break;
	case 4://四极边
		l_listDMCDate = m_CBallCutDll->m_lstSide.GetAt(POS);
		break;
	case 5://三赤道
		l_listDMCDate = m_CBallCutDll2.GetLstEquator()->GetAt(POS);
		break;
	case 6://三极中
		l_listDMCDate = m_CBallCutDll2.GetLstCenter()->GetAt(POS);
		break;
	case 7://三极边
		l_listDMCDate = m_CBallCutDll2.GetLstEdge()->GetAt(POS);
		break;
	default:
		break;
	}
	return l_listDMCDate;
}

//根据不同的球壳，得到下一点的结点
void CBallCutDlg::GetNextPos(int CutStyle,POSITION& POS)
{
	switch(CutStyle)
	{
	case 1://四赤道
		m_CBallCutDll->m_lstEquator.GetNext(POS);
		break;
	case 2://四极中
		m_CBallCutDll->m_lstCenter.GetNext(POS);
		break;
	case 3://四极侧
		m_CBallCutDll->m_lstEdge.GetNext(POS);
		break;
	case 4://四极边
		m_CBallCutDll->m_lstSide.GetNext(POS);
		break;
	case 5://三赤道
		m_CBallCutDll2.GetLstEquator()->GetNext(POS);
		break;
	case 6://三极中
		m_CBallCutDll2.GetLstCenter()->GetNext(POS);
		break;
	case 7://三极边
		m_CBallCutDll2.GetLstEdge()->GetNext(POS);
		break;
	default:
		break;
	}
}

void CBallCutDlg::OnClickBtn3equtor() 
{
	// TODO: Add your control notification handler code here
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);
	m_ctl4Equtor.SetForeColor(0);
	m_ctl4Side.SetForeColor(0);
	m_ctl4Center.SetForeColor(0);
	m_ctl4Edge.SetForeColor(0);
	m_ctl3Side.SetForeColor(0);
	m_ctl3Equtor.SetForeColor(255);
	m_ctl3Center.SetForeColor(0);
	m_iWhichProduct = 5;
}

void CBallCutDlg::OnClickBtn3center() 
{
	// TODO: Add your control notification handler code here
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(FALSE);
	m_ctl4Equtor.SetForeColor(0);
	m_ctl4Side.SetForeColor(0);
	m_ctl4Center.SetForeColor(0);
	m_ctl4Edge.SetForeColor(0);
	m_ctl3Side.SetForeColor(0);
	m_ctl3Equtor.SetForeColor(0);
	m_ctl3Center.SetForeColor(255);
	m_iWhichProduct = 6;	
}

void CBallCutDlg::OnClickBtn3side() 
{
	// TODO: Add your control notification handler code here
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	GetDlgItem(IDC_STATIC_EQUATOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_SIDE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_POLE_EDGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3EQUTOR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3CENTER)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_3SIDE)->ShowWindow(TRUE);
	m_ctl4Equtor.SetForeColor(0);
	m_ctl4Side.SetForeColor(0);
	m_ctl4Center.SetForeColor(0);
	m_ctl4Edge.SetForeColor(0);
	m_ctl3Side.SetForeColor(255);
	m_ctl3Equtor.SetForeColor(0);
	m_ctl3Center.SetForeColor(0);
	m_iWhichProduct = 7;	
}

//预热
void CBallCutDlg::OnBtnHotGas()
{
	if (FALSE == m_bFlagSB7)
	{
		m_cBtnHotGas.SelectState(IDB_BITMAP3);
		m_bFlagSB7 = TRUE;
		g_cController.Command("SB7");
	}
	else
	{
		m_cBtnHotGas.SelectState(IDB_BITMAP2);
		m_bFlagSB7 = FALSE;
		g_cController.Command("CB7");
	}
}


//乙炔
void CBallCutDlg::OnBtnFireGas()
{
	if (FALSE == m_bFlagSB6)
	{
		m_cBtnFireGas.SelectState(IDB_BITMAP3);
		m_bFlagSB6 = TRUE;
		g_cController.Command("SB6");
	}
	else
	{
		m_cBtnFireGas.SelectState(IDB_BITMAP2);
		m_bFlagSB6 = FALSE;
		g_cController.Command("CB6");
	}
}

//切割氧
void CBallCutDlg::OnBtnCutGas()
{
	if (FALSE == m_bFlagSB17)
	{
		m_cBtnCutGas.SelectState(IDB_BITMAP3);
		m_bFlagSB17 = TRUE;
		g_cController.Command("SB17");
	}
	else
	{
		m_cBtnCutGas.SelectState(IDB_BITMAP2);
		m_bFlagSB17 = FALSE;
		g_cController.Command("CB17");
	}
}
//放气
void CBallCutDlg::OnBtnReleaseGas()
{
	if (FALSE == m_bFlagSB8)
	{
		m_cBtnReleaseGas.SelectState(IDB_BITMAP3);
		m_bFlagSB8 = TRUE;
		g_cController.Command("SB8");
	}
	else
	{
		m_cBtnReleaseGas.SelectState(IDB_BITMAP2);
		m_bFlagSB8 = FALSE;
		g_cController.Command("CB8");
	}
}

void CBallCutDlg::OnClickBtnSetZore() 
{
	// TODO: Add your control notification handler code here
//	g_cController.Command("DP0,0,0,0,0,0,0,0;DE0,0,0,0,0,0,0,0");
}

void CBallCutDlg::OnClickBtnPos650() 
{
	// TODO: Add your control notification handler code here
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)		
	{
		DMCRuningMessage();
		return;
	}
	CString str;
	char szDmc[80]={0};
	str.Format("pos=%d",(int)(m_stcParamWork.Position650*g_dPulseX));
	strcpy(szDmc,str);
	g_cController.Command(szDmc);
	Sleep(100);
	strcpy(szDmc,g_strPathC + "Positon.dmc");	
	g_cController.DownloadFile(szDmc);
	Sleep(100);
	g_cController.Command("XQ");
}
