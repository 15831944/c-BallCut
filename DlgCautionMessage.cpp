// DlgCautionMessage.cpp : implementation file
//

#include "stdafx.h"
#include "ballcut.h"
#include "DlgCautionMessage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCautionMessage dialog


CDlgCautionMessage::CDlgCautionMessage(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCautionMessage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCautionMessage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_brush.CreateSolidBrush(RGB(203,211,237));
}

CDlgCautionMessage::~CDlgCautionMessage()
{

	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}

}
void CDlgCautionMessage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCautionMessage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCautionMessage, CDialog)
	//{{AFX_MSG_MAP(CDlgCautionMessage)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCautionMessage message handlers

void CDlgCautionMessage::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CDlgCautionMessage::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

HBRUSH CDlgCautionMessage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CDlgCautionMessage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CWnd *top;
	top = (CWnd*)GetDlgItem(IDD_DIALOG_CAUTION_MESSAGE);
	CWnd::SetWindowPos(top,170,200,462,202,SWP_SHOWWINDOW);
	// TODO: Add extra initialization here
	CStatic	*pStatic;
	pStatic = (CStatic*)GetDlgItem(IDC_STATIC_AFX);
	pStatic->SetFont(&g_cFontStatic);
	CWnd::SetDlgItemText(IDC_STATIC_AFX,strAfxMessage);
	CWnd::SetDlgItemText(IDC_CAPTIONINFOCTRL1,strAfxTitle);
	GetDlgItem(IDOK)->SetFont(&g_cFontStatic);
	GetDlgItem(IDCANCEL)->SetFont(&g_cFontStatic);
//	CWnd::SetDlgItemText(IDOK,strAfxYES);
//	CWnd::SetDlgItemText(IDCANCEL,strAfxNO);
	if(!bYesNo)
	{
		CButton  *pbtn;
		pbtn = (CButton*)GetDlgItem(IDCANCEL);
		pbtn->ShowWindow(FALSE);
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
