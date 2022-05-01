char current_path[255];
char temp_path[255];

int command1(char command_input[][500],char given_path[],int count)
{
	//printf("input = %s\n",command_input[0]);
	//printf("entered\n");
	char *exe[20];
	for(int i=0;i<20;i++)
	{
		exe[i] = command_input[i];
	}
	int i,j,k;
	i=0;
	while(i<20)
	{
		if(strcmp(command_input[i],"&")==0 )
		{
			//printf("ENtered return\n");
			return 0;
		}
		else if(strcmp(command_input[i],">")==0)
		{
			return 0;
		}
		else if(strcmp(command_input[i],">>")==0)
		{
			return 0;
		}
		else if (strcmp(command_input[i],"<")==0)
		{
			return 0;
		}
		else if(strcmp(command_input[i],"|")==0)
		{
			return 0;
		}
		else
		{
			i++;
		}
	}
	if(strcmp(command_input[0],"pwd") == 0)
	{
		//printf("  the pwd\n");
		for(int t1 = 0;t1 < 255;t1++)
		{
			current_path[t1] = 0;
		}
		getcwd(current_path,255);
		printf("%s\n",current_path);
		return 1;
	}
	else if(strcmp("echo",command_input[0])==0)
	{
		for(int tt = 1;tt <count;tt++)
		{
			printf("%s ",command_input[tt]);
		}
		printf("\n");
		return 1;

	}
	else if(strcmp(command_input[0],"cd") == 0)
	{
		//printf(" the cd\n");
		char s[255];
		//strcpy(command_input[count],"");
		//printf("%s\n",getcwd(s,255));
		if(strcmp(command_input[1],".")==0)
		{
			return 1;
		}
		else if(strcmp(command_input[1],"..")==0)
		{
			chdir("..");
			//printf("%s\n",getcwd(s,255));

		}
		else if(strcmp(command_input[1],"~")==0)
		{
			chdir(given_path);
			//printf("%s\n",getcwd(s,255));

		}
		else if(strcmp(command_input[1],"~/")==0)
		{
			chdir(given_path);
			//printf("%s\n",getcwd(s,255));

		}
		else 
		{
			//printf(" last in cd\n");
			for(int t1 = 0;t1 < 255;t1++)
			{
				current_path[t1] = 0;
			}
			getcwd(current_path,255);
			if(command_input[1][0] == '~' && command_input[1][1] == '/')
			{
				for(int t1 = 0;t1 < 255;t1++)
				{
					current_path[t1] = 0;
				}
				getcwd(current_path,255);
				for(int t1 = 0;t1 < 255;t1++)
				{
					temp_path[t1] = 0;
				}
				for(j=0,k=2;j<strlen(command_input[1]);j++,k++)
				{
					temp_path[j] = command_input[1][k];
				}
				if(chdir(temp_path)!=0 )
				{
					printf("Sorry,No such file or Diretory exists\n");
				}
			}
			else
			{
				//printf("command_input[1] = %scommand_input[0] = %s\n",command_input[1],command_input[0]);
				int ty = chdir(command_input[1]);
				if(ty !=0)
				{
					printf("Sorry,No such file or Diretory exists\n");
				}
				//printf("%s\n",getcwd(s,255));
			}
		}
		return 1;
	}

	else if (strcmp(command_input[0],"ls")==0)
	{
		int flag =0,temp = 0;
		//printf("%s %s %s %s \n",command_input[0],command_input[1],command_input[2],command_input[3]);
		if(strcmp(command_input[1],"-l")==0)
		{
			if(strcmp(command_input[2],"-a")==0)
			{
				flag = 3;
				fun_la(command_input,given_path,flag,temp);
			}
			else
			{
				flag = 2;
				temp = 1;
				fun_la(command_input,given_path,flag,temp);
			}

		}
		else if(strcmp(command_input[1],"-a")==0)
		{

			if(strcmp(command_input[2],"-l")==0)
			{
				flag = 3;
				fun_la(command_input,given_path,flag,temp);
			}
			else if(command_input[2][0]==0)
			{
				print_hidden(".");
			}
			else
			{
				print_hidden(command_input[2]);
			}
		}
		else if(strcmp(command_input[1],"-la")==0 || strcmp(command_input[1],"-al")==0)
		{
			flag = 2;
			fun_la(command_input,given_path,flag,temp);
		}
		else
		{
			if(strcmp(command_input[1],"")!=0)
			{
				print_nonhidden(command_input[1]);
			}
			else
			{
				print_nonhidden(".");
			}
		}
		return 1;
	}
	else if(strcmp(command_input[0],"pinfo")==0)
	{
		return  command_pinfo(command_input,given_path);
	}
	else if(strcmp(command_input[0],"setenv")==0)
	{
		int t1,t2;
		t1 = strcmp(command_input[3],"");
		t2 = strcmp(command_input[1],"");
		if(t1!=0||t2==0)
			{
				printf("error");
				return 0;
			}
		if(setenv(command_input[1],command_input[2],1) != 0)
		{
			perror("shell");
			return 0;
		}
		return 1;
	}
	else if(strcmp(command_input[0],"unsetenv")==0)
	{
		int t1,t2;
		t1 = strcmp(command_input[3],"");
		t2 = strcmp(command_input[1],"");
		if(t1!=0||t2==0)
			{
				printf("error");
				return 0;
			}
		if(unsetenv(command_input[1]) != 0)
		{
			perror("shell");
			return 0;
		}
		return 1;
	}
	return 0;
}
