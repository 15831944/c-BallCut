// BallCut.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BallCut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/************************************************************************/
/*                                                                      */
/************************************************************************/

#include "DlgCautionMessage.h"			//��ʾ����Ի����ͷ�ļ�




/************************************************************************/
/*                                                                      */
/************************************************************************/


/////////////////////////////////////////////////////////////////////////////
// CBallCutApp
CFont        g_cFontButton,g_cFontStatic,g_cFontEdit,g_cFontList,g_cFontKey,g_cFontRP;	//ÿ������Ķ���
CDMCWin      g_cController;						//galil����������
CHandDll	 g_cHandDll;						//cHandDll��̬��Ķ���
CString		 g_strPathC="C:\\Program Files\\BallCut\\";						//�ŵ�C�̵���Ŀ
CString		 g_strPathD;						//�ŵ�D�̵���Ŀ
CBallCutDlg* g_pMainDlg = NULL;
/*
*	�����ǻ�е�������ȫ��ֵ
*/
double	g_dHandAddA;
double	g_dHandAddB;
double	g_dHandAddC;
double	g_dHandAddX;
double	g_dHandAddY;
double	g_dHandAddZ;
double	g_dHandSpeedA;
double	g_dHandSpeedB;
double	g_dHandSpeedC;
double	g_dHandSpeedX;
double	g_dHandSpeedY;
double	g_dHandSpeedZ;
double	g_dHandSubA;
double	g_dHandSubB;
double	g_dHandSubC;
double	g_dHandSubX;
double	g_dHandSubY;
double	g_dHandSubZ;
long	g_lLimitFB;
long	g_lLimitFC;
long	g_lLimitFA;
long	g_lLimitFX;
long	g_lLimitFY;
long	g_lLimitFZ;
long	g_lLimitRA;
long	g_lLimitRB;
long	g_lLimitRC;
long	g_lLimitRX;
long	g_lLimitRY;
long	g_lLimitRZ;
double	g_dPulseB;
double	g_dPulseC;
double	g_dPulseX;
double	g_dPulseY;
double	g_dPulseZ;
double	g_dPulseA;
double	g_dZeroSpeedA;
double	g_dZeroSpeedB;
double	g_dZeroSpeedC;
double	g_dZeroSpeedX;
double	g_dZeroSpeedY;
double	g_dZeroSpeedZ;

double	g_dZeroOffsetA;
double	g_dZeroOffsetB;
double	g_dZeroOffsetC;
double	g_dZeroOffsetX;
double	g_dZeroOffsetY;
double	g_dZeroOffsetZ;

double	g_dBigShakeRadiuas;
//////////////�����ǹ��ղ�����ֵ////////////////////////////
BOOL g_ctlOrTouch;
double	g_dBallRadius;
double	g_dCutAdd;
double	g_dCutSpeed;
double	g_dCutSub;
double	g_dThick;
/////////////////////////////////////////////////////////////////////////
CAlarmDll	 g_AlarmDll;
CString	   g_arr_message[51][5];
BEGIN_MESSAGE_MAP(CBallCutApp, CWinApp)
	//{{AFX_MSG_MAP(CBallCutApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBallCutApp construction

CBallCutApp::CBallCutApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBallCutApp object

CBallCutApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBallCutApp initialization

BOOL CBallCutApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

/*
 *	//�������庯��
 */
InitFont();								

