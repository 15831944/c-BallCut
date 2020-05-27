// HandDll.h: interface for the CHandDll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HANDDLL_H__B469996F_0BE4_4D81_9FAA_867F4C695B19__INCLUDED_)
#define AFX_HANDDLL_H__B469996F_0BE4_4D81_9FAA_867F4C695B19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Galil\\DmcWin.h"


class AFX_EXT_CLASS CHandDll : public CObject  
{
protected:
	long     handrate;//�ֶ�����
	
	double   d_handSpeedx,d_handSpeedy,d_handSpeedz,d_handSpeedw;              //�ֶ��ٶȳ�ʼֵ�趨
	double   d_zoneSpeedx,d_zoneSpeedy,d_zoneSpeedz,d_zoneSpeedw,d_zoneSpeede,d_zoneSpeedf,d_zoneSpeedg,d_zoneSpeedh;              //�����ٶȳ�ʼֵ�趨
	double   m_ResolutionX,m_ResolutionY,m_ResolutionZ,m_ResolutionW;
	int      d_zoneDirx,d_zoneDiry,d_zoneDirz,d_zoneDirw;                      //���㷽��̶���
	long     Journey_posiX,Journey_posiY,Journey_posiZ,Journey_posiW;          /* �����г� */
	long     Journey_negaX,Journey_negaY,Journey_negaZ,Journey_negaW;          /* �����г� */
	double   d_zoneOffSetx,d_zoneOffSety,d_zoneOffSetz,d_zoneOffSetw,d_zoneOffSete,d_zoneOffSetf,d_zoneOffSetg,d_zoneOffSeth;

	double   d_handSpeeda,d_handSpeedb,d_handSpeedc,d_handSpeedd;              //�ֶ��ٶȳ�ʼֵ�趨
	double   d_zoneSpeeda,d_zoneSpeedb,d_zoneSpeedc,d_zoneSpeedd;              //�����ٶȳ�ʼֵ�趨
	double   m_ResolutionA,m_ResolutionB,m_ResolutionC,m_ResolutionD;
	int      d_zoneDira,d_zoneDirb,d_zoneDirc,d_zoneDird;                      //���㷽��̶���
	long     Journey_posiA,Journey_posiB,Journey_posiC,Journey_posiD;          /* �����г� */
	long     Journey_negaA,Journey_negaB,Journey_negaC,Journey_negaD;          /* �����г� */
	double   d_zoneOffSeta,d_zoneOffSetb,d_zoneOffSetc,d_zoneOffSetd;
	
public:
	CHandDll();
	virtual ~CHandDll();

	void handInit(long nPdmc); 
		
/*double xSpeed,double ySpeed,double zSpeed,double wSpeed ��Ϊ�û���λ*/
/*�������ܣ��Ը�����ֶ��ٶȽ������ã��ٶ�ֵΪ�û���λ*/
	void handSpeedSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed); 
	void handSpeedSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed, double aSpeed,double bSpeed,double cSpeed,double dSpeed); 
		
/*double xSpeed,double ySpeed,double zSpeed,double wSpeed ��Ϊ�û���λ*/
/*�������ܣ��Ը�����ֶ����ٶȽ������ã��ٶ�ֵΪ�û���λ*/
	void handSpeedACSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed);
	void handSpeedACSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed,double aSpeed,double bSpeed,double cSpeed,double dSpeed);
	
/*double xSpeed,double ySpeed,double zSpeed,double wSpeed ��Ϊ�û���λ*/
/*�������ܣ��Ը�����ֶ����ٶȽ������ã��ٶ�ֵΪ�û���λ*/
	void handSpeedDCSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed);
	void handSpeedDCSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed,double aSpeed,double bSpeed,double cSpeed,double dSpeed); 
		
/*double xSpeed,double ySpeed,double zSpeed,double wSpeed ��Ϊ�û���λ*/
/*�������ܣ��Ը���Ļ����ٶȽ������ã��ٶ�ֵΪ�û���λ*/
	void zoneSpeedSet(double xSpeed,double ySpeed,double zSpeed,double wSpeed,double eSpeed,double fSpeed,double gSpeed,double hSpeed); 

/*int xDir,int yDir,int zDir,int wDir   Ϊ1��-1 */
/*�������ܣ��Ը���Ļ��㷽��������ã��ٶ�ֵΪ�û���λ*/
	void zoneDirSet(int xDir,int yDir,int zDir,int wDir); 

