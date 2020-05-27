// DlgZero.cpp : implementation file
//

#include "stdafx.h"
#include "BallCut.h"
#include "DlgZero.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgZero dialog


CDlgZero::CDlgZero(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgZero::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgZero)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));
}

CDlgZero::~CDlgZero()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}

void CDlgZero::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgZero)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgZero, CDialog)
	//{{AFX_MSG_MAP(CDlgZero)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_HOME_MACHINE, OnBtnHomeMachine)
	ON_BN_CLICKED(IDC_BTN_HOME_SOFT, OnBtnHomeSoft)
	ON_BN_CLICKED(IDC_BTN_HOME_ALL, OnBtnHomeAll)
	ON_BN_CLICKED(IDC_BTN_HOME_STOP, OnBtnHomeStop)
	ON_BN_CLICKED(IDC_BTN_HOMEX, OnBtnHomeX)
	ON_BN_CLICKED(IDC_BTN_HOMEY, OnBtnHomeY)
	ON_BN_CLICKED(IDC_BTN_HOMEZ, OnBtnHomeZ)
	ON_BN_CLICKED(IDC_BTN_HOMEA, OnBtnHomeA)
	ON_BN_CLICKED(IDC_BTN_HOMEB, OnBtnHomeB)
	ON_BN_CLICKED(IDC_BTN_HOMEC, OnBtnHomeC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgZero message handlers

BOOL CDlgZero::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	MoveWindow(724,328,301,382);						//窗口的位置
	InitBtn();											//初始化按钮
	m_cZeroMachine.SelectState(IDB_BITMAP_HOMEM3);		//让机械回零按钮变红
	m_iMachineOrSoft=0;									//当为0时是机械回零当为1时是PA回零	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CDlgZero::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if (nCtlColor==CTLCOLOR_DLG)
	{
	return (HBRUSH)m_brush.GetSafeHandle();
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgZero::InitBtn()
{
	HRGN c;	
	c = CreateRectRgn(0, 0, 0, 0);
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_HOME1);		
	//X轴回零
	m_cZeroX.SetFont(&g_cFontEdit);
	m_cZeroX.SetBitMapID(IDB_BITMAP_HOME2,IDB_BITMAP_HOME1);	
	m_cZeroX.Create("X", WS_CHILD | WS_VISIBLE, CPoint(12, 238), c, this,IDC_BTN_HOMEX); 	
	//Y轴回零
	m_cZeroY.SetFont(&g_cFontEdit);
	m_cZeroY.SetBitMapID(IDB_BITMAP_HOME2,IDB_BITMAP_HOME1);	
	m_cZeroY.Create("Y", WS_CHILD | WS_VISIBLE, CPoint(108, 238), c, this,IDC_BTN_HOMEY);
	//Z轴回零
	m_cZeroZ.SetFont(&g_cFontEdit);
	m_cZeroZ.SetBitMapID(IDB_BITMAP_HOME2,IDB_BITMAP_HOME1);
	m_cZeroZ.Create("Z", WS_CHILD | WS_VISIBLE, CPoint(204, 238), c, this,IDC_BTN_HOMEZ); 
	//A轴回零
	m_cZeroA.SetFont(&g_cFontEdit);
	m_cZeroA.SetBitMapID(IDB_BITMAP_HOME2,IDB_BITMAP_HOME1);
	m_cZeroA.Create("A", WS_CHILD | WS_VISIBLE, CPoint(12, 318), c, this,IDC_BTN_HOMEA); 
	//B轴回零
	m_cZeroB.SetFont(&g_cFontEdit);
	m_cZeroB.SetBitMapID(IDB_BITMAP_HOME2,IDB_BITMAP_HOME1);
	m_cZeroB.Create("B", WS_CHILD | WS_VISIBLE, CPoint(108, 318), c, this,IDC_BTN_HOMEB); 
	//C轴回零
	m_cZeroC.SetFont(&g_cFontEdit);
	m_cZeroC.SetBitMapID(IDB_BITMAP_HOME2,IDB_BITMAP_HOME1);
	m_cZeroC.Create("C", WS_CHILD | WS_VISIBLE, CPoint(204, 318), c, this,IDC_BTN_HOMEC); 
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_HOMES1);	
	//机械零点
	m_cZeroMachine.SetFont(&g_cFontEdit);
	m_cZeroMachine.SetBitMapID(IDB_BITMAP_HOMEM1,IDB_BITMAP_HOMEM2);
	m_cZeroMachine.Create("机械零点", WS_CHILD | WS_VISIBLE, CPoint(9, 48), c, this,IDC_BTN_HOME_MACHINE); 
	//程序零点
	m_cZeroSofe.SetFont(&g_cFontEdit);
	m_cZeroSofe.SetBitMapID(IDB_BITMAP_HOMES1,IDB_BITMAP_HOMES2);
	m_cZeroSofe.Create("程序零点", WS_CHILD | WS_VISIBLE, CPoint(9, 148), c, this,IDC_BTN_HOME_SOFT); 
	//所有轴回零
	m_cZeroAll.SetFont(&g_cFontEdit);
	m_cZeroAll.SetBitMapID(IDB_BITMAP_HOMEM1,IDB_BITMAP_HOMEM2);
	m_cZeroAll.Create("同时", WS_CHILD | WS_VISIBLE, CPoint(159, 48), c, this,IDC_BTN_HOME_ALL); 
	//停止
	m_cZeroStop.SetFont(&g_cFontEdit);	
	m_cZeroStop.SetBitMapID(IDB_BITMAP_HOME_STOP2,IDB_BITMAP_HOME_STOP1);
	m_cZeroStop.Create("停止", WS_CHILD | WS_VISIBLE, CPoint(159, 148), c, this,IDC_BTN_HOME_STOP); 
	DeleteObject(c);	
}

