#define _WIN32_WINNT 0x400
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define __INIFILE__ "joy2key.ini"
int get_ini_file(char *path)
{
	char start_path[MAX_PATH];
	memset(start_path,0,sizeof(start_path));
	GetCurrentDirectory(sizeof(start_path),start_path);
	if(strlen(start_path)>0 && start_path[strlen(start_path)-1]!='\\')
		strcat(start_path,"\\");
	strcpy(path,start_path);
	strcat(path,__INIFILE__);
	return 0;
}
int get_ini_path(char *path)
{
	char start_path[MAX_PATH];
	memset(start_path,0,sizeof(start_path));
	GetCurrentDirectory(sizeof(start_path),start_path);
	if(strlen(start_path)>0 && start_path[strlen(start_path)-1]!='\\')
		strcat(start_path,"\\");
	strcpy(path,start_path);
	return 0;
}
int write_newini_str(char *section,char *key,char *str)
{
	char fname[MAX_PATH];
	get_ini_path(fname);
	strcat(fname,__INIFILE__);
	WritePrivateProfileString(section,key,str,fname);
	return TRUE;
}
int write_newini_val(char *section,char *key,int *val)
{
	char fname[MAX_PATH];
	char str[80];
	get_ini_path(fname);
	strcat(fname,__INIFILE__);
	_snprintf(str,sizeof(str),"%u",val[0]);
	WritePrivateProfileString(section,key,str,fname);
	return TRUE;
}
int get_ini_str(char *section,char *key,char *str,int len)
{
	char fstr[255];
	char fname[MAX_PATH];
	DWORD err;
	get_ini_file(fname);

	memset(fstr,0,sizeof(fstr));
	err=GetPrivateProfileString(section,key,"",fstr,sizeof(fstr)-1,fname);
	if(err==0)
		return FALSE;
	strncpy(str,fstr,len);
	return TRUE;
}
int save_button_keys(int config,int button,BYTE *keylist,int len)
{
	int i,count=0;
	int first=TRUE;
	char key[40];
	char str[255];
	memset(key,0,sizeof(key));
	memset(str,0,sizeof(str));
	_snprintf(key,sizeof(key),"BUTTON%u",button);
	for(i=0;i<len;i++){
		if(keylist[i]!=0){
			if(count!=0)
				strcat(str,",");
			_snprintf(str+strlen(str),sizeof(str)-strlen(str),"%u",i);
			count++;
		}
	}
	if(count>0){
		char cfgstr[40];
		sprintf(cfgstr,"CONFIG%u",config);
		write_newini_str(cfgstr,key,str);
	}
	return 0;
}