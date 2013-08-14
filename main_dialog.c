#define _WIN32_WINNT 0x400
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include "resource.h"

extern HINSTANCE ghInstance;
#define max_buttons 50
HWND guibuttons[max_buttons];
int init_list=TRUE;
int load_controller_image(HWND hwnd,BYTE *buf,int buf_size)
{
	FILE *f;
	char config[MAX_PATH],fname[MAX_PATH];
	int index,result=FALSE;
	index=SendMessage(hwnd,CB_GETCURSEL,0,0);
	memset(config,0,sizeof(config));
	if(SendMessage(hwnd,CB_GETLBTEXT,index,(LPARAM)config)!=CB_ERR){
		if(get_ini_str(config,"image",fname,sizeof(fname))){
			f=fopen(fname,"rb");
			if(f!=0){
				fseek(f,0x36,SEEK_SET);
				fread(buf,1,buf_size,f);
				fclose(f);
				result=TRUE;
			}
		}
	}
	return result;
}
int populate_buttons(HWND hwnd,HWND controller)
{
	int i;
	int button;
	char str[255];
	char key[40];
	char config[80];
	int x,y,w,h;
	RECT rect;

	if(init_list){
		memset(guibuttons,0,sizeof(guibuttons));
		init_list=FALSE;
	}
	sprintf(config,"CONFIG0");
	i=SendMessage(controller,CB_GETCURSEL,0,0);
	SendMessage(controller,CB_GETLBTEXT,i,config);
	for(i=0;i<max_buttons;i++){
		button=i+1;
		_snprintf(key,sizeof(key),"GUIB%u",button);
		memset(str,0,sizeof(str));
		if(get_ini_str(config,key,str,sizeof(str))){
			x=y=w=h=10;
			sscanf(str,"%u,%u,%u,%u",&x,&y,&w,&h);
			sprintf(str,"B%u",button);
			GetClientRect(hwnd,&rect);
			x=x*(rect.right-rect.left)/640;
			y=y*(rect.bottom-78-rect.top)/580;
			y+=78;
			w=w*(rect.right-rect.left)/640;
			h=h*(rect.bottom-rect.top)/580;

			if(guibuttons[i]==0){
				guibuttons[i]=CreateWindow("BUTTON", str, WS_TABSTOP|WS_CHILD|WS_VISIBLE,
					x, y, w, h,
					hwnd, (HMENU)(2000+i), NULL, NULL);
			}
			else{
				MoveWindow(guibuttons[i],x,y,w,h,TRUE);
			}
		}
	}
	return TRUE;
}

int check_axis(int button)
{
	return FALSE;
}

