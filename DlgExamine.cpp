// DlgExamine.cpp : implementation file
//

#include "stdafx.h"
#include "BallCut.h"
#include "BallCutDlg.h"
#include "DlgExamine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgExamine dialog


CDlgExamine::CDlgExamine(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExamine::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExamine)
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));   //控件背景色的刷子	
}

CDlgExamine::~CDlgExamine()
{
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
}

void CDlgExamine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExamine)
	DDX_Control(pDX, IDC_LIST_ALARM, m_listAlarm);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_IN1, m_ctlDisplayIn1);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_IN2, m_ctlDisplayIn2);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_IN3, m_ctlDisplayIn3);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_OUT1, m_ctlDisplayOut1);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_IN4, m_ctlDisplayIn4);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_IN5, m_ctlDisplayIn5);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_IN6, m_ctlDisplayIn6);
	DDX_Control(pDX, IDC_DISPLAYCTRLCTRL_OUT2, m_ctlDisplayOut2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgExamine, CDialog)
	//{{AFX_MSG_MAP(CDlgExamine)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_BACKE, OnBtnBackE)
	ON_BN_CLICKED(IDC_BTN_ALAM, OnBtnAlam)
	ON_BN_CLICKED(IDC_BTN_IOPUT, OnBtnIOput)
	ON_BN_CLICKED(IDC_BTN_HISTORYALARM,OnBtnHistoryAlarm)
	ON_MESSAGE(WM_UPDATEINPUT,UpdateInput)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgExamine message handlers

void CDlgExamine::OnPaint() 
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

BOOL CDlgExamine::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设定窗口大小
	SetWindowPos(&CWnd::wndTop, 0, 0, 1024, 788, SWP_SHOWWINDOW);
	SetWindowText("Examine");	
	InitBtn();					//初始化主界面按钮
	InitList();					//报警列表初始化
	InitDisplay();				//初始化Display控件


	CBallCutDlg	*l_pdlg;
	l_pdlg = (CBallCutDlg*)FindWindow(NULL, "PNC2000BC");
	m_ctlDisplayIn4.SetDisplayData(255-l_pdlg->m_iNewInput[0]);
	m_ctlDisplayIn5.SetDisplayData(255-l_pdlg->m_iNewInput[1]);	
	m_ctlDisplayIn6.SetDisplayData(255-l_pdlg->m_iNewInput[2]);	
	m_ctlDisplayIn1.SetDisplayData(127-l_pdlg->m_iNewInput[5]);
	m_ctlDisplayIn2.SetDisplayData(127-l_pdlg->m_iNewInput[6]);	
	m_ctlDisplayIn3.SetDisplayData(127-l_pdlg->m_iNewInput[7]);	
	m_ctlDisplayOut1.SetDisplayData(l_pdlg->m_iNewInput[8]);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*
*	初始化所有按钮函数
*/
void CDlgExamine::InitBtn()
{
	HRGN c;	
	c = CreateRectRgn(0, 0, 0, 0);
	GetBitMapRgn(GetDC(),c,IDB_BITMAP_BACK2);		
	//报警
	m_cAlam.SetFont(&g_cFontEdit);
	m_cAlam.SetBitMapID(IDB_BITMAP_ALAM1,IDB_BITMAP_ALAM2);	
	m_cAlam.Create("报警", WS_CHILD | WS_VISIBLE, CPoint(707, 714), c, this,IDC_BTN_ALAM); 
	//返回
	m_cBackE.SetFont(&g_cFontEdit);
	m_cBackE.SetBitMapID(IDB_BITMAP_BACK1,IDB_BITMAP_BACK2);	
	m_cBackE.Create("返回", WS_CHILD | WS_VISIBLE, CPoint(877, 714), c, this, IDC_BTN_BACKE); 
	//IO点
	m_cIOput.SetFont(&g_cFontEdit);
	m_cIOput.SetBitMapID(IDB_BITMAP_IOPUT2,IDB_BITMAP_IOPUT1);	
	m_cIOput.Create("IO点", WS_CHILD | WS_VISIBLE, CPoint(367, 714), c, this, IDC_BTN_IOPUT); 
	//历史报警
	m_cHistoryAlarm.SetFont(&g_cFontEdit);
	m_cHistoryAlarm.SetBitMapID(IDB_BITMAP_HISTORYALARM1,IDB_BITMAP_HISTORYALARM2);	
	m_cHistoryAlarm.Create("历史报警", WS_CHILD | WS_VISIBLE, CPoint(537, 714), c, this, IDC_BTN_HISTORYALARM); 
	DeleteObject(c);	
}

