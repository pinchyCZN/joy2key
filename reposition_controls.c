#include <windows.h>
#include "resource.h"
#include <stdio.h>

enum{
	CONTROL_ID,
	XPOS,YPOS,
	WIDTH,HEIGHT,
	HUG_L,
	HUG_R,
	HUG_T,
	HUG_B,
	HUG_CTRL_X,
	HUG_CTRL_Y,
	HUG_HEIGHT,
	HUG_WIDTH,
	HUG_CTRL_TXT_X,
	HUG_CTRL_TXT_Y,
	HUG_CTRL_TXT_X_,
	HUG_CTRL_TXT_Y_,
	SIZE_HEIGHT_OFF,
	SIZE_WIDTH_OFF,
	SIZE_HEIGHT_PER,
	SIZE_WIDTH_PER,
	SIZE_TEXT_CTRL,
	CONTROL_FINISH,
	RESIZE_FINISH
};

int process_anchor_list(HWND hwnd,short *list)
{
	int limit=9999;
	int i=0,j,x,y,width,height;
	HWND dlg_item;
	HDC	 hdc;
	RECT crect;
	SIZE text_size;
	char str[255];
	double f;
	int done=FALSE;
	int last_text=0;

	memset(&crect,0,sizeof(crect));
	hdc=GetDC(hwnd);
	GetClientRect(hwnd, &crect);
	do{
		switch(list[i]){
		case CONTROL_ID:
			x=y=width=height=0;
			dlg_item=GetDlgItem(hwnd,list[i+1]);
			if(dlg_item==NULL)
				done=TRUE;
			break;
		case XPOS:
			x+=list[i+1];
			break;
		case YPOS:
			y+=list[i+1];
			break;
		case WIDTH:
			width+=list[i+1];
			break;
		case HEIGHT:
			height+=list[i+1];
			break;
		case HUG_L:
			x+=crect.left+list[i+1];
			break;
		case HUG_R:
			x+=crect.right+list[i+1];
			break;
		case HUG_T:
			y+=crect.top+list[i+1];
			break;
		case HUG_B:
			y+=crect.bottom+list[i+1];
			break;
		case HUG_CTRL_X:
			break;
		case HUG_CTRL_Y:
			break;
		case HUG_HEIGHT:
			j=crect.bottom-crect.top;
			f=(double)list[i+1]/1000.0;
			y+=j*f;
			break;
		case HUG_WIDTH:
			j=crect.right-crect.left;
			f=(double)list[i+1]/1000.0;
			x+=j*f;
			break;
		case HUG_CTRL_TXT_X:
			if(last_text!=list[i+1]){
				GetDlgItemText(hwnd,list[i+1],str,sizeof(str)-1);
				GetTextExtentPoint32(hdc,str,strlen(str),&text_size);
				last_text=list[i+1];
			}
			x+=text_size.cx;
			break;
		case HUG_CTRL_TXT_X_:
			if(last_text!=list[i+1]){
				GetDlgItemText(hwnd,list[i+1],str,sizeof(str)-1);
				GetTextExtentPoint32(hdc,str,strlen(str),&text_size);
				last_text=list[i+1];
			}
			x-=text_size.cx;
			break;
		case HUG_CTRL_TXT_Y:
			if(last_text!=list[i+1]){
				GetDlgItemText(hwnd,list[i+1],str,sizeof(str)-1);
				GetTextExtentPoint32(hdc,str,strlen(str),&text_size);
				last_text=list[i+1];
			}
			y+=text_size.cy;
			break;
		case HUG_CTRL_TXT_Y_:
			if(last_text!=list[i+1]){
				GetDlgItemText(hwnd,list[i+1],str,sizeof(str)-1);
				GetTextExtentPoint32(hdc,str,strlen(str),&text_size);
				last_text=list[i+1];
			}
			y-=text_size.cy;
			break;
		case SIZE_HEIGHT_OFF:
			height+=crect.bottom-crect.top+list[i+1];
			break;
		case SIZE_WIDTH_OFF:
			width+=crect.right-crect.left+list[i+1];
			break;
		case SIZE_HEIGHT_PER:
			j=crect.bottom-crect.top;
			f=(double)list[i+1]/1000.0;
			height+=f*j;
			break;
		case SIZE_WIDTH_PER:
			j=crect.right-crect.left;
			f=(double)list[i+1]/1000.0;
			width+=f*j;
			break;
		case SIZE_TEXT_CTRL:
			if(last_text!=list[i+1]){
				GetDlgItemText(hwnd,list[i+1],str,sizeof(str)-1);
				GetTextExtentPoint32(hdc,str,strlen(str),&text_size);
				last_text=list[i+1];
			}
			width+=text_size.cx;
			height+=text_size.cy;
			break;
		case CONTROL_FINISH:
			SetWindowPos(dlg_item,NULL,x,y,width,height, SWP_NOZORDER);
			break;
		case RESIZE_FINISH:
			done=TRUE;
			break;
		default:
			printf("bad command %i\n",list[i]);
			break;
		}
		i+=2;
		if(i>limit)
			done=TRUE;
	}while(!done);
	ReleaseDC(hwnd,hdc);
	return TRUE;
}
short anchor_list[]={
	CONTROL_ID,IDC_CONTROLLER,
				HUG_WIDTH,100,
				//XPOS,80,
				YPOS,10,
				SIZE_WIDTH_PER,750,
				SIZE_HEIGHT_PER,1000,
				CONTROL_FINISH,-1,

	CONTROL_ID,IDC_CONFIG,
				HUG_WIDTH,100,
//				XPOS,80,
				YPOS,50,
				SIZE_WIDTH_PER,750,
				SIZE_HEIGHT_PER,1000,
				CONTROL_FINISH,-1,
	CONTROL_ID,IDC_REFRESH,
				HUG_WIDTH,100,
				//XPOS,80,
				YPOS,30,
				SIZE_WIDTH_PER,150,
				HEIGHT,18,
				CONTROL_FINISH,-1,

	CONTROL_ID,IDCANCEL,
				XPOS,5,HUG_WIDTH,870,
				HUG_T,5,
				SIZE_WIDTH_PER,120,HEIGHT,25,
				CONTROL_FINISH,-1,
	CONTROL_ID,IDSAVE,
				XPOS,5,HUG_WIDTH,870,
				HUG_T,50,
				SIZE_WIDTH_PER,120,HEIGHT,25,
				CONTROL_FINISH,-1,
	CONTROL_ID,IDC_CONTROLLER_STATIC,
				XPOS,0,YPOS,10,
				SIZE_WIDTH_PER,88,HEIGHT,25,
				CONTROL_FINISH,-1,
	CONTROL_ID,IDC_CONFIG_STATIC,
				XPOS,0,YPOS,50,
				SIZE_WIDTH_PER,88,HEIGHT,25,
				CONTROL_FINISH,-1,
				
	CONTROL_ID,IDC_DELETE_CONFIG,
				HUG_T,78,HUG_WIDTH,400,
				SIZE_WIDTH_PER,160,HEIGHT,25,
				CONTROL_FINISH,-1,
	CONTROL_ID,IDC_NEW_CONFIG,
				HUG_T,78,HUG_WIDTH,680,
				SIZE_WIDTH_PER,160,HEIGHT,25,
				CONTROL_FINISH,-1,
				


/*
	CONTROL_ID,ID_SYNCTIME,
				XPOS,5,HUG_WIDTH,870,
				HUG_T,10,HUG_HEIGHT,166,
				SIZE_WIDTH_PER,125,SIZE_HEIGHT_PER,166,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_ONTOP1, XPOS,-95,HUG_WIDTH,870,HUG_T,5,SIZE_TEXT_CTRL,IDC_ONTOP1,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_FREEZE, XPOS,-95,HUG_WIDTH,870,HUG_T,22,SIZE_TEXT_CTRL,IDC_ONTOP1,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_UTC,    XPOS,-95,HUG_WIDTH,870,HUG_T,39,SIZE_TEXT_CTRL,IDC_ONTOP1,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_NTPSERVER,
				HUG_R,-5,HUG_CTRL_TXT_X_,IDC_NTPSERVER,
				HUG_HEIGHT,333,YPOS,14,
				SIZE_TEXT_CTRL,IDC_NTPSERVER,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_HELPSTATIC,HUG_L,15,HUG_B,-55,SIZE_TEXT_CTRL,IDC_HELPSTATIC,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_STATIC_CURRENT_TIME,
				HUG_L,15,
				HUG_HEIGHT,21,
				SIZE_TEXT_CTRL,IDC_STATIC_CURRENT_TIME,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_CTIME,  
				HUG_L,15,
				HUG_HEIGHT,21,HUG_CTRL_TXT_Y,IDC_STATIC_CURRENT_TIME,
				SIZE_TEXT_CTRL,IDC_CTIME,HEIGHT,10,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_STATIC_TARGET_TIME,
				HUG_WIDTH,333,
				HUG_HEIGHT,21,
				SIZE_TEXT_CTRL,IDC_STATIC_TARGET_TIME,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_TARGET,
				HUG_WIDTH,333,
				HUG_HEIGHT,21,HUG_CTRL_TXT_Y,IDC_STATIC_TARGET_TIME,
				SIZE_TEXT_CTRL,IDC_TARGET,HEIGHT,10,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_CLRHOUR,
				HUG_WIDTH,333,
				YPOS,10,HUG_HEIGHT,21,HUG_CTRL_TXT_Y,IDC_STATIC_TARGET_TIME,HUG_CTRL_TXT_Y,IDC_TARGET,
				WIDTH,20,HEIGHT,20,SIZE_TEXT_CTRL,IDC_CLRHOUR,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_CLRMIN,
				XPOS,20,HUG_WIDTH,333,HUG_CTRL_TXT_X,IDC_CLRHOUR,
				YPOS,10,HUG_HEIGHT,21,HUG_CTRL_TXT_Y,IDC_STATIC_TARGET_TIME,HUG_CTRL_TXT_Y,IDC_TARGET,
				WIDTH,20,HEIGHT,20,SIZE_TEXT_CTRL,IDC_CLRHOUR,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_CLRSEC,
				XPOS,40,HUG_WIDTH,333,HUG_CTRL_TXT_X,IDC_CLRHOUR,HUG_CTRL_TXT_X,IDC_CLRHOUR,
				YPOS,10,HUG_HEIGHT,21,HUG_CTRL_TXT_Y,IDC_STATIC_TARGET_TIME,HUG_CTRL_TXT_Y,IDC_TARGET,
				WIDTH,20,HEIGHT,20,SIZE_TEXT_CTRL,IDC_CLRHOUR,CONTROL_FINISH,-1,
	CONTROL_ID,IDC_LIST1,
				XPOS,20,HUG_WIDTH,500,HUG_HEIGHT,500,SIZE_WIDTH_PER,100,SIZE_HEIGHT_PER,100,

*/
	RESIZE_FINISH
};

