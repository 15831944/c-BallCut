// BallCutDll.h: interface for the CBallCutDll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALLCUTDLL_H__2AADEF72_BC6D_467B_A65C_F7C9DE611F63__INCLUDED_)
#define AFX_BALLCUTDLL_H__2AADEF72_BC6D_467B_A65C_F7C9DE611F63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
const double PI = 3.1415926535897;

typedef struct tagDOUBLEPOINT
{
	double		x;	
	double		y;
	double		z;
} DOUBLEPOINT;

typedef struct tagDOUBLEANGLE
{
	double		a;		/* �ڶ�������ת�Ƕ�				*/
	double		b;		/* ��ת���ڴ�ڶ������ڶ��ĽǶ� */
	double		c;		/* ��ת�����ת�Ƕ�				*/
}DOUBLEANGLE;

typedef struct tagBALLDATA
{
	int nIdx;					/*					  */
	int nSeq;					/* �����͹����ߵ���� */
	int nType;					/* ����������		  */
	DOUBLEPOINT		ptPara;		/* XYZ������		  */
	DOUBLEANGLE		aglPara;	/* ABC������    	  */
} BALLDATA, *PBALLDATA;

class AFX_EXT_CLASS CBallCutDll  
{
protected:
	/* ���ȽǶ�ת�� */
	double Convert2Radian(const double angle);
	double Convert2Angle(const double radian);
	/* �Ƕȼ��� */
	DOUBLEANGLE GetCutAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetRoateAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetCutAngle2(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);

	//�����
	/*��һ��*/
	DOUBLEPOINT GetEquatorLongPt(double angle, double swingAngle);
	BOOL GetEquatorLong();
	/*�ڶ���*/
	DOUBLEPOINT GetEquatorShortPt(double angle, double swingAngle);
	BOOL GetEquatorShort();
	/*������*/
	BOOL GetEquatorLongR();
	/*���ı�*/
	BOOL GetEquatorShortR();
	
	//����
	/*��һ��*/
	DOUBLEPOINT GetCenterLongPt(double angle, double swingAngle);
	BOOL GetCenterLong();
	/*�ڶ���*/
	DOUBLEPOINT GetCenterShortPt(double angle, double swingAngle);
	BOOL GetCenterShort();
	/*������*/
	BOOL GetCenterLongR();
	/*���ı�*/
	BOOL GetCenterShortR();

	//����
	/*��һ��*/
	DOUBLEPOINT GetEdgeLongPt(double angle, double PoleElvtion);
	BOOL GetEdgeLong();
	/*�ڶ���*/
	DOUBLEPOINT GetEdgeShortPt(double angle, double swingAngle, double EdgeElvtion);
	BOOL GetEdgeShort();
	/*������*/
	DOUBLEPOINT GetEdgeLongRPt(double angle, double PoleElvtion);
	BOOL GetEdgeLongR();
	/*���ı�*/
	BOOL GetEdgeShortR();

	//����
	/*��һ��*/
	DOUBLEPOINT GetSideLongPt(double equatorAlpha, double sideBeta, double centerAlpha, double sideElvtion);/*sideBetaΪ�����Գƶ̱��е������ĵļн�*/
	BOOL GetSideLong();
	/*�ڶ���*/
	DOUBLEPOINT GetSideShortPt(double angle, double sideBeta, double centerAlpha, double sideElvtion);
	BOOL GetSideShort();

	/*������*/
	DOUBLEPOINT GetSideLongRPt(double angle, double Elvtion);
	BOOL GetSideLongR();

	/*���ı�*/
	BOOL GetSideShortR();

	
private:
	//��Ÿ��������ݵ���������ֵ��
	CList<BALLDATA, BALLDATA> m_lstBallEquator;
	CList<BALLDATA, BALLDATA> m_lstBallCenter;
	CList<BALLDATA, BALLDATA> m_lstBallEdge;
	CList<BALLDATA, BALLDATA> m_lstBallSide;

	//////////////////////////////////////////////////////////////////////////
	double  m_dRadius;			//����ھ�

	double m_dR2;				//��ڶ������İ뾶

	double m_dAgleMore;			//���нǶȣ��и�ÿ���ߵ�ʱ����ߵĽǶ�

	double m_dBeginPosEq;
	double m_dBeginPosEd;
	double m_dBeginPosCe;
	double m_dBeginPosSi;
	//�������
	struct tagEQUATOR 
	{
	//�̱����������ĵļнǣ��������������ĵļнǣ����߾��ȣ��̱߾���	
		double AglAlpha,         AglBeta,        AccAlpha,  AccBate;
	}m_stcEquatorData;
	
