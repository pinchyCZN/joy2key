#define _WIN32_WINNT 0x400
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include "resource.h"

HWND		hWindow;
HINSTANCE	ghInstance;

#define BUF_WIDTH 640
#define BUF_HEIGHT 580
#define BUF_SIZE (BUF_WIDTH*BUF_HEIGHT*3)
BYTE buffer[BUF_SIZE];
int screen_updated=TRUE;
int console_created=FALSE;
HANDLE hCrt;

#define KEYEVENTF_EXTENDEDKEY 0x0001
#define KEYEVENTF_KEYUP       0x0002
#define KEYEVENTF_UNICODE     0x0004
#define KEYEVENTF_SCANCODE    0x0008
#if defined(_WIN64)
 typedef unsigned __int64 ULONG_PTR;
#else
 typedef unsigned long ULONG_PTR;
#endif

#define GRIPPIE_SQUARE_SIZE 15
static HANDLE grippy;
static HWND grip_hwnd=0;
typedef struct tagMOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouseData;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} MOUSEINPUT, *PMOUSEINPUT;
typedef struct tagKEYBDINPUT {
    WORD wVk;
    WORD wScan;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} KEYBDINPUT, *PKEYBDINPUT;
typedef struct tagHARDWAREINPUT {
    DWORD uMsg;
    WORD wParamL;
    WORD wParamH;
} HARDWAREINPUT, *PHARDWAREINPUT;
typedef struct tagINPUT {
  DWORD type;
  union {
    MOUSEINPUT    mi;
    KEYBDINPUT    ki;
    HARDWAREINPUT hi;
  };
} INPUT, *PINPUT, FAR* LPINPUT;
UINT WINAPI SendInput(
  UINT nInputs,
  LPINPUT pInputs,
  int cbSize
);

void debug_printf(char *fmt,...)
{
	va_list ap;
	char s[255];
	va_start(ap,fmt);
	_vsnprintf(s,sizeof(s),fmt,ap);
	OutputDebugString(s);
}
void open_console()
{
	char Title[200]; 
	char ClassName[200]; 
	LPTSTR  lpClassName = ClassName; 
	HANDLE hConWnd; 
	FILE *hf; 
	
	if(console_created==TRUE)
	{

		GetConsoleTitle( Title, sizeof(Title));
		hConWnd = FindWindow( NULL, Title);
		GetClassName( (HWND)hConWnd,lpClassName,120);
		ShowWindow( (HWND)hConWnd,SW_SHOW);
		SetForegroundWindow((HWND)hConWnd);
		hConWnd=GetStdHandle(STD_INPUT_HANDLE);
		FlushConsoleInputBuffer(hConWnd);
		return;
	}
	AllocConsole(); 
	hCrt = (HANDLE)_open_osfhandle((long) GetStdHandle(STD_OUTPUT_HANDLE),_O_TEXT);

	fflush(stdin);
	hf = _fdopen( (int)hCrt, "w" ); 
	*stdout = *hf; 
	setvbuf( stdout, NULL, _IONBF, 0 );

	GetConsoleTitle( Title, sizeof(Title));
	hConWnd = FindWindow( NULL, Title);
	GetClassName( (HWND)hConWnd,lpClassName,120);
	ShowWindow( (HWND)hConWnd,SW_SHOW); 
	SetForegroundWindow((HWND)hConWnd);
	console_created=TRUE;
}
void move_console()
{
	char str[MAX_PATH];
	HWND hwnd;
	GetConsoleTitle(str,sizeof(str));
	hwnd=FindWindow(NULL,str);
	MoveWindow(hwnd,550,450,700,500,TRUE);
}
void set_pixel(BYTE *buf,int x,int y,BYTE R,BYTE G,BYTE B)
{
	int offset;
	if(x>=BUF_WIDTH)
		return;
	if(y>=BUF_HEIGHT)
		return;
	offset=x*3+y*BUF_WIDTH*3;
	if(offset<0)
		return;
	if((offset+2)>=BUF_SIZE)
		return;
	else{
		buf[offset]=R;
		buf[offset+1]=G;
		buf[offset+2]=B;
	}
}


