# Microsoft Developer Studio Project File - Name="BallCut" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=BallCut - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BallCut.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BallCut.mak" CFG="BallCut - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BallCut - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BallCut - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BallCut - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "BallCut - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "BallCut - Win32 Release"
# Name "BallCut - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BallCut.cpp
# End Source File
# Begin Source File

SOURCE=.\BallCut.rc
# End Source File
# Begin Source File

SOURCE=.\BallCutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BallCutDlg.h
# End Source File
# Begin Source File

SOURCE=.\btnctl.cpp
# End Source File
# Begin Source File

SOURCE=.\captioninfo1.cpp
# End Source File
# Begin Source File

SOURCE=.\ClrButton.cpp
# End Source File
# Begin Source File

SOURCE=.\cspan1.cpp
# End Source File
# Begin Source File

SOURCE=.\displayctrl1.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_KeyChar.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_KeyNumber.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAdjust.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCautionMessage.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgExamine.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgHand.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMachineParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgParamFourBall.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgParamThreeBall.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgWorkParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgZero.cpp
# End Source File
# Begin Source File

SOURCE=.\galil\Dmcwin.cpp
# End Source File
# Begin Source File

SOURCE=.\EditDoubleClick.cpp
# End Source File
# Begin Source File

SOURCE=.\font1.cpp
# End Source File
# Begin Source File

SOURCE=.\lamp2.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\planinfo1.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowFireCutPos.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UniButton.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AlarmDll.h
# End Source File
# Begin Source File

SOURCE=.\BallCut.h
# End Source File
# Begin Source File

SOURCE=.\BallCutDll.h
# End Source File
# Begin Source File

SOURCE=.\BallParmDef.h
# End Source File
# Begin Source File

SOURCE=.\btnctl.h
# End Source File
# Begin Source File

SOURCE=.\captioninfo1.h
# End Source File
# Begin Source File

SOURCE=.\ClrButton.h
# End Source File
# Begin Source File

SOURCE=.\cspan1.h
# End Source File
# Begin Source File

SOURCE=.\displayctrl1.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_KeyChar.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_KeyNumber.h
# End Source File
# Begin Source File

SOURCE=.\DlgAdjust.h
# End Source File
# Begin Source File

SOURCE=.\DlgCautionMessage.h
# End Source File
# Begin Source File

SOURCE=.\DlgExamine.h
# End Source File
# Begin Source File

SOURCE=.\DlgHand.h
# End Source File
# Begin Source File

SOURCE=.\DlgMachineParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgParamFourBall.h
# End Source File
# Begin Source File

SOURCE=.\DlgParamThreeBall.h
# End Source File
# Begin Source File

SOURCE=.\DlgWorkParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgZero.h
# End Source File
# Begin Source File

SOURCE=.\galil\Dmccom.h
# End Source File
# Begin Source File

SOURCE=.\galil\dmcdrc.h
# End Source File
# Begin Source File

SOURCE=.\galil\dmcdrco.h
# End Source File
# Begin Source File

SOURCE=.\galil\DMCMLIB.H
# End Source File
# Begin Source File

SOURCE=.\galil\Dmcwin.h
# End Source File
# Begin Source File

SOURCE=.\EditDoubleClick.h
# End Source File
# Begin Source File

SOURCE=.\font1.h
# End Source File
# Begin Source File

SOURCE=.\GeneralAlarm.h
# End Source File
# Begin Source File

SOURCE=.\HandDll.h
# End Source File
# Begin Source File

SOURCE=.\lamp2.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\planinfo1.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ShowFireCutPos.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UniButton.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\BUTTON\1.bmp
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\1赤道.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\BUTTON\2.bmp
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\2极中.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\BUTTON\3.bmp
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\3极侧.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\4极边.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\5赤道板.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\6极中板.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\7极侧板.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\BallCut.ico
# End Source File
# Begin Source File

SOURCE=.\res\BallCut.rc2
# End Source File
# Begin Source File

SOURCE=.\res\BUTTON\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\CAD-WAY1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\CAD-WAY2.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\C轴下刀1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\C轴下刀2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\EDIT-WAY1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\保存1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\保存2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\保存G1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\报警1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\报警2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\报警复位1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\报警复位2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\背景.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\编辑1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\编辑2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\编辑设置1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\编辑设置2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\参数1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\参数2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\参数备份1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\查询1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\查询2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\程序零点1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\程序零点2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\程序零点3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\赤道.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\返回1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\返回2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\分支界面.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\工件1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\工件2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\工件3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\关机1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\关机2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\回零1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\回零2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\回零3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\回零x1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\回零x2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\机械参数1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\机械参数2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\机械零点1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\机械零点2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\机械零点3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\极边.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\极侧.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\极中.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\精菱11.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\历史报警1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\历史报警2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\龙门校正1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\龙门校正2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\模拟1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\模拟2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\模拟3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割启动1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割启动2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割停止1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割停止2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割暂停1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割暂停2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\切割暂停3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\设置1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\设置2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\手动1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\手动2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\手动3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\手动小1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\手动小2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\输出点1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\输出点2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\停止1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\停止2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\自动1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\自动2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\BUTTON\自动3.bmp"
# End Source File
# Begin Source File

