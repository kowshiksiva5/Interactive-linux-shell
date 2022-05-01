char *command_storage[256];
char copyof_giveninput[10][300];
int  fun_pipe(char given_input[][500],int count,int flag_redirecting ,int flag_piping)
{
	pid_t pid;
	int fd1[2],fd2[2],command_count,t1 = 0,i,k1,k2,k3;
	command_count= flag_piping+1;
	int fd_redirecting=0,a3=-1;
	i=0;
    while(i<20)
	{
        if(strcmp(given_input[i],">")==0 || strcmp(given_input[i],">>")==0)
        {
		if(strcmp(given_input[i],">")==0)
		{
			fd_redirecting=open(given_input[i+1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
			break;
		}
		if(strcmp(given_input[i],">>")==0)
		{
			fd_redirecting=open(given_input[i+1], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
			break;
		}
        if(fd_redirecting < 0)
	    {
		perror(given_input[i+1]);
	    }
        }
		if(strcmp(given_input[i],"<")!=0)
        {
		strcpy(copyof_giveninput[t1++],given_input[i]);
        }
        i++;
	}
	
	int j = 0,k = 0,temp = 0;
	i = 0;
    while(strcmp(copyof_giveninput[j],"")!=0 && temp != 1)
	{
		k = 0;
		while(strcmp(copyof_giveninput[j],"|") != 0)
		{	
			command_storage[k]=copyof_giveninput[j];
			
			if (strcmp(copyof_giveninput[j+1],"")==0)
			{
			    k++;
				temp = 1;
				break;
			}
			j++;
            k++;
		}
		command_storage[k]=NULL;

		if (i % 2 == 1)
		{		
			pipe(fd1); 
		}
		else
		{		
			pipe(fd2); 
		}
		j++;
		//printf("fd0 = %d, fd1 = %d fd10 = %d fd11 = %d\n",fd1[0],fd1[1],fd2[0],fd2[1]);
		pid=fork();
		//printf("pid = %d\n",pid);
		
		if(pid==0)
		{
			int t1,t2;
			t1 = command_count -1;
			t2 = t1+1;
			if(fd_redirecting>0)
				dup2(fd_redirecting,1);
				
				if (i == 0)
				{
					dup2(fd2[1], 1);
				}
				else if (i == t1)
				{
					if (t2 % 2 == 1)
					{
						dup2(fd1[0],STDIN_FILENO);
					}
					else
					{
						dup2(fd2[0],STDIN_FILENO);
					} 
				}
				else	 
				{ 
					if (i % 2 == 1)
					{
						dup2(fd1[1],1);		
						dup2(fd2[0],STDIN_FILENO); 
					}
					else
					{ 
						dup2(fd2[1],1);
						dup2(fd1[0],STDIN_FILENO); 
					} 
				}
				if(execvp(command_storage[0],command_storage)==-1)
				{
					kill(getpid(),SIGTERM);
					return 0;
				}
				exit(0);			
		}
		else
		{
			wait(NULL);
		}
		if(pid==-1)
		{		
			t1 = command_count - 1;	
			if (i != t1)
			{
				if (i % 2 == 1)
				{
					k1 = fd1[1];
					close(fd1[1]);
				}
				else
				{
					k2 = fd2[1];
					close(fd2[1]); 
				}
			}
			else
			{
				continue;
			}
			printf("Child process could not be created\n");
			return 0;
		}
		if (i == 0)
		{
			close(fd2[1]);
		}
		else if (i == command_count - 1)
		{
			if (command_count % 2 == 1)	
			{
				close(fd1[0]);
			}				
			else
			{
				close(fd2[0]);
			}					
		}
		else
		{
			if (i % 2 == 1)
			{		
				k1 = fd1[1];			
				close(fd1[1]);
				k2 = fd2[0];
				close(fd2[0]);
			}
			else
			{					
				k1 = fd2[1];
				close(fd2[1]);
				k2 = fd1[0];
				close(fd1[0]);
			}
		}
        i++;
	}
	return 1;
}