/*
*	初始化list控件函数
*/
void CDlgExamine::InitList()
{
	m_listAlarm.ShowWindow(FALSE);
	m_listAlarm.SetFont(&g_cFontEdit);
	m_listAlarm.InsertColumn(0, "Time", LVCFMT_LEFT, 220, 3);
	m_listAlarm.InsertColumn(1, "Code", LVCFMT_LEFT, 80, 0);
	m_listAlarm.InsertColumn(2, "Grade", LVCFMT_LEFT, 80, 1);
	m_listAlarm.InsertColumn(3, "Content", LVCFMT_LEFT, 150, 2);
	m_listAlarm.InsertColumn(4, "State", LVCFMT_LEFT, 150, 2);
}

/*
 *	初始化Display控件
 */
void CDlgExamine::InitDisplay()
{
	//以下是输入点，设定他们的名字
	m_ctlDisplayIn1.SetDisplayName(1,"X限位+++");
	m_ctlDisplayIn1.SetDisplayName(2,"Y限位+++");
	m_ctlDisplayIn1.SetDisplayName(3,"Z限位+++");
	m_ctlDisplayIn1.SetDisplayName(4,"A限位+++");
	m_ctlDisplayIn1.SetDisplayName(5,"B限位+++");
	m_ctlDisplayIn1.SetDisplayName(6,"C限位+++");
	m_ctlDisplayIn1.SetDisplayName(7,"G限位+++");
	m_ctlDisplayIn1.SetDisplayName(8,"");
	
	m_ctlDisplayIn2.SetDisplayName(1,"X限位---");
	m_ctlDisplayIn2.SetDisplayName(2,"Y限位---");
	m_ctlDisplayIn2.SetDisplayName(3,"Z限位---");
	m_ctlDisplayIn2.SetDisplayName(4,"A限位---");
	m_ctlDisplayIn2.SetDisplayName(5,"B限位---");
	m_ctlDisplayIn2.SetDisplayName(6,"C限位---");
	m_ctlDisplayIn2.SetDisplayName(7,"G限位---");
	m_ctlDisplayIn2.SetDisplayName(8,"");
	
	m_ctlDisplayIn3.SetDisplayName(1,"X零点");
	m_ctlDisplayIn3.SetDisplayName(2,"Y零点");
	m_ctlDisplayIn3.SetDisplayName(3,"Z零点");
	m_ctlDisplayIn3.SetDisplayName(4,"A零点");
	m_ctlDisplayIn3.SetDisplayName(5,"B零点");
	m_ctlDisplayIn3.SetDisplayName(6,"C零点");
	m_ctlDisplayIn3.SetDisplayName(7,"G零点");
	m_ctlDisplayIn3.SetDisplayName(8,"");
	
	m_ctlDisplayIn6.SetDisplayName(1,"X报警");
	m_ctlDisplayIn6.SetDisplayName(2,"Y报警");
	m_ctlDisplayIn6.SetDisplayName(3,"Z报警");
	m_ctlDisplayIn6.SetDisplayName(4,"A报警");
	m_ctlDisplayIn6.SetDisplayName(5,"B报警");
	m_ctlDisplayIn6.SetDisplayName(6,"C报警");
	m_ctlDisplayIn6.SetDisplayName(7,"G报警");
	m_ctlDisplayIn6.SetDisplayName(8,"");

	m_ctlDisplayIn4.SetDisplayName(1,"输入点1");
	m_ctlDisplayIn4.SetDisplayName(2,"输入点2");
	m_ctlDisplayIn4.SetDisplayName(3,"输入点3");
	m_ctlDisplayIn4.SetDisplayName(4,"输入点4");
	m_ctlDisplayIn4.SetDisplayName(5,"输入点5");
	m_ctlDisplayIn4.SetDisplayName(6,"输入点6");
	m_ctlDisplayIn4.SetDisplayName(7,"输入点7");
	m_ctlDisplayIn4.SetDisplayName(8,"输入点8");

	m_ctlDisplayIn5.SetDisplayName(1,"输入点9");
	m_ctlDisplayIn5.SetDisplayName(2,"输入点10");
	m_ctlDisplayIn5.SetDisplayName(3,"输入点11");
	m_ctlDisplayIn5.SetDisplayName(4,"输入点12");
	m_ctlDisplayIn5.SetDisplayName(5,"输入点13");
	m_ctlDisplayIn5.SetDisplayName(6,"输入点14");
	m_ctlDisplayIn5.SetDisplayName(7,"输入点15");
	m_ctlDisplayIn5.SetDisplayName(8,"输入点16");

	m_ctlDisplayOut1.SetDisplayName(1,"输出点1");
	m_ctlDisplayOut1.SetDisplayName(2,"输出点2");
	m_ctlDisplayOut1.SetDisplayName(3,"输出点3");
	m_ctlDisplayOut1.SetDisplayName(4,"输出点4");
	m_ctlDisplayOut1.SetDisplayName(5,"输出点5");
	m_ctlDisplayOut1.SetDisplayName(6,"输出点6");
	m_ctlDisplayOut1.SetDisplayName(7,"输出点7");
	m_ctlDisplayOut1.SetDisplayName(8,"输出点8");
	
	m_ctlDisplayOut1.SetDisplayName(9,"输出点9");
	m_ctlDisplayOut1.SetDisplayName(10,"输出点10");
	m_ctlDisplayOut1.SetDisplayName(11,"输出点11");
	m_ctlDisplayOut1.SetDisplayName(12,"输出点12");
	m_ctlDisplayOut1.SetDisplayName(13,"输出点13");
	m_ctlDisplayOut1.SetDisplayName(14,"输出点14");
	m_ctlDisplayOut1.SetDisplayName(15,"输出点15");
	m_ctlDisplayOut1.SetDisplayName(16,"输出点16");
	
}

