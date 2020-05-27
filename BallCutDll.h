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
	double		a;		/* 摆动部件旋转角度				*/
	double		b;		/* 旋转轴在大摆动部件摆动的角度 */
	double		c;		/* 旋转轴的旋转角度				*/
}DOUBLEANGLE;

typedef struct tagBALLDATA
{
	int nIdx;					/*					  */
	int nSeq;					/* 此类型工件边的序号 */
	int nType;					/* 工件的类型		  */
	DOUBLEPOINT		ptPara;		/* XYZ轴数据		  */
	DOUBLEANGLE		aglPara;	/* ABC轴数据    	  */
} BALLDATA, *PBALLDATA;

class AFX_EXT_CLASS CBallCutDll  
{
protected:
	/* 弧度角度转换 */
	double Convert2Radian(const double angle);
	double Convert2Angle(const double radian);
	/* 角度计算 */
	DOUBLEANGLE GetCutAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetRoateAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetCutAngle2(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);

	//赤道板
	/*第一边*/
	DOUBLEPOINT GetEquatorLongPt(double angle, double swingAngle);
	BOOL GetEquatorLong();
	/*第二边*/
	DOUBLEPOINT GetEquatorShortPt(double angle, double swingAngle);
	BOOL GetEquatorShort();
	/*第三边*/
	BOOL GetEquatorLongR();
	/*第四边*/
	BOOL GetEquatorShortR();
	
	//极中
	/*第一边*/
	DOUBLEPOINT GetCenterLongPt(double angle, double swingAngle);
	BOOL GetCenterLong();
	/*第二边*/
	DOUBLEPOINT GetCenterShortPt(double angle, double swingAngle);
	BOOL GetCenterShort();
	/*第三边*/
	BOOL GetCenterLongR();
	/*第四边*/
	BOOL GetCenterShortR();

	//极侧
	/*第一边*/
	DOUBLEPOINT GetEdgeLongPt(double angle, double PoleElvtion);
	BOOL GetEdgeLong();
	/*第二边*/
	DOUBLEPOINT GetEdgeShortPt(double angle, double swingAngle, double EdgeElvtion);
	BOOL GetEdgeShort();
	/*第三边*/
	DOUBLEPOINT GetEdgeLongRPt(double angle, double PoleElvtion);
	BOOL GetEdgeLongR();
	/*第四边*/
	BOOL GetEdgeShortR();

	//极边
	/*第一边*/
	DOUBLEPOINT GetSideLongPt(double equatorAlpha, double sideBeta, double centerAlpha, double sideElvtion);/*sideBeta为两条对称短边中点与球心的夹角*/
	BOOL GetSideLong();
	/*第二边*/
	DOUBLEPOINT GetSideShortPt(double angle, double sideBeta, double centerAlpha, double sideElvtion);
	BOOL GetSideShort();

	/*第三边*/
	DOUBLEPOINT GetSideLongRPt(double angle, double Elvtion);
	BOOL GetSideLongR();

	/*第四边*/
	BOOL GetSideShortR();

	
private:
	//存放各个轴数据的链表，绝对值的
	CList<BALLDATA, BALLDATA> m_lstBallEquator;
	CList<BALLDATA, BALLDATA> m_lstBallCenter;
	CList<BALLDATA, BALLDATA> m_lstBallEdge;
	CList<BALLDATA, BALLDATA> m_lstBallSide;

	//////////////////////////////////////////////////////////////////////////
	double  m_dRadius;			//球的内径

	double m_dR2;				//大摆动部件的半径

	double m_dAgleMore;			//过切角度：切割每条边的时候多走的角度

	double m_dBeginPosEq;
	double m_dBeginPosEd;
	double m_dBeginPosCe;
	double m_dBeginPosSi;
	//赤道数据
	struct tagEQUATOR 
	{
	//短边中心与球心的夹角，长边中心与球心的夹角，长边精度，短边精度	
		double AglAlpha,         AglBeta,        AccAlpha,  AccBate;
	}m_stcEquatorData;
	
	//极中数据
	struct tagCENTER 
	{	
	//  短边中心与球心的夹角，长边中心与球心的夹角,长边精度，短边精度,	
		double AglAlpha,         AglBeta,            AccAlpha, AccBate;
	//长边两端点与球心的夹角，短边两端点与球心的夹角
		double EnAglAlpha,       EnAglBeta;
	}m_stcCenterData;

