#define _WIN32_WINNT 0x400
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include "resource.h"

extern HINSTANCE ghInstance;
HWND hwnd_parent=0;
HWND hdlg=0;
BYTE pressed_keys[256];

int record_mode=FALSE;
int current_config=0;
int current_button=0;
int current_axis=0;
enum {
	ID_NULL=0,
	ID_RECORD,
	ID_STOP,
	ID_RECORDED, //edit control
	ID_DESCRIPTION,
	ID_EDITOR,
	ID_SCRIPT_EDIT
};

int get_record_mode()
{
	return record_mode;
}
int get_config_list(HWND hwnd,int list)
{
	int i;
	char str[80];
	SendMessage(GetDlgItem(hwnd,list),CB_RESETCONTENT,0,0);
	for(i=0;i<10;i++){
		sprintf(str,"item %i",i);
		SendMessage(GetDlgItem(hwnd,list),CB_ADDSTRING,0,(LPARAM)str);
	}
	return TRUE;
}

typedef struct {
	int control_id;
	char *class_name;
	char *text;
	int exstyle;
	int style;
	int x,y,width,height;
}CONTROL;
CONTROL tab_list1[]={ 
	{ID_NULL,"STATIC","A \"Simple\" action is a single press of\r\na combination of keys and buttons.\r\n"
		"Click record, then press the key or\r\ncombination of keys, then release.",0,WS_CHILD|WS_VISIBLE,25,94,195,58},
	{ID_RECORD,"BUTTON","Record",0,WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,320,100,70,25},
	{ID_STOP,"BUTTON","Stop",0,WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,320,140,70,25},
	{ID_NULL,"STATIC","Recorded:",0,WS_CHILD|WS_VISIBLE,25,160,60,30},
//	{ID_RECORDED,"EDIT","",WS_EX_CLIENTEDGE,WS_DISABLED|WS_TABSTOP|WS_CHILD|WS_VISIBLE,110,160,160,25},
	{ID_RECORDED,"EDIT","",WS_EX_CLIENTEDGE,WS_TABSTOP|WS_CHILD|WS_VISIBLE,110,160,160,25},
	{ID_NULL,"STATIC","Description:",0,WS_CHILD|WS_VISIBLE,25,190,70,30},
	{ID_DESCRIPTION,"EDIT","",WS_EX_CLIENTEDGE,WS_BORDER|WS_TABSTOP|WS_CHILD|WS_VISIBLE,110,190,160,80}
};
CONTROL tab_list2[]={
	{ID_EDITOR,"BUTTON","Editor",0,WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,330,100,70,25},
	{ID_SCRIPT_EDIT,"EDIT","",WS_EX_CLIENTEDGE,WS_BORDER|WS_TABSTOP|WS_CHILD|WS_VISIBLE,100,140,180,130},
	{ID_NULL,"STATIC","action_blah()",0,WS_CHILD|WS_VISIBLE,25,90,160,20}
};
static HWND controls1[sizeof(tab_list1)/sizeof(CONTROL)];
static HWND controls2[sizeof(tab_list2)/sizeof(CONTROL)];
int get_control_id(HWND hwndctl)
{
	int i,len,id=0;
	HWND *ctrls;
	CONTROL *list;
	ctrls=controls1;
	list=tab_list1;
	len=sizeof(tab_list1)/sizeof(CONTROL);
	for(i=0;i<len;i++){
		if(ctrls[i]==hwndctl){
			id=list[i].control_id;
			return id;
		}
	}
	ctrls=controls2;
	list=tab_list2;
	len=sizeof(tab_list2)/sizeof(CONTROL);
	for(i=0;i<len;i++){
		if(ctrls[i]==hwndctl){
			id=list[i].control_id;
			return id;
		}
	}
	return id;
}
HWND get_control_handle(int id)
{
	int i,len;
	HWND *ctrls,hwnd=0;
	CONTROL *list;
	ctrls=controls1;
	list=tab_list1;
	len=sizeof(tab_list1)/sizeof(CONTROL);
	for(i=0;i<len;i++){
		if(id==list[i].control_id){
			hwnd=ctrls[i];
			return hwnd;
		}
	}
	ctrls=controls2;
	list=tab_list2;
	len=sizeof(tab_list2)/sizeof(CONTROL);
	for(i=0;i<len;i++){
		if(id==list[i].control_id){
			hwnd=ctrls[i];
			return hwnd;
		}
	}
	return hwnd;
}
int switch_tab_controls(HWND hwnd,int tab)
{
	CONTROL *tab_list;
	int count_hide,count_create;
	int i;
	HWND *ctl_hide,*ctl_show;
	if(hwnd==0 && tab==0){
		memset(controls1,0,sizeof(controls1));
		memset(controls2,0,sizeof(controls2));
		return 0;
	}
	if(tab==0){
		count_hide=sizeof(controls2)/sizeof(int);
		count_create=sizeof(controls1)/sizeof(int);
		tab_list=tab_list1;
		ctl_hide=controls2;
		ctl_show=controls1;
	}
	else{
		count_hide=sizeof(controls1)/sizeof(int);
		count_create=sizeof(controls2)/sizeof(int);
		tab_list=tab_list2;
		ctl_hide=controls1;
		ctl_show=controls2;
	}
	for(i=0;i<count_hide;i++){
		if(ctl_hide[i]!=0)
			ShowWindow(ctl_hide[i],SW_HIDE);
	}
	for(i=0;i<count_create;i++){
		if(ctl_show[i]==0){
			ctl_show[i]=CreateWindowEx(tab_list[i].exstyle,tab_list[i].class_name,tab_list[i].text,tab_list[i].style,
							tab_list[i].x,tab_list[i].y,tab_list[i].width,tab_list[i].height,
							hwnd,NULL,(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE),NULL);			
			SendMessage(ctl_show[i],WM_SETFONT,(WPARAM)GetStockObject(DEFAULT_GUI_FONT),MAKELPARAM(1,0));
		}
		else
			ShowWindow(ctl_show[i],SW_SHOW);
	}
	return TRUE;

}
int check_action_name(HWND hwnd)
{
	int i;
	char str[255];
	char stat[40];
	memset(str,0,sizeof(str));
	GetDlgItemText(hwnd,IDC_ACTION_NAME,str,sizeof(str));
	if(strlen(str)==0)
		sprintf(stat,"<-- fill in");
	else{
		stat[0]=0;
		for(i=0;i<(int)strlen(str);i++){
			if(str[i]==' '||(str[i]>='0' && str[i]<='9') || (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
				;
			else{
				sprintf(stat,"<-- bad chars");
				break;
			}
		}
	}
	SetDlgItemText(hwnd,IDC_ACTION_STATUS,stat);
	if(stat[0]!=0){
		EnableWindow(GetDlgItem(hwnd,IDOK),FALSE);
		EnableWindow(GetDlgItem(hwnd,IDC_APPLY),FALSE);
	}
	else{
		EnableWindow(GetDlgItem(hwnd,IDOK),TRUE);
		EnableWindow(GetDlgItem(hwnd,IDC_APPLY),TRUE);
	}
	return 0;
}
int process_capture()
{
	char str[255];
	print_capture(pressed_keys,str,sizeof(str));
	SendMessage(get_control_handle(ID_RECORDED),WM_SETTEXT,0,(LPARAM)str);
}
int capture_input(UINT msg,WPARAM wparam,LPARAM lparam)
{
	print_msg(msg,lparam,wparam);
	//printf("msg=%08X lp=%08X wp=%08X\n",msg->message,msg->lParam,msg->wParam);
	switch(msg){
	case WM_LBUTTONDOWN:
		{
			RECT r;
			WORD x,y;
			GetWindowRect(get_control_handle(ID_STOP),&r);
			x=LOWORD(lparam);y=HIWORD(lparam);
			if((x>=0 && y>=0) && (x<(r.right-r.left) && y<(r.bottom-r.top))){
				SendMessage(get_control_handle(ID_RECORDED),WM_SETTEXT,0,(LPARAM)"nothing");
				SendMessage(get_control_handle(ID_STOP),BM_CLICK,0,0);
			}
			else{
				save_input(pressed_keys,VK_LBUTTON);
				process_capture();
			}
		}
		break;
	case WM_RBUTTONDOWN:
		save_input(pressed_keys,VK_RBUTTON);
		process_capture();
		break;
	case WM_MBUTTONDOWN:
		save_input(pressed_keys,VK_MBUTTON);
		process_capture();
		break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
		record_mode=FALSE;
		SendMessage(get_control_handle(ID_STOP),BM_CLICK,0,0);
		break;
	case WM_SYSKEYDOWN:
		save_input(pressed_keys,wparam);
		process_capture();
		print_key(wparam);
		break;
	case WM_SYSKEYUP:
		record_mode=FALSE;
		SendMessage(get_control_handle(ID_STOP),BM_CLICK,0,0);
		break;
	case WM_KEYFIRST:
		save_input(pressed_keys,wparam);
		process_capture();
		break;
	case WM_KEYUP:
		record_mode=FALSE;
		SendMessage(get_control_handle(ID_STOP),BM_CLICK,0,0);
		break;
	default:
		break;
	}
}
LRESULT CALLBACK edit_action_dlg(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	print_msg(message,lParam,wParam);
	switch(message)
	{
	case WM_SHOWWINDOW:
		break;
	case WM_INITDIALOG:
		SendMessage(GetDlgItem(hwnd,IDC_ACTION_NAME),EM_SETLIMITTEXT,200,0);
		{
		TCITEMA tc;
		HWND hctrl;
		hctrl=GetDlgItem(hwnd,IDC_TAB1);
		tc.mask=TCIF_TEXT;
		tc.pszText="Simple";
		TabCtrl_InsertItem(hctrl,0,&tc);
		tc.mask=TCIF_TEXT;
		tc.pszText="Script";
		TabCtrl_InsertItem(hctrl,1,&tc);
		switch_tab_controls(0,0);
		switch_tab_controls(hwnd,TabCtrl_GetCurSel(GetDlgItem(hwnd,IDC_TAB1)));
		}
		check_action_name(hwnd);
		break;
	case WM_NOTIFY:
		if(LOWORD(wParam)==IDC_TAB1){
			NMHDR *hdr;
			hdr=(NMHDR*)lParam;
			if(hdr->code==TCN_SELCHANGE){
				switch_tab_controls(hwnd,TabCtrl_GetCurSel(GetDlgItem(hwnd,IDC_TAB1)));
			}
		}
		break;
	case WM_COMMAND:
		//printf("wParam %08X lParam %08X msg %08X x=%i y=%i\n",wParam,lParam,message,LOWORD(lParam),HIWORD(lParam));
		switch(LOWORD(wParam))
		{
		case IDOK:
			save_button_keys(current_config,current_button,pressed_keys,sizeof(pressed_keys));
			DestroyWindow(hwnd);
			SetFocus(hwnd_parent);
			break;
		case IDC_APPLY:
			save_button_keys(current_config,current_button,pressed_keys,sizeof(pressed_keys));
			break;
		case IDC_ACTION_NAME:
			check_action_name(hwnd);
			break;
		case IDC_CLEAR_NAME:
			SetDlgItemText(hwnd,IDC_ACTION_NAME,"");
			break;
		case WM_DESTROY:
			hdlg=0;
			DestroyWindow(hwnd);
			SetFocus(hwnd_parent);
			break;
		default:
			switch(get_control_id((HWND)lParam)){
			case ID_RECORD:
				memset(pressed_keys,0,sizeof(pressed_keys));
				SendMessage(get_control_handle(ID_RECORDED),WM_SETTEXT,0,(LPARAM)"waiting...");
				record_mode=TRUE;
				EnableWindow(get_control_handle(ID_RECORD),FALSE);
				SetFocus(get_control_handle(ID_RECORD));
				//SetFocus(hwnd);
				//SetCapture(hwnd_parent);
				SetCapture(get_control_handle(ID_STOP));
				SetCursor(LoadCursor(NULL,IDC_CROSS));
				break;
			case ID_STOP:
				EnableWindow(get_control_handle(ID_RECORD),TRUE);
				ReleaseCapture();
				SetCursor(LoadCursor(NULL,IDC_ARROW));
				record_mode=FALSE;
				{
				char str[255];
				memset(str,0,sizeof(str));
				GetDlgItemText(hwnd,IDC_ACTION_NAME,str,sizeof(str));
				if(strlen(str)==0){
					memset(str,0,sizeof(str));
					SendMessage(get_control_handle(ID_RECORDED),WM_GETTEXT,sizeof(str),(LPARAM)str);
					if(strstr(str,"nothing")!=0){
						memset(pressed_keys,0,sizeof(pressed_keys));
					}
					else{
						sanatize_string(str,strlen(str));
						SetDlgItemText(hwnd,IDC_ACTION_NAME,str);
					}
				}
				}
				break;
			}
			break;
		}
		break;
	case WM_SETCURSOR:
		break;
	case WM_NCMOUSEMOVE:
	case WM_MOUSEFIRST:
		break;
	case WM_CLOSE:
		hdlg=0;
		DestroyWindow(hwnd);
		SetFocus(hwnd_parent);
		break;
	}
	return 0;
}

LRESULT CALLBACK assign_action_dlg(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
	char str[255];

	switch(msg)
	{
	case WM_SHOWWINDOW:
		break;
	case WM_INITDIALOG:
		get_config_list(hwnd,IDC_ACTION_LIST);
		SendMessage(GetDlgItem(hwnd,IDC_ACTION_LIST),CB_SETCURSEL,current_config,0);
		break;
	case WM_COMMAND:
		switch(LOWORD(wparam))
		{
		case WM_DESTROY:
			EndDialog(hwnd,0);
			break;
		case IDC_NEW_ACTION:
			hdlg=CreateDialog(ghInstance,MAKEINTRESOURCE(IDD_EDIT_ACTION),hwnd_parent,edit_action_dlg);
			if(hdlg!=NULL)
				ShowWindow(hdlg, SW_SHOW);
			EndDialog(hwnd,IDC_NEW_ACTION);
			break;
		case IDC_EDIT_ACTION:


			EndDialog(hwnd,IDC_EDIT_ACTION);
			break;
		case IDC_DELETE_ACTION:
			_snprintf(str,sizeof(str),"This will delete the action '%s' from this configuration. Do you want to do this?");
			if(IDYES==MessageBox(hwnd,str,"Confirm Delete",MB_YESNO)){
				//delete_config();
				EndDialog(hwnd,0);
			}
			break;
		case IDOK:
			EndDialog(hwnd,0);
			break;
		}
		break;
	case WM_CLOSE:
	case WM_QUIT:
		EndDialog(hwnd,0);
		break;
	}
	return 0;
}
int handle_button(HWND hwnd,int config,int button,int axis)
{
	int result;
	current_config=config;
	current_button=button;
	current_axis=axis;
	hwnd_parent=hwnd;
	result=DialogBox(ghInstance,MAKEINTRESOURCE(IDD_ASSIGN_ACTION),hwnd,assign_action_dlg);
	return 0;
}
int get_edit_dlg()
{
	return (int)hdlg;
}