/*int xDir,int yDir,int zDir,int wDir   Ϊ1��-1 */
/*�������ܣ��Ը���Ļ��㷽��������ã��ٶ�ֵΪ�û���λ*/
	void zoneOffset(double xOffSet,double yOffSet,double zOffSet,double wOffSet); 
	void zoneOffset(double xOffSet,double yOffSet,double zOffSet,double wOffSet,double eOffSet,double fOffSet,double gOffSet,double hOffSet); 
	
/*double xRes,double yRes,double zRes,double wRes  ��ÿ���û���λ��������*/
/*�������ܣ��Ը�������嵱���������ã���ÿ���û���λ�ж��ٸ�����*/
	void ResolutionSet(double xRes,double yRes,double zRes,double wRes); 
	void ResolutionSet(double xRes,double yRes,double zRes,double wRes,double aRes,double bRes,double cRes,double dRes); 
		
/*�������ܣ��ֶ���������*/
	long handSpeedAdd(); 

/*�������ܣ��ֶ����ʽ���*/
	long handSpeedSub(); 

/*�������ܣ������ֶ�����*/
	long GetHandRate();                /* ���ص�ǰ���ֶ����� */

/*�������ܣ��ֶ��ٶ�/����ˢ��*/
	void handSpeedRefresh(); 

/*double stepper  ����ֵ����X��Ҫ���ӵ���ֵ��Ϊ0��ʾ�����ƶ���ֱ��ST����*/
/*�������ܣ�X�������ƶ�stepper��*/
	void handAxisAdd(char chAxis,double stepper); 

/*double stepper  ����ֵ����X��Ҫ���ӵ���ֵ��Ϊ0��ʾ�����ƶ���ֱ��ST����*/
/*�������ܣ�X�ᷴ���ƶ�stepper��*/
	void handAxisSub(char chAxis,double stepper); 

/*CString filename  ����������ƣ�Ϊ*.dmc�ļ�  */
/*�������ܣ������ļ�����ִ�У��ص���е���*/
	void Zone(CString filename); 

/*int n����n�������*/
/*BOOL is��TURE  SB;   FALSE  CB*/
/*�������ܣ���ָ�����������λ�����*/
	long SetOut(int n,BOOL is);

/*�������ܣ���ȡָ����������״̬*/
/*����ֵ��1  �������0  �����*/
	long GetOut(int n);                //��ȡ������״̬;
	
	/*�������ܣ���ȡָ����������״̬*/
	/*����ֵ��1  �������0  �����*/
	long GetGroupOut(int n);                //��ȡ������״̬;
	
/*�������ܣ���ȡָ����������״̬*/
/*����ֵ��1  �����룬0  ������*/
	long GetIn(int n);                 //��ȡ������״̬;

	/*�������ܣ���ȡָ����������״̬*/
	/*����ֵ��1  �����룬0  ������*/
	long GetGroupIn(int n);                 //��ȡ������״̬;
	
/*�������ܣ��˶�ֹͣ*/
	long OnStop();

/*CString Axis��Ϊ��X����Y����Z����W����A����B����C����D����*/
/*�������ܣ���ѯ�˶�״̬*/
	long OnIsBG(CString Axis);

	long SetJourneyPositive(long jourX,long jourY,long jourZ,long jourW);      //���������״̬;
	long SetJourneyPositive(long jourX,long jourY,long jourZ,long jourW,long jourA,long jourB,long jourC,long jourD);      //���������״̬;
		
	long SetJourneyNegetive(long jourX,long jourY,long jourZ,long jourW);      //���������״̬;
	long SetJourneyNegetive(long jourX,long jourY,long jourZ,long jourW,long jourA,long jourB,long jourC,long jourD);      //���������״̬;
		
	long Emergency();//��ͣ
		
	long EmergencyState();//��ͣ

    long LForLR(char axis); 

	int GetCommandInt(CString szComm);     //���������״̬;
	
	double GetCommandFloat(CString szComm);     //���������״̬;

	long GalilCommand(CString szComm);     //���������״̬;

	void SwitchOutput(int nOut);     //ת�������

	int Command(CString szComm);     //���������״̬;
	
protected:
	
	CDMCWin  *m_pController;
	long     h_rc;
	char     szhResponse[200];
	char     hcmd[80];
	CString  h_szRc;
};

#endif // !defined(AFX_HANDDLL_H__B469996F_0BE4_4D81_9FAA_867F4C695B19__INCLUDED_)