	//��������
	struct tagCENTER 
	{	
	//  �̱����������ĵļнǣ��������������ĵļн�,���߾��ȣ��̱߾���,	
		double AglAlpha,         AglBeta,            AccAlpha, AccBate;
	//�������˵������ĵļнǣ��̱����˵������ĵļн�
		double EnAglAlpha,       EnAglBeta;
	}m_stcCenterData;

	//��������
	struct tagEDGE 
	{	
		//    �̱���ʼ�ĽǶȣ��̱߽����ĽǶ� ���߾��ȣ��̱߾���,	
		double AglStart,AglEnd,               AccAlpha, AccBate;
		//���Ա����˵������ĵļнǣ��̱����˵������ĵļн�
		double AglAlpha,			AglBeta;	      
	}m_stcEdgeData;

	//����
	struct tagSIDE 
	{	
		//90�ȣ�             �̱߶˵��ٵĽǶȣ����߾��ȣ��̱߾���,	
		double AglAlpha90,         AglBeta,         AccAlpha, AccBate;
	}m_stcSideData;
	//////////////////////////////////////////////////////////////////////////
	
public:

	CBallCutDll();
	virtual ~CBallCutDll();
	CBallCutDll(int Radius); //


	//��ȡ�������������������
	const CList<BALLDATA, BALLDATA>* GetLstEquator();
	const CList<BALLDATA, BALLDATA>* GetLstCenter();
	const CList<BALLDATA, BALLDATA>* GetLstEdge();
	const CList<BALLDATA, BALLDATA>* GetLstSide();

	//��Ÿ��������ݵ�����ÿ�����ֵ��(����)	
	CList<BALLDATA, BALLDATA> m_lstEquator;
	CList<BALLDATA, BALLDATA> m_lstCenter;
	CList<BALLDATA, BALLDATA> m_lstEdge;
	CList<BALLDATA, BALLDATA> m_lstSide;
	

	/*
	 *	�������ƣ�GetEquator
	 *	�������ܣ���ȡ���������������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����double angle: ���̱��е����������ߵļн�
				  double swingAngle:�������е����������ߵļн�
				  double angleAcc:angle����
				  double swingAngleAcc:swingAngle����
	 */
	BOOL GetEquator();

	/*
	 *	�������ƣ�GetCenter
	 *	�������ܣ���ȡ���и����������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����double angle: ���̱��е����������ߵļн�
				  double swingAngle:�������е����������ߵļн�
				  double angleAcc:angle����
				  double swingAngleAcc:swingAngle����
	 */
	BOOL GetCenter();

	
	/*
	 *	�������ƣ�GetEdge
	 *	�������ܣ���ȡ��������������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����double edgeAlpha�����೤�����˵����������ߵļн�
				  double edgeBeta�� ���೤�Ա����˵����������ߵļн�
				  double edgeElvtion������ͼ�γ��ߡ����߶Ա����������ߵļн�
				  -----------------------------------------------------------
				  double centerAlpha���������̱��е����������ߵļн�
				  double centerGamma������ͼ���������е����������ߵļн�

				  double angleAcc:  edgeAlpha�Ĳ���
				  double edgeElvtionAcc������ͼ�ζ̱ߵĲ���
				  
		��ע��GetEdgeShort�е���������+2���ԭ�򣺲�����2����еط��в���
	 */
	BOOL GetEdge();
	/*
	 *	�������ƣ�GetSide
	 *	�������ܣ���ȡ���߸����������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����sideBeta���������˵���ƽ��Բ�ĵļн�
				  sideElvtion: �����е㡢���Ա��е����������ߵļн�
				  ----------------------------------------------------
				  centerAlpha: �������̱��е������ĵ����ߵļн�
				  equatorAlpha: ������̱��е����������ߵļн�
				  edgeBeta�����೤�Ա����˵����������ߵļн�

				  double aglAcc: �ǶȲ��������ȣ�
	 */
	BOOL GetSide();

	//�뾶
	void SetRadius(double radius) { m_dRadius = radius; }
	double GetRaius() const { return m_dRadius; }
	//R2
	void SetR2(double r2) { m_dR2 = r2; }
	double GetR2() const { return m_dR2;}
	//���нǶ�
	void SetAglMore(double agl) { m_dAgleMore = agl; }
	double GetAglMore() { return m_dAgleMore; }
};


