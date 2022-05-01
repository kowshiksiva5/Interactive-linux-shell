char temp_arr[100][20][100];
char *arr[500];
int pid,copy_pid,arr_count = 0,check[100] = {0};
void fun_print1()
{
    int y,i;
    char farr[100];
    pid_t pid;
    for(int tt= 0;tt< 100;tt++)
    {
        farr[tt] = 0;
    }
    int t11 = -1;
    pid = waitpid(t11,&y,WNOHANG);
    int t2 = pid,t1;
    sprintf(farr,"%d",t2);
    i = 0;
    while(i < arr_count)
    {
        t1 = strcmp(temp_arr[i][0],farr);
        if(t1 == 0)
        {
            t2 = 2;
            int t3 = 0;
            if(temp_arr[i][t2][t3] == '1')
            {
                if(WIFEXITED(y))
                {
                    fflush(stdout);
                    check[i] = 1;
                    fprintf(stdout,"%s Exited normally with PID : %d\n",temp_arr[i][1],pid);
                    fflush(stdout);
                }
                else
                {
                    check[i] = 1;
                    fprintf(stdout,"%s Exited abnormally with PID : %d\n",temp_arr[i][1],pid);
                    fflush(stdout);
                }
            }

        }
        i++;
    }

}
void fun_signal(int temp_signal)
{
    int temp;
    temp = temp_signal;
	if(temp == SIGINT)
	{
		deduce(temp);
		signal(SIGINT, fun_signal);     
	}
}
void fun_signal1(int temp_signal)
{
    int temp;
    char farr[100];
    temp = temp_signal;
    if(temp = SIGTSTP)
    {
        int t1,t2,t3;
        t1 = copy_pid;
        setpgid(t1,t1);
        if(t1 !=-1)
        {
            t2 = t1;
            kill(t2,SIGTSTP);
            sprintf(farr,"%d",t2);
            int tt = 0;
            while(tt< arr_count)
            {
                if(strcmp(temp_arr[tt][0],farr)==0)
                {
                    int n1,n2;
                    n1 = 2;
                    n2 = 0;
                    temp_arr[tt][n1][n2] = '1';
                    check[tt] = 0;
                }
                tt++;
            }
            signal(SIGCHLD,fun_print1);
        }        
        t2 = copy_pid;
        signal(SIGTSTP,SIG_IGN);
        t1 = copy_pid;
        signal(SIGTSTP, fun_signal);
    }
}
int fun_jobs(char given_input[100],int t)
{
    printf("Backgroundjobs\n");
    int i = 0,cc = 0;
    while(i< arr_count)
    {
        int t1,t2,t3;
        t1 = strcmp(temp_arr[i][2],"1");
        if(t1 == 0)
        {
            t2 = check[i];
            if(t2 == 1)
            {
                t3 = cc +1;
                printf("%d Stopped %s ",t3,temp_arr[i][1]);
                int k = 3;
                while(strcmp(temp_arr[i][k],"")!=0 && strcmp(temp_arr[i][k],"&")!=0)
                {
                    int t4,t5;
                    t4 = i;
                    t5 = k;
                    printf("%s ",temp_arr[t4][t5]);
                }
                printf("[%s]\n",temp_arr[i][0]);
            }
            else
            {
                  printf("%d Running %s ",t3,temp_arr[i][1]);
                int k = 3;
                while(strcmp(temp_arr[i][k],"")!=0 && strcmp(temp_arr[i][k],"&")!=0)
                {
                    int t4,t5;
                    t4 = i;
                    t5 = k;
                    printf("%s ",temp_arr[t4][t5]);
                }
                printf("[%s]\n",temp_arr[i][0]);
            }
            
        }

    }
    cc = 0;
    printf("Foreground Jobs Exited till now\n");
    while(i< arr_count)
    {
        int t1,t2,t3;
        t1 = strcmp(temp_arr[i][2],"0");
        if(t1 == 0)
        {
            t2 = i;
            t3 = 1;
                printf("%d Exited process %s ",++cc,temp_arr[t2][t3]);
                int k = 3;
                while(strcmp(temp_arr[i][k],"")!=0 && strcmp(temp_arr[i][k],"&")!=0)
                {
                    int t4,t5;
                    t4 = i;
                    t5 = k;
                    printf("%s ",temp_arr[t4][t5]);
                }
                printf("[%s]\n",temp_arr[i][0]);
        }
    }
    return 1;
}
int fun_fg(char given_input[100],int t)
{


}
int fun_bg(char given_input[100],int t)
{
    int t8,t2,t3;

}
int fun_kjobs(char given_input[100],char given_input1[100],int t,int t1)
{
    int t8,t2;
    t8 = 0;
    t8 = atoi(given_input);
    t2 = 0;
    t2 = atof(given_input1);
    if(temp_arr[t1-1][2][0]=='1' && check[t1-1]==0)
    {
        int t3,t4;
        t3 = t8-1;
        t4 = 0;
        kill(atoi(temp_arr[t3][t4]),t2);
        return 1;
    }
    printf("job is not running\n");
    return 0;
}
int fun_overkill(char given_input[100],int t)
{
    int i= 0;
    while(i < arr_count)
    {
        int t8,t2,t3;
        t8 = i;
        t2 = 2;
        t3 = 0;
        if(temp_arr[t8][t2][t3]=='1'&&check[i] == 0)
        {
            int t4,t5,t6;
            t4 = i;
            t5 = 0;
            t6 = 9;
            kill(atoi(temp_arr[t4][t5]),t6);
        }
    }
    return 0;
}
int command2(char command_input[][500],char given_path[],int count)
{
    //printf("Entered command2\n");
    int flag_redirect=0,flag_piping=0,i,flag_background = 0;
    int t1,t2,t3,t4,t5,t6,t7,t8;
    pid_t pid,pid1,pid2,pid3;
    t1 = strcmp(command_input[0],"jobs");
    t2 = strcmp(command_input[0],"fd");
    t3 = strcmp(command_input[0],"bg");
    t4 = strcmp(command_input[0],"kjob");
    t5 = strcmp(command_input[0],"overkill");
    t6 = strcmp(command_input[0],"quit");
    t7 = strcmp(command_input[1],"");
    t8 = strcmp(command_input[2],"");
    if(t1 == 0)
    {
       return fun_jobs(command_input[0],t1);
    }
    else if (t2 == 0)
    {
        return fun_fg(command_input[1],t2);
    }
    else if(t3 == 0)
    {
        return fun_bg(command_input[1],t3);
    }
    else if(t4 == 0)
    {
        if(t7 != 0 && t8 != 0 )
        {
            return fun_kjobs(command_input[1],command_input[2],t7,t8);
        }
    }
    else if(t5 == 0)
    {
        return fun_overkill(command_input[0],t5);
    }
    else if(t6 == 0)
    {
        exit(0);
    }
    for(i = 0; strcmp(command_input[i],"")!=0;i++)
    {
        //printf("command_input[%d] = %s\n",i,command_input[i]);
        if(strcmp(command_input[i],"|")==0)
        {
            flag_piping++;
        }
        else if(strcmp(command_input[i],"&")==0)
        {
            flag_background = 1;
            //fore_back(command_input,given_path,count,flag_background);
        }
        else if(strcmp(command_input[i],">")==0)
        {
            flag_redirect++;
        }
        else if(strcmp(command_input[i],"<")==0)
        {
            flag_redirect++;
        }
        else if(strcmp(command_input[i],">>")==0)
        {
            flag_redirect++;
        }
    }
    if(flag_redirect&&flag_piping==0)
    {
        //printf("calling redirection\n");
        fun_redirect(command_input,i,flag_redirect,flag_piping);
    }
    else if(flag_piping||flag_redirect)
    {
       // printf("calling piping\n");
        fun_pipe(command_input,i,flag_redirect,flag_piping);
    }
    pid = fork();
    copy_pid = pid;
    int temp,flag_state;
    temp = pid;
    i = 0;
    while(i<500)
    {
        arr[i] = NULL;
        i++;
    }
    i = 0;
    while(i<500 && strcmp(command_input[i],"")!=0)
    {
        arr[i] = command_input[i];
        i++;
    }
   

    if(pid = 0)
    {
        int tem;
        tem = flag_background;
        if(tem == 1)
        {
            setpgid(0,0);
        }
        int t1;
        t1 = execvp(arr[0],arr);
        if(t1 == -1)
        {
            return fun_Error(1);
        }
        exit(0);
    }
    else if(pid < 0)
    {
        return fun_Error(1);

    }
    else
    {
        int t1,t2,t3;
        t1 = arr_count;
        t2 = pid;
        sprintf(temp_arr[t1][0],"%d",t2);
        t1 = arr_count;
        strcpy(temp_arr[t1][1],arr[0]);
        t1 = arr_count;
        t3 = flag_background;
        sprintf(temp_arr[t1][2],"%d",t3);
        i = 1;
        while(arr[i]!= NULL)
        {
            t1 = arr_count;
            strcpy(temp_arr[t1][i+2],command_input[i]);
            i++;
        }
        arr_count++;
    }
    int y;
    y = flag_background;
    if(y != 0)
    {
        signal(SIGTSTP,fun_signal1);
    }
    else
    {
        signal(SIGTSTP,fun_signal1);
        int t1,t2,t3;
        t1 = pid;
        pid1 = waitpid(pid,&flag_state, WUNTRACED);
    }
    return 1;
}

