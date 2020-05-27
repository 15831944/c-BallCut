// DlgHand.cpp : implementation file
//

#include "stdafx.h"
#include "BallCut.h"
#include "DlgHand.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgHand dialog


CDlgHand::CDlgHand(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHand::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgHand)
	m_dPRA = 0.0;
	m_dPRB = 0.0;
	m_dPRC = 0.0;
	m_dPRX = 0.0;
	m_dPRY = 0.0;
	m_dPRZ = 0.0;
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));
}

CDlgHand::~CDlgHand()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}

void CDlgHand::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgHand)
	DDX_Control(pDX, IDC_EDIT_PRZ, m_ctlPRZ);
	DDX_Control(pDX, IDC_EDIT_PRY, m_ctlPRY);
	DDX_Control(pDX, IDC_EDIT_PRX, m_ctlPRX);
	DDX_Control(pDX, IDC_EDIT_PRC, m_ctlPRC);
	DDX_Control(pDX, IDC_EDIT_PRB, m_ctlPRB);
	DDX_Control(pDX, IDC_EDIT_PRA, m_ctlPRA);
	DDX_Text(pDX, IDC_EDIT_PRA, m_dPRA);
	DDX_Text(pDX, IDC_EDIT_PRB, m_dPRB);
	DDX_Text(pDX, IDC_EDIT_PRC, m_dPRC);
	DDX_Text(pDX, IDC_EDIT_PRX, m_dPRX);
	DDX_Text(pDX, IDC_EDIT_PRY, m_dPRY);
	DDX_Text(pDX, IDC_EDIT_PRZ, m_dPRZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgHand, CDialog)
	//{{AFX_MSG_MAP(CDlgHand)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_HANDXF, OnBtnHandXF)
	ON_BN_CLICKED(IDC_BTN_HANDXR, OnBtnHandXR)
	ON_BN_CLICKED(IDC_BTN_HANDYF, OnBtnHandYF)
	ON_BN_CLICKED(IDC_BTN_HANDYR, OnBtnHandYR)
	ON_BN_CLICKED(IDC_BTN_HANDZF, OnBtnHandZF)
	ON_BN_CLICKED(IDC_BTN_HANDZR, OnBtnHandZR)
	ON_BN_CLICKED(IDC_BTN_HANDAF, OnBtnHandAF)
	ON_BN_CLICKED(IDC_BTN_HANDAR, OnBtnHandAR)
	ON_BN_CLICKED(IDC_BTN_HANDBF, OnBtnHandBF)
	ON_BN_CLICKED(IDC_BTN_HANDBR, OnBtnHandBR)
	ON_BN_CLICKED(IDC_BTN_HANDCF, OnBtnHandCF)
	ON_BN_CLICKED(IDC_BTN_HANDCR, OnBtnHandCR)
	ON_BN_CLICKED(IDC_BTN_HAND_STOP, OnBtnHandStop)
	ON_BN_CLICKED(IDC_BTN_HAND_MOTION_STYLE, OnBtnHandMotionStyle)
	ON_BN_CLICKED(IDC_BTN_HAND_BAGEN, OnBtnHandBagen)
	ON_MESSAGE(WM_MOUSEDN,OnMouseDn)
	ON_MESSAGE(WM_EDITDOUBLE,OnEditDouble)					//系统消息

	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CDlgHand message handlers