/*
 *	机械回零按钮
 */
void CDlgZero::OnBtnHomeMachine()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	m_iMachineOrSoft=0;
	m_cZeroMachine.SelectState(IDB_BITMAP_HOMEM3);
	m_cZeroSofe.SelectState(0);	
}

/*
 *	程序回零按钮
 */
void CDlgZero::OnBtnHomeSoft()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	m_iMachineOrSoft=1;
	m_cZeroSofe.SelectState(IDB_BITMAP_HOMES3);
	m_cZeroMachine.SelectState(0);		
}

/*
 *	所有轴回零按钮
 */
void CDlgZero::OnBtnHomeAll()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeAll.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();	
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA0,0,0,0,0,0;BGXYZWEF");
		else
		{
			NoHomeMessage();
		}
	}	
}

/*
 *	回零停止按钮
 */
void CDlgZero::OnBtnHomeStop()
{
	g_cController.Command("ST");
	Sleep(40);
	g_cController.Command("STXYZ");
}

/*
 *	X回零按钮
 */
void CDlgZero::OnBtnHomeX()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeX.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();	
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA0;BGX");
		else
		{
			NoHomeMessage();
		}
	}
}

/*
 *	Y回零按钮
 */
void CDlgZero::OnBtnHomeY()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeY.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA,0;BGY");
		else
		{
			NoHomeMessage();
		}
	}	
}

/*
 *	Z回零按钮
 */
void CDlgZero::OnBtnHomeZ()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeZ.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA,,0;BGZ");
		else
		{
			NoHomeMessage();
		}
	}	
}

/*
 *	A回零按钮
 */
void CDlgZero::OnBtnHomeA()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeA.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA,,,0;BGD");
		else
		{
			NoHomeMessage();
		}
	}	
}

/*
 *	B回零按钮
 */
void CDlgZero::OnBtnHomeB()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeB.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA,,,,0;BGE");
		else
		{
			NoHomeMessage();
		}
	}	
}

/*
 *	C回零按钮
 */
void CDlgZero::OnBtnHomeC()
{
	char l_chReturnIsBG[80]={0};
	g_cController.Command("MG_BGA|_BGB|_BGC|_BGD|_BGE|_BGF|_BGG",l_chReturnIsBG,sizeof(l_chReturnIsBG));
	if(atoi(l_chReturnIsBG) || g_cHandDll.GetCommandFloat("MG_XQ")>=0.0)	
	{
		DMCRuningMessage();
		return;
	}
	if(m_iMachineOrSoft==0)			
	{
		char szDmc[80]={0};
		strcpy(szDmc,g_strPathC + "HomeC.dmc");
		long l_lResponse = 0;
		l_lResponse = g_cController.DownloadFile(szDmc);
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}	
		l_lResponse = g_cController.Command("XQ");
		if (l_lResponse != 0)
		{
			CommunicationErrorMessage();
			return;
		}
	}
	else    
	{
		char chZero[80] = {0};
		g_cController.Command("MG homecx&homecy&homecz&homecw&homece&homecf",chZero,sizeof(chZero));
		if(atoi(chZero) == 1)
			g_cController.Command("PA,,,,,0;BGF");
		else
		{
			NoHomeMessage();
		}
	}	
}