/*
 *	//////////////////////////////////////////////////////////////////////////
 */
	CBallCutDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void GetBitMapRgn(CDC *pDC, HRGN &c,int nID)
{	
	CDC   memDC; 
	//�����봫��DC���ݵ���ʱDC 
	memDC.CreateCompatibleDC(pDC); 
	HRGN hrgn;
	hrgn = CreateRectRgn(0, 0, 0, 0);
	CombineRgn(c,c,hrgn,RGN_AND);
	DeleteObject(hrgn);
	CBitmap cBitmap;
	cBitmap.LoadBitmap(nID);
	memDC.SelectObject(&cBitmap); 
	BITMAP   bit;       
    cBitmap.GetBitmap   (&bit);//ȡ��λͼ����������Ҫ�õ�λͼ�ĳ��Ϳ�        
	int   y; 
	for(y=0;y <bit.bmHeight     ;y++) 
	{ 
        CRgn   rgnTemp;  //������ʱregion 
		
		int   iX   =   0; 
		do 
		{ 
			//����͸��ɫ�ҵ���һ����͸��ɫ�ĵ�. 
			while   (iX   <=   bit.bmWidth     &&   memDC.GetPixel(iX,   y)   ==   RGB(255,255,255)) 
				iX++; 
			
			//��ס�����ʼ�� 
			int   iLeftX   =   iX; 
			
			//Ѱ���¸�͸��ɫ�ĵ� 
			while   (iX   <=   bit.bmWidth     &&   memDC.GetPixel(iX,   y)   !=   RGB(255,255,255)) 
				++iX; 
			
			//����һ������������ص���Ϊ1���ص���ʱ��region�� 
			rgnTemp.CreateRectRgn(iLeftX,   y,   iX,   y+1); 
			
			//�ϲ����� "region ". 
			CombineRgn(c,c,rgnTemp,RGN_OR); 
			
			//ɾ����ʱ "region ",�����´δ���ʱ�ͳ��� 
			rgnTemp.DeleteObject(); 
		}while(iX<bit.bmWidth); 
	}	
}


/*
 *	�������庯��
 */
void InitFont()
{
	g_cFontButton.CreateFont(20,0,0,0,FW_MEDIUM,0,0,0,ANSI_CHARSET,OUT_STROKE_PRECIS,	\
		CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("����"));

	g_cFontStatic.CreateFont(16,0,0,0,FW_LIGHT,0,0,0,ANSI_CHARSET,OUT_STROKE_PRECIS,	\
		CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("����"));

	g_cFontEdit.CreateFont(18,0,0,0,FW_LIGHT,0,0,0,ANSI_CHARSET,OUT_STROKE_PRECIS,		\
		CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("����"));

	g_cFontList.CreateFont(15,0,0,0,FW_LIGHT,0,0,0,ANSI_CHARSET,OUT_STROKE_PRECIS,		\
		CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("����"));

	g_cFontKey.CreateFont(32,0,0,0,FW_BOLD,0,0,0,ANSI_CHARSET,OUT_STROKE_PRECIS,		\
		CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("����"));
	
	g_cFontRP.CreateFont(28,0,0,0,FW_BOLD,0,0,0,ANSI_CHARSET,OUT_STROKE_PRECIS,			\
		CLIP_STROKE_PRECIS,DRAFT_QUALITY,VARIABLE_PITCH|FF_SWISS,_T("Times New Roman"));
	
}

/*
*	ͨ�Ŵ�����ʾ��
*/
void CommunicationErrorMessage()
{
	CDlgCautionMessage OpenDlg;
	OpenDlg.bYesNo=FALSE;
	OpenDlg.strAfxMessage="ͨ�Ŵ���!��ȫ���ϵ�";
	OpenDlg.strAfxTitle="ͨ�Ŵ���";
	OpenDlg.DoModal();
}

/*
*	����������ʾ��!����������л��������ִ��
*/
void DMCRuningMessage()
{
	CDlgCautionMessage OpenDlg;
	OpenDlg.bYesNo=FALSE;
	OpenDlg.strAfxMessage="��������!����������л��������ִ��";
	OpenDlg.strAfxTitle="��������!";
	OpenDlg.DoModal();
}

/*
*	�����»������ʾ��
*/
void NoHomeMessage()
{
	CDlgCautionMessage OpenDlg;
	OpenDlg.bYesNo=FALSE;
	OpenDlg.strAfxMessage="���Ȼػ�е���!";
	OpenDlg.strAfxTitle="��������!";
	OpenDlg.DoModal();
}