BOOL CDlgHand::OnInitDialog() 
{
	CDialog::OnInitDialog();
	MoveWindow(724,328,301,382);
	InitBtn();											//初始化按钮	
	InitData();											//初始化手动按钮界面的数据
	
	l_iHandMotionStyle=5;								//手动界面里选择手动方式会用到	

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDlgHand::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CDlgHand::InitBtn()
{
	HRGN c;	
	c = CreateRectRgn(0, 0, 0, 0);
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_HANDAUX1);		
	//X轴正
	m_cHandXF.HaveBitmap(1);
	m_cHandXF.SetFont(&g_cFontEdit);
	m_cHandXF.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandXF.Create("X+", WS_CHILD | WS_VISIBLE, CPoint(9, 9), c, this,IDC_BTN_HANDXF); 
	//X轴负
	m_cHandXR.HaveBitmap(1);
	m_cHandXR.SetFont(&g_cFontEdit);
	m_cHandXR.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandXR.Create("X-", WS_CHILD | WS_VISIBLE, CPoint(79, 9), c, this,IDC_BTN_HANDXR); 	
	//Y轴正
	m_cHandYF.HaveBitmap(1);
	m_cHandYF.SetFont(&g_cFontEdit);
	m_cHandYF.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandYF.Create("Y+", WS_CHILD | WS_VISIBLE, CPoint(9, 69), c, this,IDC_BTN_HANDYF); 
	//Y轴负
	m_cHandYR.HaveBitmap(1);
	m_cHandYR.SetFont(&g_cFontEdit);
	m_cHandYR.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandYR.Create("Y-", WS_CHILD | WS_VISIBLE, CPoint(79, 69), c, this,IDC_BTN_HANDYR); 
	//Z轴正
	m_cHandZF.HaveBitmap(1);
	m_cHandZF.SetFont(&g_cFontEdit);
	m_cHandZF.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandZF.Create("Z+", WS_CHILD | WS_VISIBLE, CPoint(9, 129), c, this,IDC_BTN_HANDZF); 
	//Z轴负
	m_cHandZR.HaveBitmap(1);
	m_cHandZR.SetFont(&g_cFontEdit);
	m_cHandZR.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandZR.Create("Z-", WS_CHILD | WS_VISIBLE, CPoint(79, 129), c, this,IDC_BTN_HANDZR); 
	//A轴正
	m_cHandAF.HaveBitmap(1);
	m_cHandAF.SetFont(&g_cFontEdit);
	m_cHandAF.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandAF.Create("A+", WS_CHILD | WS_VISIBLE, CPoint(9, 189), c, this,IDC_BTN_HANDAF); 
	//A轴负
	m_cHandAR.HaveBitmap(1);
	m_cHandAR.SetFont(&g_cFontEdit);
	m_cHandAR.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandAR.Create("A-", WS_CHILD | WS_VISIBLE, CPoint(79, 189), c, this,IDC_BTN_HANDAR); 
	//B轴正
	m_cHandBF.HaveBitmap(1);
	m_cHandBF.SetFont(&g_cFontEdit);
	m_cHandBF.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandBF.Create("B+", WS_CHILD | WS_VISIBLE, CPoint(9, 249), c, this,IDC_BTN_HANDBF); 
	//B轴负
	m_cHandBR.HaveBitmap(1);	
	m_cHandBR.SetFont(&g_cFontEdit);
	m_cHandBR.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandBR.Create("B-", WS_CHILD | WS_VISIBLE, CPoint(79, 249), c, this,IDC_BTN_HANDBR); 
	//C轴正
	m_cHandCF.HaveBitmap(1);
	m_cHandCF.SetFont(&g_cFontEdit);
	m_cHandCF.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandCF.Create("C+", WS_CHILD | WS_VISIBLE, CPoint(9, 309), c, this,IDC_BTN_HANDCF); 
	//C轴负
	m_cHandCR.HaveBitmap(1);
	m_cHandCR.SetFont(&g_cFontEdit);
	m_cHandCR.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandCR.Create("C-", WS_CHILD | WS_VISIBLE, CPoint(79, 309), c, this,IDC_BTN_HANDCR); 
	//手动运动方式
	m_cHandMotionStyle.HaveBitmap(1);
	m_cHandMotionStyle.SetFont(&g_cFontEdit);
	m_cHandMotionStyle.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandMotionStyle.Create("连续", WS_CHILD | WS_VISIBLE, CPoint(149, 309), c, this,IDC_BTN_HAND_MOTION_STYLE); 
	//开始运动
	m_cHandBegan.HaveBitmap(1);
	m_cHandBegan.SetFont(&g_cFontEdit);
	m_cHandBegan.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandBegan.Create("运动", WS_CHILD | WS_VISIBLE, CPoint(219, 309), c, this,IDC_BTN_HAND_BAGEN); 
	//手动停止
	m_cHandStop.HaveBitmap(1);
	m_cHandStop.SetFont(&g_cFontEdit);
	m_cHandStop.SetBitMapID(IDB_BITMAP_HANDAUX1,IDB_BITMAP_HANDAUX2);	
	m_cHandStop.Create("停止", WS_CHILD | WS_VISIBLE, CPoint(219, 249), c, this,IDC_BTN_HAND_STOP); 
	DeleteObject(c);
	//初始化静态控件的字体
	GetDlgItem(IDC_RADIO_PA)->SetFont(&g_cFontStatic);
	GetDlgItem(IDC_RADIO_PR)->SetFont(&g_cFontStatic);
	for(int i=IDC_STATIC1;i<IDC_STATIC7;i++)	//让手动里的静态控件底色跟窗口一样
	{
		GetDlgItem(i)->SetFont(&g_cFontStatic);
	}
}