class AFX_EXT_CLASS CBallCut2Dll  
{
protected:
	/* ���ȽǶ�ת�� */
	double Convert2Radian(const double angle);
	double Convert2Angle(const double radian);
	/* �Ƕȼ��� */
	DOUBLEANGLE GetCutAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetRoateAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetCutAngle2(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	
	//�����
	/*��һ��*/
	DOUBLEPOINT GetEquatorLongPt(double angle, double swingAngle);
	BOOL GetEquatorLong(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*�ڶ���*/
	DOUBLEPOINT GetEquatorShortPt(double angle, double swingAngle);
	BOOL GetEquatorShort(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*������*/
	BOOL GetEquatorLongR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*���ı�*/
	BOOL GetEquatorShortR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);

	//����
	/*��һ��*/
	DOUBLEPOINT GetCenterLongPt(double angle, double swingAngle);
	BOOL GetCenterLong(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*�ڶ���*/
	DOUBLEPOINT GetCenterShortPt(double angle, double swingAngle);
	BOOL GetCenterShort(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*������*/
	BOOL GetCenterLongR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*���ı�*/
	BOOL GetCenterShortR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);

	//����
	/*��һ��*/
	DOUBLEPOINT GetEdgeLongPt(double aglAlpha,  double EdgeElvtion, double equatorAlpha, double centerGamma);
	BOOL GetEdgeLong(double aglAlpha, double angleAcc, double EdgeElvtion, double equatorAlpha, double centerGamma);
	/*�ڶ���*/
	DOUBLEPOINT GetEdgeLongRPt(double angle, double PoleElvtion);
	BOOL GetEdgeLongR(double angle, double angleAcc, double EdgeElvtion);


private:
	//��Ÿ��������ݵ�����
	CList<BALLDATA, BALLDATA> m_lstBallEquator;
	CList<BALLDATA, BALLDATA> m_lstBallCenter;
	CList<BALLDATA, BALLDATA> m_lstBallEdge;

	double  m_dRadius;			//����ھ���4600mm
	double m_dR2;				//��ڶ������İ뾶
	double m_dAgleMore;			//���нǶȣ��и�ÿ���ߵ�ʱ����ߵĽǶ�

public:
	CBallCut2Dll()
	{
		m_dAgleMore  = 0;
	}
	virtual ~CBallCut2Dll();

	//��ȡ�������������������
	const CList<BALLDATA, BALLDATA>* GetLstEquator();
	const CList<BALLDATA, BALLDATA>* GetLstCenter();
	const CList<BALLDATA, BALLDATA>* GetLstEdge();

	/*
	 *	�������ƣ�GetEquator
	 *	�������ܣ���ȡ���������������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����double angle: ���̱��е����������ߵļн�
				  double swingAngle:�������е����������ߵļн�
				  double angleAcc:angle����
				  double swingAngleAcc:swingAngle����
	 */
	BOOL GetEquator(double angle, double swingAngle, double angleAcc, double swingAngleAcc);

	/*
	 *	�������ƣ�GetCenter
	 *	�������ܣ���ȡ���и����������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����centerAlpha�����̱��е����������ߵļн�
				  centerGamma���������е����������ߵļн�
				  centerPlane���̱����˵�������ƽ��ԲԲ�ĵļн�

				  double angleAcc:angle����
				  double swingAngleAcc:swingAngle����
	 */
	BOOL GetCenter(double angle, double swingAngle, double aglPlane, double angleAcc, double swingAngleAcc);

	/*
	 *	�������ƣ�GetEdge
	 *	�������ܣ���ȡ��������������
	 *  ����ֵ��  BOOL: TRUE��ʾ��ȡ���ݳɹ�, FALSE��ʾ��ȡ����ʧ��
		����˵����edgeAlpha�����Ա��������������ߵļн�
				  aglPlane���������˵�������ƽ��ԲԲ�ĵļн�
				  edgeElvtion�����ߺͳ��Ա��е����������ߵļн�
				  -----------------------------------------------------
				  equatorAlpha�����̱��е����������ߵļн�
				  centerAlpha�����̱��е����������ߵļн�

				  double aglAcc���ǶȲ���(����)
	 */
	BOOL GetEdge(double edgeAlpha, double aglAcc, double aglPlane, double edgeElvtion, \
		double equatorAlpha, double centeralpha);
	

	//�뾶
	void SetRadius(double radius) { m_dRadius = radius; }
	double GetRaius() const { return m_dRadius; }
	//��ڶ������İ뾶R2
	void SetR2(double r2) { m_dR2 = r2; }
	double GetR2() const { return m_dR2; }
	//���нǶ�
	void SetAglMore(double agl) { m_dAgleMore = agl; }
	double GetAglMore() { return m_dAgleMore; }

};


#endif // !defined(AFX_BALLCUTDLL_H__2AADEF72_BC6D_467B_A65C_F7C9DE611F63__INCLUDED_)
