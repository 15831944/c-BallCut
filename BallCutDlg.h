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
#include "DlgParamFourBall.h"//四壳球切割参数
#include "DlgParamThreeBall.h"//三壳球参数



#define WM_INPUT WM_USER+100			//控制器有输入点进来时发送的消息
/////////////////////////////////////////////////////////////////////////////
// CBallCutDlg dialog

class CBallCutDlg : public CDialog
{
// Construction
public:

	CBallCutDlg(CWnd* pParent = NULL);	// standard constructor
	~CBallCutDlg();
//////////////////////////////////////////////////////////////////////////
	CDlgZero* m_CDlgZero;		//回零非模态对话框
	CDlgHand* m_CDlgHand;		//手动非模态对话框
//	CShowFireCutPos* m_CDlgFireCutPos;	//
	CBrush m_brush;
	int m_iOldInput[10];		//老输入点			
	int m_iNewInput[10];		//新输入点
	HANDLE m_hThreadOne;		//建一个线程的句柄
	CBallCutDll* m_CBallCutDll;	//球切割数据的对象
	CBallCut2Dll m_CBallCutDll2;//第二类的球数据
	struct stcPARAM_FOUR_BALL //四壳球切割的参数
	{
		double Ball4EA,Ball4EG,Ball4EAA,Ball4EGA;//赤道数据
		double Ball4CA,Ball4CG,Ball4CAA,Ball4CGA;//极中数据
		double Ball4EDA,Ball4EDG,Ball4EDE,Ball4EDAA,Ball4EDGA;//极侧数据
		double Ball4SG,Ball4SB,Ball4SE,Ball4EDB,Ball4SGA;//极边数据	
		
	};
	struct stcPARAM_THREE_BALL //三壳球切割的参数
	{
		double Ball3EA,Ball3EB,Ball3EAA,Ball3EBA;//赤道数据
		double Ball3CA,Ball3CB,Ball3CG,Ball3CGA,Ball3CBA;//极中数据
		double Ball3SA,Ball3SB,Ball3SG,Ball3SAA;//极边数据
	};
	struct stcPARAM_WORK
	{	//		过切度数，圆心偏置
		double OverCut,CenterOffset,Position400,Position650,Position3000;
	};
	stcPARAM_THREE_BALL m_stcParamThreeBall;
	stcPARAM_FOUR_BALL  m_stcParamFourBall;
	stcPARAM_WORK  m_stcParamWork;
//////////////////////////////////////////////////////////////////////////
	void OnSystemTimer();			//系统时间
	void InitAutoGalilParam();		//初始化自动界面的galil参数
	static DWORD __stdcall ThreadDownloadDMC(LPVOID lpParam);		//线程1，下载DMC命令，让机器切割。
	//这个函数格式：一定是DWORD WINAPI 函数名 (LPVOID lpParam) ，格式不正确将无法调用成功。
	
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
	CUniButton m_cCutStop;	//切割停止 
	CUniButton m_cCutSuspend;//切割暂停
	CUniButton m_cCutBegan;//启动
	CUniButton m_cBtnHotGas;//预热氧	
	CUniButton m_cBtnFireGas;//燃气
	CUniButton m_cBtnCutGas;//切割氧
	CUniButton m_cBtnReleaseGas;//放气

	
	void WhenInputingDone();		//扫描输入点是否有输入，有输入的话的发送消息//打开软件时读出参数
	void InitInterface();			//初始化手动和回零的界面
	void FirstInputState();			//刚上电时查看下输入点状态
	void CompareZeroOrOne(int WhichInput,int Inputed,int Inputing);		//比较输入0，1的函数
	void CompareNumber(int WhichInput,int Inputed,int Inputing);			//比较0~255，就是TI值

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
	afx_msg LRESULT OnEditDouble(WPARAM wParam, LPARAM lParam);			//点编辑框时会发送是否弹触摸屏的消息
	afx_msg LRESULT OnMsgInput(WPARAM wParam, LPARAM lParam);			//自己定义的WIN消息
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);	
	afx_msg void OnClickSliderMultiply();								//点击滑块的函数
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
	int m_iWhichProduct;		//1赤道，2极中，3极侧，4极边
	int m_iBreakThread;			//跳出线程的变量，当为1时跳出	
	int m_iIsSuspend;				//是否按下暂停按钮0有，1无
	BOOL m_bFlagSB6;
	BOOL m_bFlagSB7;
	BOOL m_bFlagSB8;
	BOOL m_bFlagSB17;
	




	//求六轴的插补速度 
	double GetSpeedVecter(double SX,double SY,double SZ,double SA,double SB,double SC);
	//切第一种球的的函数，共4种
	void Cut4StyleBall(int CutStyle);//CutStyle为1时是赤道，2极中，3极侧，4极边
	//根据不同的球壳，得到不同的点的数据
	BALLDATA GetPointData(int CutStyle,POSITION& POS);
	//根据不同的球壳，得到下一点的结点
	void GetNextPos(int CutStyle,POSITION& POS);
	//问电机速度
	void AskAuxSpeed();	
	//问电机位置
	void AskAuxPosition();
	//问伺服使能状态
	int AskServoSHState();	
	//问电机正限位状态
	int AskMotorLimitF();		
	//问电机负限位状态
	int AskMotorLimitR();		
	//问电机机械零点开关的值
	int AskMotorHome();
	//初始化主界面按钮			
	void InitBtn();					
	//初始化数据//打开软件时读出参数
	void InitData();
	//获得链表的头
	POSITION GetHeadPos(int CutStyle);

	void OnBtnHotGas();		//预热
	void OnBtnFireGas();   //乙炔
	void OnBtnCutGas();//切割氧
	void OnBtnReleaseGas();//放气

	DECLARE_MESSAGE_MAP()
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALLCUTDLG_H__686FAA2B_3B12_414E_9A48_2C586F0A26C8__INCLUDED_)
