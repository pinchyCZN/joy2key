#define _WIN32_WINNT 0x400
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include "resource.h"

extern HINSTANCE ghInstance;
extern LRESULT CALLBACK edit_action_dlg(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

LRESULT CALLBACK quick_record_dlg(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
	char str[255];
	print_msg(msg,lparam,wparam);
	switch(msg)
	{
	case WM_SHOWWINDOW:
		SetCapture(GetDlgItem(hwnd,IDCANCEL));
		SetCursor(LoadCursor(NULL,IDC_CROSS));
		break;
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch(LOWORD(wparam)){
		case IDCANCEL:
			SetCursor(LoadCursor(NULL,IDC_ARROW));
			EndDialog(hwnd,0);
			break;
		}
		break;
	case WM_CLOSE:
	case WM_QUIT:
		SetCursor(LoadCursor(NULL,IDC_ARROW));
		EndDialog(hwnd,0);
		break;
	}
	return 0;
}


int quick_record(HANDLE hwnd,int button)
{
	int result;
	HWND hdlg=0;
	hdlg=CreateDialog(ghInstance,MAKEINTRESOURCE(IDD_EDIT_ACTION),hwnd,edit_action_dlg);
	if(hdlg!=NULL){
		ShowWindow(hdlg, SW_SHOW);
		SendMessage(hdlg,WM_COMMAND,0,get_control_handle(1));
	}
//	result=DialogBox(ghInstance,MAKEINTRESOURCE(IDD_QUICKRECORD),hwnd,quick_record_dlg);
}