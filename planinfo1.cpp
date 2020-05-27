// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "planinfo1.h"

// Dispatch interfaces referenced by this interface
#include "font1.h"

/////////////////////////////////////////////////////////////////////////////
// CPlanInfo

IMPLEMENT_DYNCREATE(CPlanInfo, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CPlanInfo properties

OLE_COLOR CPlanInfo::GetBackColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_BACKCOLOR, VT_I4, (void*)&result);
	return result;
}

void CPlanInfo::SetBackColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_BACKCOLOR, VT_I4, propVal);
}

CString CPlanInfo::GetCaption()
{
	CString result;
	GetProperty(DISPID_CAPTION, VT_BSTR, (void*)&result);
	return result;
}

void CPlanInfo::SetCaption(LPCTSTR propVal)
{
	SetProperty(DISPID_CAPTION, VT_BSTR, propVal);
}

COleFont CPlanInfo::GetFont()
{
	LPDISPATCH pDispatch;
	GetProperty(DISPID_FONT, VT_DISPATCH, (void*)&pDispatch);
	return COleFont(pDispatch);
}

void CPlanInfo::SetFont(LPDISPATCH propVal)
{
	SetProperty(DISPID_FONT, VT_DISPATCH, propVal);
}

OLE_COLOR CPlanInfo::GetForeColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_FORECOLOR, VT_I4, (void*)&result);
	return result;
}

void CPlanInfo::SetForeColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_FORECOLOR, VT_I4, propVal);
}

long CPlanInfo::GetAlign()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void CPlanInfo::SetAlign(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

float CPlanInfo::GetMax()
{
	float result;
	GetProperty(0x2, VT_R4, (void*)&result);
	return result;
}

void CPlanInfo::SetMax(float propVal)
{
	SetProperty(0x2, VT_R4, propVal);
}

float CPlanInfo::GetMin()
{
	float result;
	GetProperty(0x3, VT_R4, (void*)&result);
	return result;
}

void CPlanInfo::SetMin(float propVal)
{
	SetProperty(0x3, VT_R4, propVal);
}

float CPlanInfo::GetValue()
{
	float result;
	GetProperty(0x4, VT_R4, (void*)&result);
	return result;
}

void CPlanInfo::SetValue(float propVal)
{
	SetProperty(0x4, VT_R4, propVal);
}

unsigned long CPlanInfo::GetTextColor()
{
	unsigned long result;
	GetProperty(0x5, VT_I4, (void*)&result);
	return result;
}

void CPlanInfo::SetTextColor(unsigned long propVal)
{
	SetProperty(0x5, VT_I4, propVal);
}

unsigned long CPlanInfo::GetScaleColor()
{
	unsigned long result;
	GetProperty(0x6, VT_I4, (void*)&result);
	return result;
}

void CPlanInfo::SetScaleColor(unsigned long propVal)
{
	SetProperty(0x6, VT_I4, propVal);
}

float CPlanInfo::GetPlanValue()
{
	float result;
	GetProperty(0x7, VT_R4, (void*)&result);
	return result;
}

void CPlanInfo::SetPlanValue(float propVal)
{
	SetProperty(0x7, VT_R4, propVal);
}

unsigned long CPlanInfo::GetPlanColor()
{
	unsigned long result;
	GetProperty(0x8, VT_I4, (void*)&result);
	return result;
}

void CPlanInfo::SetPlanColor(unsigned long propVal)
{
	SetProperty(0x8, VT_I4, propVal);
}

BOOL CPlanInfo::GetBorder()
{
	BOOL result;
	GetProperty(0x9, VT_BOOL, (void*)&result);
	return result;
}

void CPlanInfo::SetBorder(BOOL propVal)
{
	SetProperty(0x9, VT_BOOL, propVal);
}

BOOL CPlanInfo::GetDisplayCaption()
{
	BOOL result;
	GetProperty(0xa, VT_BOOL, (void*)&result);
	return result;
}

void CPlanInfo::SetDisplayCaption(BOOL propVal)
{
	SetProperty(0xa, VT_BOOL, propVal);
}

short CPlanInfo::GetDegree()
{
	short result;
	GetProperty(0xb, VT_I2, (void*)&result);
	return result;
}

void CPlanInfo::SetDegree(short propVal)
{
	SetProperty(0xb, VT_I2, propVal);
}

BOOL CPlanInfo::GetDisplayScale()
{
	BOOL result;
	GetProperty(0xc, VT_BOOL, (void*)&result);
	return result;
}

void CPlanInfo::SetDisplayScale(BOOL propVal)
{
	SetProperty(0xc, VT_BOOL, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CPlanInfo operations

float CPlanInfo::GetClickIndex()
{
	float result;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_R4, (void*)&result, NULL);
	return result;
}

void CPlanInfo::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
