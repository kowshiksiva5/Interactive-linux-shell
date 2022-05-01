int fun_error(int t)
{
    if(t = 1)
    {
        perror("SIGTSTP not found");
    }
    else if(t = 2)
    {
        perror("SIGINT not found");
    }
}
int fun_print(char temp1[],char *temp2,char temp[])
{
    sprintf(temp1,"%s@%s:%s$",getenv("USER"),temp2,temp);
}
int deduce(int temp)
{
    signal(SIGINT,SIG_IGN);
}
int fun_Error(int t)
{
    perror("Error");
    return 0;
}