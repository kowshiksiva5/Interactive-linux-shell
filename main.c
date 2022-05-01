#include "prompt.h"
#include "headers.h"
#include "displayinguserfriendly.h"
#include "pinfo.h"
#include "ls.h"
//#include "history.h"
#include "cep.h"
//#include "fore_background.h"
#include "main_signal.h"
#include "redirecting.h"
#include "pipe.h"
#include "jobs.h"
#include "othercommands.h"
#include "parsing.h"
int history_count ;
char hist[20][1000],temp_path[255];
int print_prompt(char given_path[],char executablepath[])
{
	int i,j,k,count = 0;
	for(int y = 0; y<255;y++)
	{
		temp_path[y] = 0;
	}
	temp_path[0]='~';
	temp_path[1]='/';
	for(i = 0;i<strlen(given_path)&&given_path[i]==executablepath[i];i++)
	{
		count++;
	}

	for(i = count+1,k = 2;i<strlen(executablepath);i++,k++)
		temp_path[k]=executablepath[i];


	if(count==strlen(given_path))
		return 0;
	else
		return 1;

}
void checkusername(char *username)
{
	if(username == NULL)
	{
		perror("get user name");
		//exit(1);
	}
}
void checkhname(char *hname)
{
	if(hname == NULL)
	{
		perror("get host name");
		//exit(1);
	}
}
struct utsname uname_pointer;

int main()
{
	char input_line[2555], path[255],cur_path[255];
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP,fun_signal);
	for(int tt = 0;tt<255;tt++)
	{
		path[tt] = 0;
	}
	signal(SIGQUIT, SIG_IGN);
	char *in;
	char arr[5000];
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	getcwd(path,255);
	for(int i = 0; i < 20 ; i++ )
	{
		for(int j = 0; j<1000 ; j++)
		{
			hist[i][j] = 0;

		}
	}
	history_count = 0;
	while (1)
	{
		if(signal(SIGTSTP,fun_signal)!=SIG_ERR)
		{
			strcpy(input_line,"");
		}
		else
		{
			fun_error(1);
		}
		if(signal(SIGINT,fun_signal)!=SIG_ERR)
		{
			strcpy(input_line,"");
		}
		else
		{
			fun_error(2);
		}
		for(int tt = 0;tt<255;tt++)
		{
			cur_path[tt] = 0;
		}
		getcwd(cur_path,255);
		uname(&uname_pointer); 
		checkhname(getenv("USER"));
		checkusername(uname_pointer.nodename);
		if(print_prompt(path,cur_path)==0)
		{
            fun_print(input_line,uname_pointer.nodename,temp_path);
		}
		else
		{
			fun_print(input_line,uname_pointer.nodename,cur_path);
		}
		in = readline(input_line);
		strcpy(arr,in);
		if(strcmp(arr,"quit")==0)
		{
			_exit(0);
		}
		fflush(stdout);
		fflush(stdin);
		breakinput(arr,path);
	}
}
