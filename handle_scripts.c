#define _WIN32_WINNT 0x400
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <conio.h>

#include ".\lua\include\lua.h"
#include ".\lua\include\lualib.h"
#include ".\lua\include\lauxlib.h"

int key_ctrl=FALSE;
int key_shift=FALSE;
int extended_key=FALSE;
int getkey()
{
	int i=0;
	key_ctrl=FALSE;
	key_shift=FALSE;
	extended_key=FALSE;
	i=getch();
	if (GetKeyState(VK_SHIFT) < 0)
		key_shift=TRUE;
	if(GetKeyState(VK_CONTROL) < 0)
		key_ctrl=TRUE;
	if(i==0 || i==0xE0)
	{
		i=getch();
		extended_key=TRUE;
	}
	return i&0xFF;
}

int test_lua()
{
    int status, result, i;
    double sum;
    lua_State *L;

	L=luaL_newstate();
	luaL_openlibs(L);
    status = luaL_loadfile(L, ".\\scripts\\script.lua.txt");
    if (status) {
        printf("Couldn't load file: %s\n", lua_tostring(L, -1));
		getkey();
        exit(1);
    }

    result = lua_pcall(L, 0, LUA_MULTRET, 0);
	if (result) {
        printf("Failed to run script: %s\n", lua_tostring(L, -1));
		getkey();
        exit(1);
    }
	/*
	lua_newtable(L);
	for (i = 1; i <= 5; i++) {
        lua_pushnumber(L, i);
        lua_pushnumber(L, i+100);
        lua_rawset(L, -3);
    }
	lua_setglobal(L, "foo");
	*/
	lua_getglobal(L,"calc");
	lua_call(L,0,0);
//	result = lua_pcall(L, 0, LUA_MULTRET, 0);
	sum = lua_tonumber(L, -1);
//	printf("Script returned: %.0f\n", sum);
//    lua_pop(L, 1);  /* Take the returned value out of the stack */
    lua_close(L);   /* Cya, Lua */
	printf("press any key\n");
	getkey();
    exit(1);
	return 0;
}
#include <E:\DEV\MSVC_Projects\DX8_SDK\include\dinput.h>
BOOL CALLBACK enum_gamepads(LPCDIDEVICEINSTANCE lpddi, LPVOID pvRef)
{
	char str[255];
	int i=2;
	int result;
	_snprintf(str,sizeof(str),"%s",lpddi->tszInstanceName);
	do{
		result=SendMessage((HWND)pvRef,CB_FINDSTRINGEXACT,1,(LPARAM)str);
		if(result!=CB_ERR)
			_snprintf(str,sizeof(str),"%s (%i)",lpddi->tszInstanceName,i);
		else{
			SendMessage((HWND)pvRef, CB_ADDSTRING, 0, (LPARAM)str);
			result=SendMessage((HWND)pvRef,CB_FINDSTRINGEXACT,0,(LPARAM)str);
			if(result!=CB_ERR){
				SendMessage((HWND)pvRef, CB_SETITEMDATA, result, (LPARAM)lpddi->guidInstance.Data1);
				printf("found game pad %s GUID:%08X\n",str,lpddi->guidInstance.Data1);
			}
			break;
		}
		i++;
	}while(i<100);
   return DIENUM_CONTINUE;
}

int refresh_gamepads(HWND hwnd)
{
	int test=FALSE;
	int i;
	LPDIRECTINPUT8 dinp;
	SendMessage(hwnd,CB_RESETCONTENT,0,0);
	if(test){
		DIDEVICEINSTANCE di;
		sprintf(di.tszInstanceName,"adaptoid");
		for(i=0;i<4;i++){
			di.guidInstance.Data1=rand();
			enum_gamepads(&di,hwnd);
		}
		printf("press key\n");
//		getkey();
	}
	else
	if(DirectInput8Create(GetModuleHandle(0),DIRECTINPUT_VERSION,&IID_IDirectInput8,(void *)&dinp,0)==DI_OK){
			IDirectInput8_EnumDevices(dinp, DI8DEVCLASS_GAMECTRL, enum_gamepads,
                      hwnd, DIEDFL_ATTACHEDONLY);
	}
	SendMessage(hwnd,CB_SETCURSEL,0,0);
	return TRUE;
}