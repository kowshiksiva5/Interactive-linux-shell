
void print_hidden(char given[])
{
	DIR *p1;
	struct dirent *D;
	p1 = opendir(given);
	if (p1==NULL)
	{
		printf("No such file or directory");
	}
	else
	{
		while(( D = readdir(p1)) != NULL)
		{
			printf("%s ", D->d_name);
		}
		closedir(p1);
	}
	printf("\n");


	return ;
}
void print_nonhidden(char given[])
{
	DIR *p1;
	struct dirent *D;
	p1 = opendir(given);
	if (p1 == NULL)
	{
		printf("No such file or directory\n");
	}
	else
	{
		while(( D = readdir(p1)) != NULL)
		{
			if(D->d_name[0]!='.')
				printf("%s ", D->d_name);
		}
		closedir(p1);
	}   
	printf("\n");
}

void  lsfileminusl(char buffer[])
{
	DIR *dir;
	char mod[200];
	char write_rwx[200];
	int year;
	struct stat kk_stat;
    struct passwd *user;
    struct group *Gp;
    struct tm *St_time;
	
	stat(buffer,&kk_stat);
	user = getpwuid(kk_stat.st_uid);
	Gp = getgrgid(kk_stat.st_gid);
	for(int i=0;i<200;i++)
	{
		write_rwx[i] = 0;
	}
	if(S_ISDIR(kk_stat.st_mode))
	{
		if(write_rwx[0]==0)
		write_rwx[0]= 'd' ;
	}
	else
	{
		if(write_rwx[0]==0)
		write_rwx[0] ='-';
	}

	if((kk_stat.st_mode & S_IRUSR ))
	{
		if(write_rwx[1]==0)
		write_rwx[1]= 'r' ;
	}
	else
	{
		if(write_rwx[1]==0)
		write_rwx[1] ='-';
	}
		

	if( (kk_stat.st_mode & S_IWUSR))
	{
		if(write_rwx[2]==0)
		write_rwx[2] ='w';
	}
	else
	{
		if(write_rwx[2]==0)
		write_rwx[2] ='-';
	}

	if((kk_stat.st_mode & S_IXUSR)) 
	{
		if(write_rwx[3]==0)
		write_rwx[3]= 'x' ;
	}
	else
	{
		if(write_rwx[3]==0)
		write_rwx[3] ='-';
	}
		
	if((kk_stat.st_mode & S_IRGRP) )
	{
		if(write_rwx[4]==0)
		write_rwx[4]= 'r';
	}
	else
	{
		if(write_rwx[4]==0)
		write_rwx[4] ='-';
	}
		
	if( (kk_stat.st_mode & S_IWGRP))
	{
		if(write_rwx[5]==0)
		write_rwx[5]= 'w' ;
	}
	else
	{
		if(write_rwx[5]==0)
		write_rwx[5] ='-'; 
	}
		
	if(kk_stat.st_mode & S_IXGRP)
	{
		if(write_rwx[6]==0)
		write_rwx[6]= 'x' ;
	}
	else
	{
		if(write_rwx[6]==0)
		write_rwx[6] ='-';
	}
		
	if( (kk_stat.st_mode & S_IROTH))
	{
		if(write_rwx[7]==0)
		write_rwx[7]= 'r' ;
	}
	else
	{
		if(write_rwx[7]==0)
		write_rwx[7] ='-'; 
	}
		
	if( (kk_stat.st_mode & S_IWOTH))
	{
		if(write_rwx[8]==0)
		write_rwx[8]= 'w' ;
	}
	else
	{
		if(write_rwx[8]==0)
		write_rwx[8] ='-';
	}
		
	if( (kk_stat.st_mode & S_IXOTH) ==0 )
	{
		if(write_rwx[9]==0)
		write_rwx[9] ='-'; 
	}
	else
	{
		if(write_rwx[9]==0)
		write_rwx[9]= 'x' ;
	}
	printf("%s\t%d\t%s\t%s\t%lld\t",write_rwx,(int)kk_stat.st_nlink,user->pw_name,Gp->gr_name,(long long)kk_stat.st_size);
	time_t now;
	time(&now);
	year = localtime(&now)->tm_year;
	St_time = localtime(&kk_stat.st_ctime);

	if(St_time->tm_year != year)
	{
		strftime(mod,13,"%b %e %year",St_time);
	}
	else
	{
		strftime(mod,13,"%b %e %R",St_time);
	}

	printf("%s\t%s\n",mod,buffer);	 	
	
	//printf("%s\n",buffer);
}

int fun_la(char command_input[][500],char given_path[],int flag,int temp)
{
	//printf("reached");
	DIR *p1;
	struct dirent *D;
	char temp_path[255];
	int t1;
	for(int i=0;i<255;i++)
	{
		temp_path[i] = 0;
	}
	getcwd(temp_path,255);
	if(flag == 2)
	{
		t1 = 2;
	}
	if(flag == 3)
	{
		t1 = 3;
	}     
	if(strcmp(command_input[t1],"")==0)          
		p1 = opendir(temp_path);
	else
		p1 = opendir(command_input[2]);

	if (p1)
	{
		for(;(D = readdir(p1)) != NULL ;)
		{
			if(temp==0)
			{
				lsfileminusl(D->d_name);
			}
			else
			{
				if(D->d_name[0]!='.')
				{
					lsfileminusl(D->d_name);
				}
			}
		}
	}
	else
	{
		printf("No such file or directory\n");
		return 0;
	}  

}
