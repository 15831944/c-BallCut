// BallCutDlg.h : header file
//
//{{AFX_INCLUDES()
#include "planinfo1.h"
#include "lamp2.h"
#include "captioninfo1.h"
#include "btnctl.h"
//}}AFX_INCLUDES

#if !defined(AFX_BALLCUTDLG_H__686FAA2B_3B12_414E_9A48_2C586F0A26C8__INCLUDED_)
#define AFX_BALLCUTDLG_H__686FAA2B_3B12_414E_9A48_2C586F0A26C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UniButton.h"
#include "DlgExamine.h"
#include "DlgZero.h"
#include "DlgHand.h"
#include "ShowFireCutPos.h"
#include "EditDoubleClick.h"
#include "Dlg_KeyNumber.h"
#include "BallCutDll.h"
#include "DlgParamFourBall.h"//�Ŀ����и����
#include "DlgParamThreeBall.h"//���������



#define WM_INPUT WM_USER+100			//����������������ʱ���͵���Ϣ
/////////////////////////////////////////////////////////////////////////////
// CBallCutDlg dialog

class CBallCutDlg : public CDialog
{
// Construction
public:

	CBallCutDlg(CWnd* pParent = NULL);	// standard constructor
	~CBallCutDlg();
//////////////////////////////////////////////////////////////////////////
	CDlgZero* m_CDlgZero;		//�����ģ̬�Ի���
	CDlgHand* m_CDlgHand;		//�ֶ���ģ̬�Ի���
//	CShowFireCutPos* m_CDlgFireCutPos;	//
	CBrush m_brush;
	int m_iOldInput[10];		//�������			
	int m_iNewInput[10];		//�������
	HANDLE m_hThreadOne;		//��һ���̵߳ľ��
	CBallCutDll* m_CBallCutDll;	//���и����ݵĶ���
	CBallCut2Dll m_CBallCutDll2;//�ڶ����������
	struct stcPARAM_FOUR_BALL //�Ŀ����и�Ĳ���
	{
		double Ball4EA,Ball4EG,Ball4EAA,Ball4EGA;//�������
		double Ball4CA,Ball4CG,Ball4CAA,Ball4CGA;//��������
		double Ball4EDA,Ball4EDG,Ball4EDE,Ball4EDAA,Ball4EDGA;//��������
		double Ball4SG,Ball4SB,Ball4SE,Ball4EDB,Ball4SGA;//��������	
		
	};
	struct stcPARAM_THREE_BALL //�������и�Ĳ���
	{
		double Ball3EA,Ball3EB,Ball3EAA,Ball3EBA;//�������
		double Ball3CA,Ball3CB,Ball3CG,Ball3CGA,Ball3CBA;//��������
		double Ball3SA,Ball3SB,Ball3SG,Ball3SAA;//��������
	};
	struct stcPARAM_WORK
	{	//		���ж�����Բ��ƫ��
		double OverCut,CenterOffset,Position400,Position650,Position3000;
	};
	stcPARAM_THREE_BALL m_stcParamThreeBall;
	stcPARAM_FOUR_BALL  m_stcParamFourBall;
	stcPARAM_WORK  m_stcParamWork;
//////////////////////////////////////////////////////////////////////////
	void OnSystemTimer();			//ϵͳʱ��
	void InitAutoGalilParam();		//��ʼ���Զ������galil����
	static DWORD __stdcall ThreadDownloadDMC(LPVOID lpParam);		//�߳�1������DMC����û����и
	//���������ʽ��һ����DWORD WINAPI ������ (LPVOID lpParam) ����ʽ����ȷ���޷����óɹ���
	
// Dialog Data
	//{{AFX_DATA(CBallCutDlg)
	enum { IDD = IDD_BALLCUT_DIALOG };
	CEditDoubleClick	m_ctlHeatTime;
	CPlanInfo	m_ctlSliderMultiply;
	CLamp	m_ctlLampStateA;
	CLamp	m_ctlLampStateB;
	CLamp	m_ctlLampStateC;
	CLamp	m_ctlLampStateX;
	CLamp	m_ctlLampStateY;
	CLamp	m_ctlLampStateZ;
	CCaptionInfo	m_CapTime;
	CBtnCtl	m_ctl4Equtor;
	CBtnCtl	m_ctl4Side;
	CBtnCtl	m_ctl4Center;
	CBtnCtl	m_ctl4Edge;
	CBtnCtl	m_ctl3Side;
	CBtnCtl	m_ctl3Equtor;
	CBtnCtl	m_ctl3Center;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBallCutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CUniButton m_cBtnClose;
	CUniButton m_cBtnHand;
	CUniButton m_cBtnAuto;
	CUniButton m_cBtnZero;
	CUniButton m_cBtnWorkParam;
	CUniButton m_cBtnExamine;
	CUniButton m_cCutStop;	//�и�ֹͣ 
	CUniButton m_cCutSuspend;//�и���ͣ
	CUniButton m_cCutBegan;//����
	CUniButton m_cBtnHotGas;//Ԥ����	
	CUniButton m_cBtnFireGas;//ȼ��
	CUniButton m_cBtnCutGas;//�и���
	CUniButton m_cBtnReleaseGas;//����

	
	void WhenInputingDone();		//ɨ��������Ƿ������룬������Ļ��ķ�����Ϣ//�����ʱ��������
	void InitInterface();			//��ʼ���ֶ��ͻ���Ľ���
	void FirstInputState();			//���ϵ�ʱ�鿴�������״̬
	void CompareZeroOrOne(int WhichInput,int Inputed,int Inputing);		//�Ƚ�����0��1�ĺ���
	void CompareNumber(int WhichInput,int Inputed,int Inputing);			//�Ƚ�0~255������TIֵ

