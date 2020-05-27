// AlarmDll.h: interface for the CAlarmDll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALARMDLL_H__A59C274F_612B_4E06_BF5B_359F503F3A17__INCLUDED_)
#define AFX_ALARMDLL_H__A59C274F_612B_4E06_BF5B_359F503F3A17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"
#include "GeneralAlarm.h"

/*---------------------------------------*/
#define		GRADE_GREEN		0
#define		GRADE_YELLOW	1
#define		GRADE_ORANGE	2
#define		GRADE_RED		3

#define		SELF_ALM_CODE    100    /*�Զ��屨���Ż���*/

#define		UNDEFINED_ALARM		 -1		/* ������δ���� */
#define		OVERLAP_DEFINED		 -2		/* �ظ����� */
#define		LOW_ALARM_BASE_NUM	 -3		/* �Զ��屨����Ӧ����100 */
#define		MULTI_STRING_CH		 -4		/* ����˵������20���ַ� */
#define		MULTI_STRING_EN		 -5		/* Ӣ��˵������40���ַ� */

/*---------------------------------------*/

struct tagAlarm
{
	int			nCode;			/* ������ */
	char		chTime[40];		/* �������ڼ�ʱ�� */
	int			nState;			/* ���û����״̬ */
	tagAlarm	*pNext;			/* ��һ���� */
	tagAlarm	*pPrev;			/* ��һ���� */
};
typedef struct tagAlarm ALARM, *pALARM;

/* ���б����б�(ͨ�ñ������Զ��屨��) */
struct tagAlarmList
{
	int				nCode;				/* ������ */
	int				nGrade;				/* �����ȼ� */
	char			chContentCh[40];	/* �������� */
	char			chContentEn[40];	/* �������� */
	tagAlarmList	*pNext;				/* ��һ���� */
	tagAlarmList	*pPrev;				/* ��һ���� */
};
typedef struct tagAlarmList ALARMLIST, *pALARMLIST;

/* ��ǰ�����ļ�¼���� */
struct tagParaAlarm
{
	int				nCode;			/* ������ */
	int				nGrade;			/* �����ȼ� */	
	char			chTime[40];		/* �������ڼ�ʱ�� */
	char			Context[40];	/* �������� */
};
typedef struct tagParaAlarm PARAALARM, *pPARAALARM;

class AFX_EXT_CLASS CAlarmDll : public CObject  
{
public:

	CAlarmDll();
	virtual ~CAlarmDll();

	/* ��ʼ�����ݿ� */
	BOOL InitDB(CString	strAppDir);

	/* ��ȡ��ǰ�����ĵ������ݵĽṹָ��*/
	pPARAALARM GetSpecifyAlarm(int nCode);

	/* ������ʷ��������ʱ�� Ĭ��Ϊ5�� */
	void SetHisAlmTime(int nDay);

	/* ���ñ������� */
	/* nCode�������ţ��Ƕ����б����б��еļ�������޸ģ����Ȳ��ҽڵ㣩 */
	/* nGrade������ */
	int SetAlarmGrade(int nCode, int nGrade);

	/* ���õ�ǰ���� */
	int SetAlarm(int nCode);

	/* �����ǰ���� */
	int DeleteAlarm(int nCode);

	/* ��ȡ��ǰ�����ĵ�һ���������� */
	pPARAALARM GetAlarm();
	
	/* ��ȡ��һ���������� */
	pPARAALARM GetNextAlarm();
	
	/* ��ȡ���һ���������� */
	pPARAALARM GetLastAlarm();
	
	/* ��ȡ��ǰ�������� */
	int GetAlarmCounts();

	/* ��ȡ��ʷ���� */
	pALARM GetHistoryAlarm();
	
	/* �������� */
	int SetLanguage(int nLanguage);
	
	/* �ͷű����ṹ ʵʱ����*/
	void FreeAlarm();
	
	/* �ͷ���ʷ�����б�ṹ �ͷ�����*/
	void FreeHistoryAlarm();
	/*------------------------------------------*/

	/* ��ȡ�Զ��屨�� */
	pALARMLIST GetSelfAlarm();

	/* ��ȡ�Զ��屨������ */
	int GetSelfAlarmCounts();

	/* �ͻ������Զ��屨�� */
	int AddSelfDefAlm(int nCode, int nGrade, CString chContentCh, CString chContentEn);

	/* �����Զ��屨�� */
	int AddSelfAlarm(pALARMLIST pSelfAlarm);

	/* ɾ���Զ��屨�� */
	int DeleteSelfAlarm(pALARMLIST pSelfAlarm);

	/* ɾ�������Զ��屨�� */
	int DeleteSelfAlarms();

	/*------------------------------------------*/

protected:

	_ConnectionPtr m_pCon;	// �������ݿ�
	_RecordsetPtr m_pRs;	// ��¼��
	int m_Language;			// ��Ӣ�����Ե�����
	CString m_strDay;

 	pALARM  m_pCurrAlarm;   //��ǰ�����ṹָ��

 	ALARM	m_CurrAlarm;
	int		m_CurrAlarmCounts;
	ALARM	m_HistoryAlarm;
	int		m_SelfAlarmCounts;

	ALARMLIST	m_SelfAlarmList;
	ALARMLIST   m_GeneralAlarmList;

	PARAALARM	m_CurrentContent;
	
	/* ��ʼ��ͨ�ñ��� */
	void InitGeneralAlarm();
	
	/* ��ʼ���Զ��屨�� */
	void InitSelfDefiningAlarm();
	
	/* ��ʼ����ʷ���� */
	void InitHistoryAlarm();
	
	/* ���ӱ����ṹ */
	int AddAlarm(int nCode);

	/* ���ӱ����б�ṹ */
	pALARMLIST AddGeneralAlarmList();

	/* �����Զ��屨���б�ṹ */
	void AddSelfAlarmList(pALARMLIST pSelfAlarm);
	
	/* �ͷű����б�ṹ �ͷ�ͨ�õ�*/
	void FreeAlarmList();
	
	/* �ͷ��Զ��屨���б�ṹ */
	void FreeSelfAlarmList();

	/* ɾ�����ݿ��г��������ļ�¼ */
	void DeletePastAlarm();
};

#endif // !defined(AFX_ALARMDLL_H__A59C274F_612B_4E06_BF5B_359F503F3A17__INCLUDED_)































