/*
 *	报警按钮函数
 */
void CDlgExamine::OnBtnAlam()
{
	m_listAlarm.MoveWindow(15, 40, 988, 648, TRUE);
	m_listAlarm.ShowWindow(TRUE);
	m_ctlDisplayOut1.ShowWindow(FALSE);
	m_ctlDisplayIn1.ShowWindow(FALSE);
	m_ctlDisplayIn2.ShowWindow(FALSE);
	m_ctlDisplayIn3.ShowWindow(FALSE);
	m_ctlDisplayIn4.ShowWindow(FALSE);
	m_ctlDisplayIn5.ShowWindow(FALSE);
	m_ctlDisplayIn6.ShowWindow(FALSE);
	ShowAlam(TRUE);
}

/*
*	历史报警按钮函数
*/
void CDlgExamine::OnBtnHistoryAlarm()
{
	m_listAlarm.MoveWindow(15, 40, 988, 648, TRUE);
	m_listAlarm.ShowWindow(TRUE);
	m_ctlDisplayOut1.ShowWindow(FALSE);
	m_ctlDisplayIn1.ShowWindow(FALSE);
	m_ctlDisplayIn2.ShowWindow(FALSE);
	m_ctlDisplayIn3.ShowWindow(FALSE);
	m_ctlDisplayIn4.ShowWindow(FALSE);
	m_ctlDisplayIn5.ShowWindow(FALSE);
	m_ctlDisplayIn6.ShowWindow(FALSE);
	ShowAlam(FALSE);
}
/*
 *	返回按钮函数
 */
void CDlgExamine::OnBtnBackE()
{
	CDlgExamine::OnOK();
}

/*
*	输入输出按钮函数
*/
void CDlgExamine::OnBtnIOput()
{
	m_listAlarm.ShowWindow(FALSE);
	m_ctlDisplayOut1.ShowWindow(TRUE);
	m_ctlDisplayIn1.ShowWindow(TRUE);
	m_ctlDisplayIn2.ShowWindow(TRUE);
	m_ctlDisplayIn3.ShowWindow(TRUE);
	m_ctlDisplayIn4.ShowWindow(TRUE);
	m_ctlDisplayIn5.ShowWindow(TRUE);
	m_ctlDisplayIn6.ShowWindow(TRUE);
}