SOURCE=.\Debug\HandDll.lib
# End Source File
# End Group
# Begin Source File

SOURCE=.\Debug\msado15.tlh
# End Source File
# Begin Source File

SOURCE=.\msado15.tlh
# End Source File
# Begin Source File

SOURCE=.\msado15.tli
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\galil\DMC32.lib
# End Source File
# Begin Source File

SOURCE=.\galil\DMCMLIB.lib
# End Source File
# Begin Source File

SOURCE="C:\Program Files\Microsoft Visual Studio\VC98\Lib\ODBCCP32.LIB"
# End Source File
# Begin Source File

SOURCE=.\AlarmRecord.lib
# End Source File
# Begin Source File

SOURCE=.\HandDll.lib
# End Source File
# Begin Source File

SOURCE=.\MFCBallCut0D.lib
# End Source File
# End Target
# End Project
# Section BallCut : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font1.h
# 	2:8:ImplFile:font1.cpp
# End Section
# Section BallCut : {8C236C62-832C-441E-BA96-9FDB080C059E}
# 	2:21:DefaultSinkHeaderFile:captioninfo1.h
# 	2:16:DefaultSinkClass:CCaptionInfo
# End Section
# Section BallCut : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section BallCut : {1F1A4D94-9EE9-460D-A23B-2710BE388DDA}
# 	2:5:Class:CLamp
# 	2:10:HeaderFile:lamp2.h
# 	2:8:ImplFile:lamp2.cpp
# End Section
# Section BallCut : {DFAC5876-68AD-4858-9F59-C37422F10248}
# 	2:5:Class:CCSpan
# 	2:10:HeaderFile:cspan1.h
# 	2:8:ImplFile:cspan1.cpp
# End Section
# Section BallCut : {71A5E095-40DA-4A4D-83D3-21D29C89C7B5}
# 	2:21:DefaultSinkHeaderFile:cspan1.h
# 	2:16:DefaultSinkClass:CCSpan
# End Section
# Section BallCut : {81B9117E-72B5-4DE3-963B-0A3F5B06F66B}
# 	2:21:DefaultSinkHeaderFile:displayctrl1.h
# 	2:16:DefaultSinkClass:CDisplayCtrl
# End Section
# Section BallCut : {7C5CE390-4368-4CAB-B0E2-FF8D7D6F0631}
# 	2:5:Class:CBtnCtl
# 	2:10:HeaderFile:btnctl.h
# 	2:8:ImplFile:btnctl.cpp
# End Section
# Section BallCut : {D21D9466-82BF-42A1-8EDC-2ED1C85AB130}
# 	2:5:Class:CCaptionInfo
# 	2:10:HeaderFile:captioninfo1.h
# 	2:8:ImplFile:captioninfo1.cpp
# End Section
# Section BallCut : {5AB0622F-638F-4520-8591-A2B63E58ED4B}
# 	2:5:Class:CPlanInfo
# 	2:10:HeaderFile:planinfo1.h
# 	2:8:ImplFile:planinfo1.cpp
# End Section
# Section BallCut : {C06EA015-E48A-4FF2-8862-28925C248B46}
# 	2:21:DefaultSinkHeaderFile:btnctl.h
# 	2:16:DefaultSinkClass:CBtnCtl
# End Section
# Section BallCut : {36A58C54-2836-42DF-B0C2-B1BCB69006AA}
# 	2:5:Class:CDisplayCtrl
# 	2:10:HeaderFile:displayctrl1.h
# 	2:8:ImplFile:displayctrl1.cpp
# End Section
# Section BallCut : {9DA7072B-A6DB-4819-8FDC-C818CC82A02D}
# 	2:21:DefaultSinkHeaderFile:lamp2.h
# 	2:16:DefaultSinkClass:CLamp
# End Section
# Section BallCut : {769D5AAE-0342-424F-9ABD-386E44BA4123}
# 	2:21:DefaultSinkHeaderFile:planinfo1.h
# 	2:16:DefaultSinkClass:CPlanInfo
# End Section
