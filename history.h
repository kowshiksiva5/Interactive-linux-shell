void history(int num)
{
    //printf("History %d\n",num);
    int fd,args=0;
    char arr1[1000055],*tok;
    fd = open("history.txt",O_RDWR | O_CREAT |O_APPEND,0777); 
    read(fd,arr1,1000055);
   // printf("arr1 = %s\n",arr1);
    tok = strtok(arr1,"\t");
    for(;tok!=NULL;)
    {
        //printf("tok = %s\n",tok);
        args++;
        tok = strtok(NULL,"\t");
    }
    close(fd);
}

void write_cmd(char* given)
{
    //const char fnam[]="myshell_his.txt";
    int fd,args = 0;
    long long int len,len2,j,i;
    char *argv[100005],*tok,arr1[1000055],inse[1000055];
    fd = open("history.txt",O_RDWR | O_CREAT |O_APPEND,0777); 
    read(fd,arr1,1000055); 
    //const char de[]="\n";
    tok = strtok(arr1,"\t");
    //while(tok!=NULL)
    for(args = 0;tok !=NULL;args++)
    {
        argv[args]=tok;
        //printf("tok = %s\n",tok);
        tok = strtok(NULL,"\t");
    }
    if(args>=20)
    {
        args=19;
    }
    /*close(fd);
    fd = open(fnam,O_RDWR | O_CREAT |O_TRUNC,0777); 
    if(fd<0){
        perror("Error opening file");
        exit(1);
    }*/
    len=strlen(given);
    strcpy(inse,given);
    j = strlen(inse);
    i=0;
    while(i<args)
    {
        len = strlen(argv[i])+j;
        for(len2 = j;j<len;j++)
        {
            inse[j]=argv[i][j-len2];
        }
        i++;
    }
    inse[j]='\t';
    //printf("inse = %s",inse);
    write(fd,inse,strlen(inse));
    
    close(fd);



    

    
}



/*extern int history_count;
extern char  hist[20][1000];
int hist_print(char command_input[][500])
{
    int start,end,temp;
    if(strcmp(command_input[1],"")!=0)
    {
        if(command_input[1][1]!=0)
        {
            int t1,t2,t;
            t1 = command_input[1][0] - '0';
            t2 = command_input[1][1] - '0';
            t = t2*10+t1; 
            printf("t - %d t1  = %d t2 = %d\n",t,t1,t2);
            start = (history_count - t)%20;
        }
        else
        {
            int t = command_input[1][0] - '0';
            start = (history_count - t)%20;
        }
        
        for(int i = start ;i<history_count;i++)
        {
            printf("%s\n",hist[i]);
        }

    }
    else
    {
        for(int i=0;i<history_count;i++)
        {
            printf("%s\n",hist[i]);
        }
    }
    

}*/