/*
 *	X轴正向按钮
 */
void CDlgHand::OnBtnHandXF()
{	
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STX");
}

/*
 *	X轴负向按钮
 */
void CDlgHand::OnBtnHandXR()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STX");
}

/*
 *	Y轴正向按钮
 */
void CDlgHand::OnBtnHandYF()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STY");
}

/*
 *	Y轴负向按钮
 */
void CDlgHand::OnBtnHandYR()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STY");
}

/*
 *	Z轴正向按钮
 */
void CDlgHand::OnBtnHandZF()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STZ");
}

/*
 *	Z轴负向按钮
 */
void CDlgHand::OnBtnHandZR()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STZ");
}

/*
 *	A轴正向按钮
 */
void CDlgHand::OnBtnHandAF()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STW");	
}

/*
 *	A轴负向按钮
 */
void CDlgHand::OnBtnHandAR()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STW");
}

/*
 *	B轴正向按钮
 */
void CDlgHand::OnBtnHandBF()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STE");
}

/*
 *	B轴负向按钮
 */
void CDlgHand::OnBtnHandBR()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STE");
}

/*
 *	C轴正向按钮
 */
void CDlgHand::OnBtnHandCF()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STF");
}

/*
 *	C轴负向按钮
 */
void CDlgHand::OnBtnHandCR()
{
	if(l_iHandMotionStyle==5)
		g_cHandDll.GalilCommand("STF");
}

/*
 *	 手动停止按钮
 */
void CDlgHand::OnBtnHandStop()
{
	g_cController.Command("ST");
	Sleep(40);
	g_cController.Command("STXYZWEFG");
}
/*
 *	选择点动还是连续按钮
 */
void CDlgHand::OnBtnHandMotionStyle()
{
	l_iHandMotionStyle++;
	if (6==l_iHandMotionStyle)
	{
		l_iHandMotionStyle = 1;
	}
	switch(l_iHandMotionStyle)		//手动界面里1：0.1）2：1）3：5）4：10）5：连续）
	{
	case 1:
		m_cHandMotionStyle.SetWindowText("0.1");
		break;
	case 2:
		m_cHandMotionStyle.SetWindowText("1");
		break;
	case 3:
		m_cHandMotionStyle.SetWindowText("5");
		break;
	case 4:
		m_cHandMotionStyle.SetWindowText("10");
		break;
	case 5:
		m_cHandMotionStyle.SetWindowText("连续");
		break;
	}
	m_cHandMotionStyle.RepeatDraw();
}

/*
 *	点动开始按钮
 */
void CDlgHand::OnBtnHandBagen()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	int l_iIsPa=((CButton*)GetDlgItem(IDC_RADIO_PA))->GetCheck();
	CString l_strX,l_strY,l_strZ,l_strA,l_strB,l_strC,l_strPR,l_strBG,l_strPA,l_strtemp;
	double l_dX,l_dY,l_dZ,l_dA,l_dB,l_dC;
	UpdateData(TRUE);	
	l_dX=m_dPRX*g_dPulseX;
	l_dY=m_dPRY*g_dPulseY;
	l_dZ=m_dPRZ*g_dPulseZ;
	l_dA=m_dPRA*g_dPulseA;
   	l_dB=m_dPRB*g_dPulseB;
 	l_dC=m_dPRC*g_dPulseC;
	if (l_dX == 0)		//x轴
	{	
		if (1 == l_iIsPa)    
		{
			l_strtemp="PA0";
		}
		else
		{
			l_strtemp="PR0";
			if (l_dX==0 && l_dY==0 && l_dZ==0 && l_dA==0 && l_dB==0 && l_dC==0)//如果是PR会看是不是都是零
			{
				return;
			}
		}
		l_strBG="BG";			
	}	
	else
	{
		if (1 == l_iIsPa)
		{
			l_strtemp.Format("PA%.0f",l_dX);
		}
		else	
		{
			l_strtemp.Format("PR%.0f",l_dX);
			if (l_dX==0 && l_dY==0 && l_dZ==0 && l_dA==0 && l_dB==0 && l_dC==0)//如果是PR会看是不是都是零
			{
				return;
			}
		}
		l_strBG.Format("BGX");
	}
	if (l_dY == 0)		//y轴
	{
		l_strtemp=l_strtemp+",0";
	}	
	else
	{
		l_strPA.Format(",%.0f",l_dY);
		l_strtemp=l_strtemp+l_strPA;
		l_strBG=l_strBG+"Y";
	}
	if (l_dZ == 0)		//z轴
	{
		l_strtemp=l_strtemp+",0";
	}	
	else
	{
		l_strPA.Format(",%.0f",l_dZ);
		l_strtemp=l_strtemp+l_strPA;
		l_strBG=l_strBG+"Z";
	}
	if (l_dA == 0)		//a轴
	{
		l_strtemp=l_strtemp+",0";
	}	
	else
	{
		l_strPA.Format(",%.0f",l_dA);
		l_strtemp=l_strtemp+l_strPA;
		l_strBG=l_strBG+"W";
	}
	if (l_dB == 0)		//b轴
	{
		l_strtemp=l_strtemp+",0";
	}	
	else
	{
		l_strPA.Format(",%.0f",l_dB);
		l_strtemp=l_strtemp+l_strPA;
		l_strBG=l_strBG+"E";
	}
	if (l_dC == 0)		//c轴
	{
		l_strtemp=l_strtemp+",0";
	}	
	else
	{
		l_strPA.Format(",%.0f",l_dC);
		l_strtemp=l_strtemp+l_strPA;
		l_strBG=l_strBG+"F";
	}
	char l_cGalilCmd[80]={0};
	strcpy(l_cGalilCmd,l_strtemp+";"+l_strBG);
	long l_lResponse=g_cController.Command(l_cGalilCmd);
	if (0!=l_lResponse) 
	{ 
		CommunicationErrorMessage();
	}
}

