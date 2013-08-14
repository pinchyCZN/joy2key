# Microsoft Developer Studio Project File - Name="joy2key" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=joy2key - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "joy2key.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "joy2key.mak" CFG="joy2key - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "joy2key - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "joy2key - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=Cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "joy2key - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=Link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "joy2key - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I ".\lib\\" /I ".\cint\lib\\" /I ".\flex\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=Link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib lua52.lib  dinput8.lib dxguid.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:".\lua\\" /libpath:"e:\DEV\MSVC_Projects\DX8_SDK\lib\\"

!ENDIF 

# Begin Target

# Name "joy2key - Win32 Release"
# Name "joy2key - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "flexbison"

# PROP Default_Filter ""
# End Group
# Begin Group "lua"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\lua\include\lauxlib.h
# End Source File
# Begin Source File

SOURCE=.\lua\include\lua.h
# End Source File
# Begin Source File

SOURCE=.\lua\include\lua.hpp
# End Source File
# Begin Source File

SOURCE=.\lua\include\luaconf.h
# End Source File
# Begin Source File

SOURCE=.\lua\include\lualib.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\cint.c
# End Source File
# Begin Source File

SOURCE=.\debug_print.c
# End Source File
# Begin Source File

SOURCE=.\edit_action.c
# End Source File
# Begin Source File

SOURCE=.\flex_bison.c
# End Source File
# Begin Source File

SOURCE=.\handle_scripts.c
# End Source File
# Begin Source File

SOURCE=.\joy2key.c
# End Source File
# Begin Source File

SOURCE=.\main_dialog.c
# End Source File
# Begin Source File

SOURCE=.\quick_record.c
# End Source File
# Begin Source File

SOURCE=.\reposition_controls.c
# End Source File
# Begin Source File

SOURCE=.\script_stuff.c
# End Source File
# Begin Source File

SOURCE=.\trex.c
# End Source File
# Begin Source File

SOURCE=.\yyparse.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cint\closure.h
# End Source File
# Begin Source File

SOURCE=.\cint\complain.h
# End Source File
# Begin Source File

SOURCE=.\cint\config.h
# End Source File
# Begin Source File

SOURCE=.\cint\conflicts.h
# End Source File
# Begin Source File

SOURCE=.\cint\derives.h
# End Source File
# Begin Source File

SOURCE=.\cint\lib\error.h
# End Source File
# Begin Source File

SOURCE=.\cint\files.h
# End Source File
# Begin Source File

SOURCE=.\cint\getargs.h
# End Source File
# Begin Source File

SOURCE=.\cint\lib\getopt.h
# End Source File
# Begin Source File

SOURCE=.\cint\gram.h
# End Source File
# Begin Source File

SOURCE=.\cint\lalr.h
# End Source File
# Begin Source File

SOURCE=.\cint\lex.h
# End Source File
# Begin Source File

SOURCE=.\cint\LR0.h
# End Source File
# Begin Source File

SOURCE=.\cint\nullable.h
# End Source File
# Begin Source File

SOURCE=.\cint\lib\obstack.h
# End Source File
# Begin Source File

SOURCE=.\cint\output.h
# End Source File
# Begin Source File

SOURCE=.\cint\print.h
# End Source File
# Begin Source File

SOURCE=.\cint\print_graph.h
# End Source File
# Begin Source File

SOURCE=.\cint\lib\quote.h
# End Source File
# Begin Source File

SOURCE=.\cint\lib\quotearg.h
# End Source File
# Begin Source File

SOURCE=.\cint\reader.h
# End Source File
# Begin Source File

SOURCE=.\cint\reduce.h
# End Source File
# Begin Source File

SOURCE=.\scripts\script.lua.txt
# End Source File
# Begin Source File

SOURCE=.\cint\state.h
# End Source File
# Begin Source File

SOURCE=.\cint\symtab.h
# End Source File
# Begin Source File

SOURCE=.\cint\system.h
# End Source File
# Begin Source File

SOURCE=.\cint\types.h
# End Source File
# Begin Source File

SOURCE=.\cint\vcg.h
# End Source File
# Begin Source File

SOURCE=.\cint\vcg_defaults.h
# End Source File
# Begin Source File

SOURCE=.\cint\warshall.h
# End Source File
# Begin Source File

SOURCE=.\cint\lib\xalloc.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# End Group
# End Target
# End Project
