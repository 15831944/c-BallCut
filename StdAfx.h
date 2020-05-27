// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__246AADFB_7138_49EC_B879_B08D3114D555__INCLUDED_)
#define AFX_STDAFX_H__246AADFB_7138_49EC_B879_B08D3114D555__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls

#endif // _AFX_NO_AFXCMN_SUPPORT

/************************************************************************/
/*                                  *_*                                 */
/************************************************************************/

#include "HandDll.h"				// HandDll动态库的头文件
#include "galil\\Dmcwin.h"			// Galil控制器的头文件
#import "C:\Program Files\Common Files\System\Ado\msado15.dll" no_namespace rename ("EOF","adoEOF") rename ("BOF","adoBOF")
#include "odbcinst.h"       //注册数据库用
#include "ClrButton.h"		
#include "AlarmDll.h"				// 报警的头文件
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__246AADFB_7138_49EC_B879_B08D3114D555__INCLUDED_)
