#if !defined(AFX_CSPAN1_H__4BCDBE4D_DE5D_4739_8547_688C95315380__INCLUDED_)
#define AFX_CSPAN1_H__4BCDBE4D_DE5D_4739_8547_688C95315380__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CCSpan wrapper class

class CCSpan : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCSpan)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x71a5e095, 0x40da, 0x4a4d, { 0x83, 0xd3, 0x21, 0xd2, 0x9c, 0x89, 0xc7, 0xb5 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	long GetMaxValue();
	void SetMaxValue(long);
	long GetMinValue();
	void SetMinValue(long);
	unsigned long GetPointColor();
	void SetPointColor(unsigned long);
	CString GetTitle();
	void SetTitle(LPCTSTR);
	long GetScaleCount();
	void SetScaleCount(long);
	OLE_COLOR GetForeColor();
	void SetForeColor(OLE_COLOR);
	double GetPointValue();
	void SetPointValue(double);
	unsigned long GetBeginColor();
	void SetBeginColor(unsigned long);
	unsigned long GetMidColor();
	void SetMidColor(unsigned long);
	unsigned long GetEndColor();
	void SetEndColor(unsigned long);
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);
	long GetProgressValue();
	void SetProgressValue(long);

// Operations
public:
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSPAN1_H__4BCDBE4D_DE5D_4739_8547_688C95315380__INCLUDED_)
