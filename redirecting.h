void error(int t)
{
    if(t == 1)
    {
        perror("couldn't open input file");
    }
    else if(t == 2)
    {
        perror("couldn't open output file");
    }
}
int fun_redirect(char given_input[][500],int count,int flag_redirect,int flag_piping)
{
    //printf("Entered redirection\n");
    int flag_in = 0,flag_out = 0,flag_append = 0,fd,pid;
    char *arr[500],input[300],output[300],append[300];
    int i = 0;
    while(i < 20)
    {
        arr[i] = NULL;
        i++;
    }
    struct stat temp;
    i = 0;
    while(i<20)
    {
        arr[i] = given_input[i];
        //printf("arr[%d] = %s\n",i,arr[i]);
        i++;
    }
    pid = fork();
    //printf("pid = %d\n",pid);

    if(pid != 0)
    {
        wait(NULL);
    }
    else
    {
        for(int i=0;i<count && given_input[i] != NULL ;i++)
        {
            int t1,t2,t3;
            t1 = strcmp(given_input[i],">");
            t2 = strcmp(given_input[i],"<");
            t3 = strcmp(given_input[i],">>");
            if(t1 == 0 || t2 == 0 || t3 == 0)
            {
                arr[i] = NULL;
                if(t1 == 0)
                {
                    strcpy(output,arr[i+1]);
                    flag_out = 1;
                }
                else if(t2 == 0)
                {
                    strcpy(input,arr[i+1]);
                    flag_in = 1;
                }
                else if(t3 == 0)
                {
                    strcpy(append,arr[i+1]);
                    flag_append == 1;
                }
            }
        }
        //printf("flag_in = %d flag_out = %d flag_ append = %d\n",flag_in,flag_out,flag_append);
        if(flag_in != 0)
		{
			fd = open(input,O_RDONLY,0);
            if(fd < 0)
            {
                error(1);
            }
            dup2(fd,0);
			close(fd);
		}	
		else if(flag_out != 0)
		{
			if (stat(output,&temp)==0)
            {
				fd = open(output, O_WRONLY);
                if(fd < 0)
                {
                    error(2);
                }	
				dup2(fd,1);
				close(fd);
			}
			else
			{
				fd = creat(output,0644);
                if(fd < 0)
                {
                    error(2);
                }
				dup2(fd,1);
				close(fd);
			}
		}
    	else if (flag_append != 0)
		{
			if (stat(append,&temp)==0)
			{
				fd = open(append,O_APPEND | O_WRONLY);
				error(2);
				dup2(fd,1);
				close(fd);
			}
			else
			{
				fd = creat(append,0644);
				if (fd<0)
				{
                    error(2);
                }
				dup2(fd,1);
				close(fd);
			}
		}
        if(execvp(arr[0],arr) == -1)
        {
            printf("%s: command doesn't exist\n",given_input[0]);
        }
    }
    

}