	//极侧数据
	struct tagEDGE 
	{	
		//    短边起始的角度，短边结束的角度 长边精度，短边精度,	
		double AglStart,AglEnd,               AccAlpha, AccBate;
		//长对边两端点与球心的夹角，短边两端点与球心的夹角
		double AglAlpha,			AglBeta;	      
	}m_stcEdgeData;

	//极边
	struct tagSIDE 
	{	
		//90度，             短边端点少的角度，长边精度，短边精度,	
		double AglAlpha90,         AglBeta,         AccAlpha, AccBate;
	}m_stcSideData;
	//////////////////////////////////////////////////////////////////////////
	
public:

	CBallCutDll();
	virtual ~CBallCutDll();
	CBallCutDll(int Radius); //


	//获取各个轴数据链表的引用
	const CList<BALLDATA, BALLDATA>* GetLstEquator();
	const CList<BALLDATA, BALLDATA>* GetLstCenter();
	const CList<BALLDATA, BALLDATA>* GetLstEdge();
	const CList<BALLDATA, BALLDATA>* GetLstSide();

	//存放各个轴数据的链表，每个点的值的(增量)	
	CList<BALLDATA, BALLDATA> m_lstEquator;
	CList<BALLDATA, BALLDATA> m_lstCenter;
	CList<BALLDATA, BALLDATA> m_lstEdge;
	CList<BALLDATA, BALLDATA> m_lstSide;
	

	/*
	 *	函数名称：GetEquator
	 *	函数功能：获取赤道板各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：double angle: 两短边中点与球心连线的夹角
				  double swingAngle:两长边中点与球心连线的夹角
				  double angleAcc:angle步进
				  double swingAngleAcc:swingAngle步进
	 */
	BOOL GetEquator();

	/*
	 *	函数名称：GetCenter
	 *	函数功能：获取极中各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：double angle: 两短边中点与球心连线的夹角
				  double swingAngle:两长边中点与球心连线的夹角
				  double angleAcc:angle步进
				  double swingAngleAcc:swingAngle步进
	 */
	BOOL GetCenter();

	
	/*
	 *	函数名称：GetEdge
	 *	函数功能：获取极侧各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：double edgeAlpha：极侧长边两端点与球心连线的夹角
				  double edgeBeta： 极侧长对边两端点与球心连线的夹角
				  double edgeElvtion：极侧图形长边、长边对边与球心连线的夹角
				  -----------------------------------------------------------
				  double centerAlpha：极中两短边中点与球心连线的夹角
				  double centerGamma：极中图形两长边中点与球心连线的夹角

				  double angleAcc:  edgeAlpha的步进
				  double edgeElvtionAcc：极侧图形短边的步进
				  
		备注：GetEdgeShort中第三个参数+2°的原因：不加这2°会有地方切不着
	 */
	BOOL GetEdge();
	/*
	 *	函数名称：GetSide
	 *	函数功能：获取极边各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：sideBeta：长边两端点与平面圆心的夹角
				  sideElvtion: 长边中点、长对边中点与球心连线的夹角
				  ----------------------------------------------------
				  centerAlpha: 极中两短边中点与球心的连线的夹角
				  equatorAlpha: 赤道两短边中点与球心连线的夹角
				  edgeBeta：极侧长对边两端点与球心连线的夹角

				  double aglAcc: 角度步进（精度）
	 */
	BOOL GetSide();

	//半径
	void SetRadius(double radius) { m_dRadius = radius; }
	double GetRaius() const { return m_dRadius; }
	//R2
	void SetR2(double r2) { m_dR2 = r2; }
	double GetR2() const { return m_dR2;}
	//过切角度
	void SetAglMore(double agl) { m_dAgleMore = agl; }
	double GetAglMore() { return m_dAgleMore; }
};