	// Generated message map functions
	//{{AFX_MSG(CBallCutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnClose();
	afx_msg void OnBtnAuto();
	afx_msg void OnBtnHand();
	afx_msg void OnBtnZero();
	afx_msg void OnBtnExamine();
	afx_msg void OnBtnWorkParam();
	afx_msg void OnBtnCutSuspend();
	afx_msg void OnBtnCutBegan();
	afx_msg void OnBtnCutStop();
	afx_msg LRESULT OnEditDouble(WPARAM wParam, LPARAM lParam);			//��༭��ʱ�ᷢ���Ƿ񵯴���������Ϣ
	afx_msg LRESULT OnMsgInput(WPARAM wParam, LPARAM lParam);			//�Լ������WIN��Ϣ
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);	
	afx_msg void OnClickSliderMultiply();								//�������ĺ���
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClickBtn3center();
	afx_msg void OnClickBtn3side();
	afx_msg void OnBtnEqutor();
	afx_msg void OnBtnPoleEdge();
	afx_msg void OnBtnPoleCenter();
	afx_msg void OnBtnPoleSide();
	afx_msg void OnClickBtn3equtor();
	afx_msg void OnClickBtnSetZore();
	afx_msg void OnClickBtnPos650();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
private:
	int m_iWhichProduct;		//1�����2���У�3���࣬4����
	int m_iBreakThread;			//�����̵߳ı�������Ϊ1ʱ����	
	int m_iIsSuspend;				//�Ƿ�����ͣ��ť0�У�1��
	BOOL m_bFlagSB6;
	BOOL m_bFlagSB7;
	BOOL m_bFlagSB8;
	BOOL m_bFlagSB17;
	




	//������Ĳ岹�ٶ� 
	double GetSpeedVecter(double SX,double SY,double SZ,double SA,double SB,double SC);
	//�е�һ����ĵĺ�������4��
	void Cut4StyleBall(int CutStyle);//CutStyleΪ1ʱ�ǳ����2���У�3���࣬4����
	//���ݲ�ͬ����ǣ��õ���ͬ�ĵ������
	BALLDATA GetPointData(int CutStyle,POSITION& POS);
	//���ݲ�ͬ����ǣ��õ���һ��Ľ��
	void GetNextPos(int CutStyle,POSITION& POS);
	//�ʵ���ٶ�
	void AskAuxSpeed();	
	//�ʵ��λ��
	void AskAuxPosition();
	//���ŷ�ʹ��״̬
	int AskServoSHState();	
	//�ʵ������λ״̬
	int AskMotorLimitF();		
	//�ʵ������λ״̬
	int AskMotorLimitR();		
	//�ʵ����е��㿪�ص�ֵ
	int AskMotorHome();
	//��ʼ�������水ť			
	void InitBtn();					
	//��ʼ������//�����ʱ��������
	void InitData();
	//��������ͷ
	POSITION GetHeadPos(int CutStyle);

	void OnBtnHotGas();		//Ԥ��
	void OnBtnFireGas();   //��Ȳ
	void OnBtnCutGas();//�и���
	void OnBtnReleaseGas();//����

	DECLARE_MESSAGE_MAP()
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALLCUTDLG_H__686FAA2B_3B12_414E_9A48_2C586F0A26C8__INCLUDED_)
