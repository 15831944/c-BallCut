// ShowFireCutPos.cpp : implementation file
//

#include "stdafx.h"
#include "ballcut.h"
#include "ShowFireCutPos.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowFireCutPos dialog


CShowFireCutPos::CShowFireCutPos(CWnd* pParent /*=NULL*/)
	: CDialog(CShowFireCutPos::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowFireCutPos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowFireCutPos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowFireCutPos)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowFireCutPos, CDialog)
	//{{AFX_MSG_MAP(CShowFireCutPos)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowFireCutPos message handlers

BOOL CShowFireCutPos::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowPos(CWnd::GetOwner(),0,265,720,445,SWP_SHOWWINDOW);
	// TODO: Add extra initialization here
	SetTimer(1,200,NULL);
	m_a=300;
	m_b=240;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowFireCutPos::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default


	if (nIDEvent == 1)
	{
		OnButton1() ;
	}


	
	CDialog::OnTimer(nIDEvent);
}


void CShowFireCutPos::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDC *pDC = GetDC();
	CPen pPen,*pOldpen;
	pPen.CreatePen(PS_SOLID,2,RGB(222, 222, 20));
	pOldpen = pDC->SelectObject(&pPen);
	pDC->MoveTo(m_a,m_b);
	char tpa[80]={0};
	char tpb[80]={0};
	g_cController.Command("TPA",tpa,sizeof(tpa));
	g_cController.Command("TPB",tpb,sizeof(tpb));
	m_a = atoi(tpa)/100+300;
	m_b = atoi(tpb)/100+240;
	pDC->LineTo((m_a),(m_b));
	pDC->SelectObject(pOldpen);
	pPen.DeleteObject();
	DeleteObject(pDC);	
}

void CShowFireCutPos::OnButton2() 
{
	// TODO: Add your control notification handler code here
	Invalidate(TRUE);
	
}