int reposition_controls(HWND hwnd)
{
	RECT	rect;
	process_anchor_list(hwnd,anchor_list);
	InvalidateRect(hwnd,&rect,TRUE);
	return TRUE;
}

#define GRIPPIE_SQUARE_SIZE 15
static HANDLE grippy;
static HWND grip_hwnd=0;

int create_grippy(HWND hwnd)
{
	RECT client_rect;
	GetClientRect(hwnd,&client_rect);
	
	grip_hwnd=CreateWindow("Scrollbar",NULL,WS_CHILD|WS_VISIBLE|SBS_SIZEGRIP,
		client_rect.right-GRIPPIE_SQUARE_SIZE,
		client_rect.bottom-GRIPPIE_SQUARE_SIZE,
		GRIPPIE_SQUARE_SIZE,GRIPPIE_SQUARE_SIZE,
		hwnd, NULL,NULL,NULL);

	return 0;
}

int grippy_move(HWND hwnd)
{
	RECT client_rect;
	GetClientRect(hwnd,&client_rect);
	if(grip_hwnd!=0)
	{
		SetWindowPos(grip_hwnd,NULL,
			client_rect.right-GRIPPIE_SQUARE_SIZE,
			client_rect.bottom-GRIPPIE_SQUARE_SIZE,
			GRIPPIE_SQUARE_SIZE,GRIPPIE_SQUARE_SIZE,
			SWP_NOZORDER|SWP_SHOWWINDOW);
	}
	return 0;
}