void display_help(HWND hwnd)
{
	MessageBox(hwnd,"< > xdelta\r\n"
		"+ - bytestep\r\n"
		"[] zoom\r\n"
		"tab=stretch to dialog\r\n"
		"F5=open file\r\n"
		"1/2/right click=select RGB mode\r\n"
		"space=clear buffer\r\n"
		"Q/W=select next/prev file\r\n"
		"Z=reset xdelta,bytestep,zoom\r\n"
		,"HELP",MB_OK);
}
LRESULT CALLBACK request_value(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(message!=0x200&&message!=0x84&&message!=0x20&&message!=WM_ENTERIDLE)
	debug_printf("message=%08X wParam=%08X lParam=%08X tick=%u\n",message,wParam,lParam,GetTickCount());
	switch(message)
	{
	case WM_CLOSE:
	case WM_QUIT:
		DestroyWindow(hwnd);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)){

			DestroyWindow(hwnd);
			break;
		}
	}
	return 0;
}

LRESULT CALLBACK MainDlg(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc,hdcMem;
	PAINTSTRUCT ps;
	BITMAPINFO bmi;
	static RECT client_rect;
	char str[255];
	int i;

#ifdef _DEBUG
//	if(message!=0x200&&message!=0x84&&message!=0x20&&message!=WM_ENTERIDLE)
//		debug_printf("message=%08X wParam=%08X lParam=%08X\n",message,wParam,lParam);
#endif	
	switch(message)
	{
	case WM_INITDIALOG:
		create_grippy(hwnd);
		BringWindowToTop(hwnd);
		GetClientRect(hwnd,&client_rect);
		memset(buffer,0,sizeof(buffer));
		refresh_gamepads(GetDlgItem(hwnd,IDC_CONTROLLER));
		reposition_controls(hwnd);
		populate_buttons(hwnd,GetDlgItem(hwnd,IDC_CONTROLLER));
		load_controller_image(GetDlgItem(hwnd,IDC_CONTROLLER),buffer,sizeof(buffer));
#ifdef _DEBUG
		open_console();
		move_console();
//		test_lua();
//		compile_text(0,0);
#endif
		break;
	case WM_SIZE:
		client_rect.right=LOWORD(lParam);
		client_rect.bottom=HIWORD(lParam);
		grippy_move(hwnd);
		reposition_controls(hwnd);
		populate_buttons(hwnd,GetDlgItem(hwnd,IDC_CONTROLLER));
		InvalidateRect(hwnd,NULL,TRUE);
		break;
	
	case WM_COMMAND:
		print_msg(message,lParam,wParam);
		switch(LOWORD(wParam))
		{
		case WM_DESTROY:
		#ifndef _DEBUG
			if(MessageBox(hwnd,"Sure you want to quit?","QUIT",MB_OKCANCEL)!=IDOK)
				break;
		#endif
			PostQuitMessage(0);
			break;
		case IDC_CONTROLLER:
			if(HIWORD(wParam)==CBN_SELENDOK){
				memset(buffer,0,sizeof(buffer));
				populate_buttons(hwnd,GetDlgItem(hwnd,IDC_CONTROLLER));
				load_controller_image(GetDlgItem(hwnd,IDC_CONTROLLER),buffer,sizeof(buffer));
				InvalidateRect(hwnd,NULL,TRUE);
			}
			break;
		case IDC_REFRESH:
			refresh_gamepads(GetDlgItem(hwnd,IDC_CONTROLLER));
			break;
		case IDC_NEW_CONFIG:
			{
				INPUT i;
				i.type=1;
				i.ki.wScan=0;
				i.ki.dwFlags=0; //KEYEVENTF_SCANCODE;
				i.ki.dwExtraInfo=0;
				i.ki.time=0;
				i.ki.wVk=VK_LWIN;
				SendInput(1,&i,sizeof(i));
				i.ki.dwFlags=KEYEVENTF_KEYUP;
				SendInput(1,&i,sizeof(i));
			}
			Beep(1000,10);
			break;
		default:
			if(LOWORD(wParam)>=2000 && LOWORD(wParam)<2100){ //100 buttons should be enuf for anybody
				if(SendMessage(GetDlgItem(hwnd,IDC_QUICKRECORD),BM_GETCHECK,0,0)==BST_CHECKED)
					quick_record(hwnd,LOWORD(wParam)-2000,0);
				else
					handle_button(hwnd,0,LOWORD(wParam)-2000,0);
			}
		break;
		}
	case WM_PAINT:
//		TIME1
		hdc=BeginPaint(hwnd,&ps);
		memset(&bmi,0,sizeof(BITMAPINFO));
		bmi.bmiHeader.biBitCount=24;
		bmi.bmiHeader.biWidth=BUF_WIDTH;
		bmi.bmiHeader.biHeight=BUF_HEIGHT;
		bmi.bmiHeader.biPlanes=1;
		bmi.bmiHeader.biSize=40;
		StretchDIBits(hdc,0,78,client_rect.right,client_rect.bottom-78,0,0,BUF_WIDTH,BUF_HEIGHT,buffer,&bmi,DIB_RGB_COLORS,SRCCOPY);

//		SetDIBitsToDevice(hdc,0,30,BUF_WIDTH,BUF_HEIGHT,0,0,0,BUF_WIDTH,buffer,&bmi,DIB_RGB_COLORS);
		EndPaint(hwnd,&ps);
//		TIME2
		break;
	case WM_CLOSE:
	case WM_QUIT:
		#ifndef _DEBUG
			if(MessageBox(hwnd,"Sure you want to quit?","QUIT",MB_OKCANCEL)!=IDOK)
				break;
		#endif
		PostQuitMessage(0);
		break;
	case WM_MOUSEWHEEL:
		if(wParam&0x80000000)
			SendMessage(hwnd,WM_KEYDOWN,VK_NEXT,0);
		else
			SendMessage(hwnd,WM_KEYDOWN,VK_PRIOR,0);
		break;
	case WM_NCMOUSEMOVE:
		break;
	case WM_MOUSEFIRST:
		printf("x=%i y=%i\n",LOWORD(lParam)*640/(client_rect.right-client_rect.left),
			((HIWORD(lParam)-78)*(580)/(client_rect.bottom-78-client_rect.top)));
//		print_msg(message,lParam,wParam);

		break;
	case WM_KEYUP:
//		drawbuffer(file,offset,buffer,RGBmode,zoom,bytestep,xdelta);
		InvalidateRect(hwnd,NULL,TRUE);
		break;
	case WM_KEYDOWN:
#ifdef _DEBUG
//		debug_printf("message=%08X wParam=%08X lParam=%08X\n",message,wParam,lParam);
#endif
		switch(wParam)
		{

		}
//		drawbuffer(file,offset,buffer,RGBmode,zoom,bytestep,xdelta);
		InvalidateRect(hwnd,NULL,TRUE);   // force redraw
		break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	MSG msg;
	ghInstance=hInstance;
	
	hWindow=CreateDialog(ghInstance,MAKEINTRESOURCE(IDD_MAIN_DIALOG),NULL,MainDlg);
	if(!hWindow){
		MessageBox(NULL,"Could not create main dialog","ERROR",MB_ICONERROR | MB_OK);
		return 0;
	}

#ifdef _DEBUG
//	open_console();
#endif
	ShowWindow(hWindow,iCmdShow);
	UpdateWindow(hWindow);

	while(GetMessage(&msg,NULL,0,0))
	{
		HWND hdlg=get_edit_dlg();
		print_msg(msg.message,msg.lParam,msg.wParam);
		if(hdlg==0)
			hdlg=hWindow;
		if(get_record_mode())
			capture_input(msg.message,msg.wParam,msg.lParam);
		if(!IsDialogMessage(hdlg,&msg)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else{
		}
	}
	return msg.wParam;
}