HBRUSH CDlgExamine::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
 *	更新IO点
 */
LRESULT CDlgExamine::UpdateInput(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case IN_SERVO_FLIMIT+1:
		m_ctlDisplayIn1.SetDisplayData(127-lParam);
		break;
	case IN_SERVO_RLIMIT+1:
		m_ctlDisplayIn2.SetDisplayData(127-lParam);
		break;
	case IN_HOME_STATE+1:
		m_ctlDisplayIn3.SetDisplayData(127-lParam);
		break;
	case IN_INPUT_8+1:
		m_ctlDisplayIn4.SetDisplayData(255-lParam);
		break;
	case IN_INPUT_16+1:
		m_ctlDisplayIn5.SetDisplayData(255-lParam);
		break;
	case IN_SERVO_ALARM+1:
		m_ctlDisplayIn6.SetDisplayData(255-lParam);
		break;
	case 300:
		m_ctlDisplayOut1.SetDisplayData(lParam);
		break;
		
	default:
		break;
	}
	return 0;
}

BEGIN_EVENTSINK_MAP(CDlgExamine, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgExamine)
	ON_EVENT(CDlgExamine, IDC_DISPLAYCTRLCTRL_OUT1, -601 /* DblClick */, OnDblClickDisplayctrlctrlOut1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

/*
*	双击display控件函数（输出点才能双击）
*/
void CDlgExamine::OnDblClickDisplayctrlctrlOut1() 
{
	// TODO: Add your control notification handler code here
	int	l_iRes=0;
	l_iRes = m_ctlDisplayOut1.GetDbClickNum();
	g_cHandDll.SwitchOutput(l_iRes);
}

/*
 *	显示报警函数
 */
void CDlgExamine::ShowAlam(BOOL bCurrAlarm)
{
	int nCurltem = 0;
	CString strItem1, strItem2, strItem3, strItem4, strItem5;
	
	m_listAlarm.DeleteAllItems();
	
	if(bCurrAlarm)
	{
		m_nAlarmCounts = g_AlarmDll.GetAlarmCounts();
		m_pRTAlarm = g_AlarmDll.GetAlarm();
		for(int i=0;i<m_nAlarmCounts;i++)
		{
			strItem1.Format("%s", m_pRTAlarm->chTime);
			strItem2.Format("%d", m_pRTAlarm->nCode);
			strItem3.Format("%d", m_pRTAlarm->nGrade);
			strItem4.Format("%s", m_pRTAlarm->Context);			
			nCurltem = m_listAlarm.InsertItem(m_listAlarm.GetItemCount(), strItem1);
			m_listAlarm.SetItemText(nCurltem, 1, strItem2);
			m_listAlarm.SetItemText(nCurltem, 2, strItem3);
			m_listAlarm.SetItemText(nCurltem, 3, strItem4);
			m_pRTAlarm = g_AlarmDll.GetNextAlarm();
		}
	}
	else
	{
		pALARM		 m_pTempAlarm;
		pPARAALARM	 pTempPara;
		m_pHistoryAlarm = g_AlarmDll.GetHistoryAlarm();
		for(m_pTempAlarm=m_pHistoryAlarm; m_pTempAlarm; m_pTempAlarm = m_pTempAlarm->pNext)
		{
			strItem1.Format("%s", m_pTempAlarm->chTime);
			strItem2.Format("%d", m_pTempAlarm->nCode);
			pTempPara = g_AlarmDll.GetSpecifyAlarm(m_pTempAlarm->nCode);
			strItem3.Format("%d", pTempPara->nGrade);
			strItem4.Format("%s", pTempPara->Context);
				if(m_pTempAlarm->nState == 0)
					strItem5 = "清除";
				else
					strItem5 = "报警";			
			nCurltem = m_listAlarm.InsertItem(m_listAlarm.GetItemCount(), strItem1);
			m_listAlarm.SetItemText(nCurltem, 1, strItem2);
			m_listAlarm.SetItemText(nCurltem, 2, strItem3);
			m_listAlarm.SetItemText(nCurltem, 3, strItem4);
			m_listAlarm.SetItemText(nCurltem, 4, strItem5);
		}
	}
}