/*
 *	初始化手动界面按钮
 */
void CDlgHand::InitData()
{
	((CButton*)GetDlgItem(IDC_RADIO_PA))->SetCheck(1);	//初始化绝对单选框
//	((CButton*)GetDlgItem(IDC_RADIO_PR))->SetCheck(1);	//初始化相对单选框
	GetDlgItem(IDC_EDIT_PRX)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_PRX)->SetFont(&g_cFontButton);
	GetDlgItem(IDC_EDIT_PRY)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_PRY)->SetFont(&g_cFontButton);
	GetDlgItem(IDC_EDIT_PRZ)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_PRZ)->SetFont(&g_cFontButton);
	GetDlgItem(IDC_EDIT_PRA)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_PRA)->SetFont(&g_cFontButton);
	GetDlgItem(IDC_EDIT_PRB)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_PRB)->SetFont(&g_cFontButton);
	GetDlgItem(IDC_EDIT_PRC)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_PRC)->SetFont(&g_cFontButton);
}

/*
 *	鼠标按下后的函数
 */
LRESULT CDlgHand::OnMouseDn(WPARAM wParam, LPARAM lParam)
{
double l_dStepper;
switch(wParam) 
{
case IDC_BTN_HANDXF:		
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisAdd('A',l_dStepper);
	break;
case IDC_BTN_HANDXR:  
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisSub('A', l_dStepper);
	break;
case IDC_BTN_HANDYF: 
    if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisAdd('Y', l_dStepper);		
	break;
case IDC_BTN_HANDYR:    
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisSub('Y', l_dStepper);
	break;
case IDC_BTN_HANDZF: 
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisAdd('Z', l_dStepper);
	break;
case IDC_BTN_HANDZR:   
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisSub('Z', l_dStepper);
	break;
case IDC_BTN_HANDAF:
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisAdd('W', l_dStepper);
	break;
case IDC_BTN_HANDAR:  
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisSub('W', l_dStepper);			
	break;
case IDC_BTN_HANDBF:    
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisAdd('E', l_dStepper);
	break;
case IDC_BTN_HANDBR:  
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisSub('E', l_dStepper);			
	break;
case IDC_BTN_HANDCF:  
	if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisAdd('F', l_dStepper);
	break;
case IDC_BTN_HANDCR: 
    if(l_iHandMotionStyle==5)				l_dStepper = 0;
	else if(l_iHandMotionStyle==1)		    l_dStepper = 0.1;
	else if(l_iHandMotionStyle==2)	    	l_dStepper = 1;
	else if(l_iHandMotionStyle==3)	    	l_dStepper = 5;
	else if(l_iHandMotionStyle==4)		    l_dStepper = 10;
	else	                     			l_dStepper = 0;
	g_cHandDll.handAxisSub('F', l_dStepper);		
	break;
default:										
	break;
}
	return 0;
}

/*
 *	触摸屏WIN消息函数触发
 */
 LRESULT CDlgHand::OnEditDouble(WPARAM wParam, LPARAM lParam) 
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