class AFX_EXT_CLASS CBallCut2Dll  
{
protected:
	/* 弧度角度转换 */
	double Convert2Radian(const double angle);
	double Convert2Angle(const double radian);
	/* 角度计算 */
	DOUBLEANGLE GetCutAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetRoateAngle(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	DOUBLEANGLE GetCutAngle2(const DOUBLEPOINT& pt, const DOUBLEPOINT& ptNext);
	
	//赤道板
	/*第一边*/
	DOUBLEPOINT GetEquatorLongPt(double angle, double swingAngle);
	BOOL GetEquatorLong(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*第二边*/
	DOUBLEPOINT GetEquatorShortPt(double angle, double swingAngle);
	BOOL GetEquatorShort(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*第三边*/
	BOOL GetEquatorLongR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*第四边*/
	BOOL GetEquatorShortR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);

	//极中
	/*第一边*/
	DOUBLEPOINT GetCenterLongPt(double angle, double swingAngle);
	BOOL GetCenterLong(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*第二边*/
	DOUBLEPOINT GetCenterShortPt(double angle, double swingAngle);
	BOOL GetCenterShort(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*第三边*/
	BOOL GetCenterLongR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);
	/*第四边*/
	BOOL GetCenterShortR(double angle, double swingAngle, double angleAcc, double swingAngleAcc);

	//极侧
	/*第一边*/
	DOUBLEPOINT GetEdgeLongPt(double aglAlpha,  double EdgeElvtion, double equatorAlpha, double centerGamma);
	BOOL GetEdgeLong(double aglAlpha, double angleAcc, double EdgeElvtion, double equatorAlpha, double centerGamma);
	/*第二边*/
	DOUBLEPOINT GetEdgeLongRPt(double angle, double PoleElvtion);
	BOOL GetEdgeLongR(double angle, double angleAcc, double EdgeElvtion);


private:
	//存放各个轴数据的链表
	CList<BALLDATA, BALLDATA> m_lstBallEquator;
	CList<BALLDATA, BALLDATA> m_lstBallCenter;
	CList<BALLDATA, BALLDATA> m_lstBallEdge;

	double  m_dRadius;			//球的内径：4600mm
	double m_dR2;				//大摆动部件的半径
	double m_dAgleMore;			//过切角度：切割每条边的时候多走的角度

public:
	CBallCut2Dll()
	{
		m_dAgleMore  = 0;
	}
	virtual ~CBallCut2Dll();

	//获取各个轴数据链表的引用
	const CList<BALLDATA, BALLDATA>* GetLstEquator();
	const CList<BALLDATA, BALLDATA>* GetLstCenter();
	const CList<BALLDATA, BALLDATA>* GetLstEdge();

	/*
	 *	函数名称：GetEquator
	 *	函数功能：获取赤道板各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：double angle: 两短边中点与球心连线的夹角
				  double swingAngle:两长边中点与球心连线的夹角
				  double angleAcc:angle步进
				  double swingAngleAcc:swingAngle步进
	 */
	BOOL GetEquator(double angle, double swingAngle, double angleAcc, double swingAngleAcc);

	/*
	 *	函数名称：GetCenter
	 *	函数功能：获取极中各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：centerAlpha：两短边中点与球心连线的夹角
				  centerGamma：两长边中点与球心连线的夹角
				  centerPlane：短边两端点与所在平面圆圆心的夹角

				  double angleAcc:angle步进
				  double swingAngleAcc:swingAngle步进
	 */
	BOOL GetCenter(double angle, double swingAngle, double aglPlane, double angleAcc, double swingAngleAcc);

	/*
	 *	函数名称：GetEdge
	 *	函数功能：获取极侧各个轴的数据
	 *  返回值：  BOOL: TRUE表示获取数据成功, FALSE表示获取数据失败
		参数说明：edgeAlpha：长对边两点与球心连线的夹角
				  aglPlane：长边两端点与所在平面圆圆心的夹角
				  edgeElvtion：长边和长对边中点与球心连线的夹角
				  -----------------------------------------------------
				  equatorAlpha：两短边中点与球心连线的夹角
				  centerAlpha：两短边中点与球心连线的夹角

				  double aglAcc：角度步进(精度)
	 */
	BOOL GetEdge(double edgeAlpha, double aglAcc, double aglPlane, double edgeElvtion, \
		double equatorAlpha, double centeralpha);
	

	//半径
	void SetRadius(double radius) { m_dRadius = radius; }
	double GetRaius() const { return m_dRadius; }
	//大摆动部件的半径R2
	void SetR2(double r2) { m_dR2 = r2; }
	double GetR2() const { return m_dR2; }
	//过切角度
	void SetAglMore(double agl) { m_dAgleMore = agl; }
	double GetAglMore() { return m_dAgleMore; }

};


#endif // !defined(AFX_BALLCUTDLL_H__2AADEF72_BC6D_467B_A65C_F7C9DE611F63__INCLUDED_)
