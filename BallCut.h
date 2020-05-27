// BallCut.h : main header file for the BALLCUT application
//

#if !defined(AFX_BALLCUT_H__095AAC80_EEB0_443A_AC13_F133F07CE1C5__INCLUDED_)
#define AFX_BALLCUT_H__095AAC80_EEB0_443A_AC13_F133F07CE1C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
/************************************************************************/
/*                                                                      */
/************************************************************************/
#include "resource.h"		// main symbols
/************************************************************************/
/*     ͷ�ļ�                                                           */
/************************************************************************/

#include "DlgCautionMessage.h"		//��ʾ����Ի����
#include "BallCutDlg.h"


/************************************************************************/
/*       �궨���������                                                 */
/************************************************************************/
////////*ǰ16�������*/
#define IN_INPUT_1			1	
#define IN_INPUT_2			2
#define IN_INPUT_3			3
#define IN_INPUT_4			4
#define IN_INPUT_5			5
#define IN_INPUT_6			6
#define IN_INPUT_7			7
#define IN_INPUT_8			8
#define IN_INPUT_9			9
#define IN_INPUT_10			10
#define IN_INPUT_11			11
#define IN_INPUT_12			12
#define IN_INPUT_13			13
#define IN_INPUT_14			14
#define IN_INPUT_15			15
#define IN_INPUT_16			16
/////////*�ŷ�����*/
#define IN_SERVOX_ALARM		17	
#define IN_SERVOY_ALARM		18	
#define IN_SERVOZ_ALARM		19	
#define IN_SERVOA_ALARM		20
#define IN_SERVOB_ALARM		21
#define IN_SERVOC_ALARM		22
#define IN_SERVOG_ALARM		23
#define IN_SERVO_ALARM		24
/*��ͣ����*/
#define IN_EMG_STOP			25	
/*�ŷ�����λ*/
#define IN_SERVOX_FLIMIT	33	
#define IN_SERVOY_FLIMIT	34	
#define IN_SERVOZ_FLIMIT	35	
#define IN_SERVOA_FLIMIT	36
#define IN_SERVOB_FLIMIT	37	
#define IN_SERVOC_FLIMIT	38	
#define IN_SERVOG_FLIMIT	39
#define IN_SERVO_FLIMIT		40	
/*�ŷ�����λ*/
#define IN_SERVOX_RLIMIT	41	
#define IN_SERVOY_RLIMIT	42	
#define IN_SERVOZ_RLIMIT	43	
#define IN_SERVOA_RLIMIT	44
#define IN_SERVOB_RLIMIT	45	
#define IN_SERVOC_RLIMIT	46	
#define IN_SERVOG_RLIMIT	47
#define IN_SERVO_RLIMIT		48	
/*�ŷ�״̬�Ƿ�ʹ��*/
#define IN_SERVOX_STATE		49	
#define IN_SERVOY_STATE		50
#define IN_SERVOZ_STATE		51
#define IN_SERVOA_STATE		52
#define IN_SERVOB_STATE		53
#define IN_SERVOC_STATE		54
#define IN_SERVOG_STATE		55
#define IN_SERVO_STATE		56
/*�����е��㿪��*/
#define IN_HOMEX_STATE		57	
#define IN_HOMEY_STATE		58
#define IN_HOMEZ_STATE		59
#define IN_HOMEA_STATE		60
#define IN_HOMEB_STATE		61
#define IN_HOMEC_STATE		62
#define IN_HOMEG_STATE		63
#define IN_HOME_STATE		64
//�����ļ���·��
#define FILE_PATH_OF_D      "D:\\Program Files\\BallCut\\"
#define FILE_PATH_OF_C      "C:\\Program Files\\BallCut\\"


/////////////////////////////////////////////////////////////////////////////
// CBallCutApp:
// See BallCut.cpp for the implementation of this class
//


/*
 *	������ȫ����������
 */
extern  CFont        g_cFontButton,g_cFontStatic,g_cFontEdit,g_cFontList,g_cFontKey,g_cFontRP;	//ÿ������Ķ���
extern  CDMCWin      g_cController;					//galil����������
extern  CHandDll	 g_cHandDll;					//cHandDll��̬��Ķ���
extern  CString		 g_strPathC;					//�ŵ�C�̵���Ŀ
extern  CString		 g_strPathD;					//�ŵ�D�̵���Ŀ
extern  class CBallCutDlg* g_pMainDlg;

/*
 *	�����ǻ�е�������ȫ��ֵ
 */
extern	double	g_dHandAddA;
extern	double	g_dHandAddB;
extern	double	g_dHandAddC;
extern	double	g_dHandAddX;
extern	double	g_dHandAddY;
extern	double	g_dHandAddZ;
extern	double	g_dHandSpeedA;
extern	double	g_dHandSpeedB;
extern	double	g_dHandSpeedC;
extern	double	g_dHandSpeedX;
extern	double	g_dHandSpeedY;
extern	double	g_dHandSpeedZ;
extern	double	g_dHandSubA;
extern	double	g_dHandSubB;
extern	double	g_dHandSubC;
extern	double	g_dHandSubX;
extern	double	g_dHandSubY;
extern	double	g_dHandSubZ;
extern	long	g_lLimitFB;
extern	long	g_lLimitFC;
extern	long	g_lLimitFA;
extern	long	g_lLimitFX;
extern	long	g_lLimitFY;
extern	long	g_lLimitFZ;
extern	long	g_lLimitRA;
extern	long	g_lLimitRB;
extern	long	g_lLimitRC;
extern	long	g_lLimitRX;
extern	long	g_lLimitRY;
extern	long	g_lLimitRZ;
extern	double	g_dPulseB;
extern	double	g_dPulseC;
extern	double	g_dPulseX;
extern	double	g_dPulseY;
extern	double	g_dPulseZ;
extern	double	g_dPulseA;
extern	double	g_dZeroSpeedA;
extern	double	g_dZeroSpeedB;
extern	double	g_dZeroSpeedC;
extern	double	g_dZeroSpeedX;
extern	double	g_dZeroSpeedY;
extern	double	g_dZeroSpeedZ;
extern	double	g_dZeroOffsetA;
extern	double	g_dZeroOffsetB;
extern	double	g_dZeroOffsetC;
extern	double	g_dZeroOffsetX;
extern	double	g_dZeroOffsetY;
extern	double	g_dZeroOffsetZ;
extern	double	g_dBigShakeRadiuas;
extern  CAlarmDll	 g_AlarmDll;
//////////////////////�����ǹ��ղ�����ȫ�ֱ���ֵ///////////////////////////////
extern  double	g_dBallRadius;
extern  double	g_dCutAdd;
extern  double	g_dCutSpeed;
extern  double	g_dCutSub;
extern  double	g_dThick;
extern  BOOL g_ctlOrTouch;
/*
 *	������ȫ�ֺ�������
 */
void GetBitMapRgn(CDC *pDC, HRGN &c,int nID);	//�ؼ��Ĵ�С
void InitFont();								//��ʼ������
void CommunicationErrorMessage();		//ͨ�Ŵ�����ʾ����
void DMCRuningMessage();				//DMC��������������ʾ����
void NoHomeMessage();					//�����»������ʾ��
/*
 *	//////////////////////////////////////////////////////////////////////////
 */
class CBallCutApp : public CWinApp
{
public:
	CBallCutApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBallCutApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBallCutApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CBallCutApp theApp;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALLCUT_H__095AAC80_EEB0_443A_AC13_F133F07CE1C5__INCLUDED_)
