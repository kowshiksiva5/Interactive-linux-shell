int fore_back(char given_input[][500],char given_path[],int count,int flag_background)
{
    int pid,temp,pid_2,flag_background_2 = 0,qq;
    char *temp_arr[1000];
    
    for(int i= 0;i<20;i++)
    {
        temp_arr[i] = given_input[i];
    }
    
    

    pid = fork();
    if(pid == 0)
    {
        int status;
        if(flag_background == 1)
        {
            pid_2 = fork();
            if(pid_2 == 0)
            {
                flag_background_2 = 1;
                temp = execvp(temp_arr[0],temp_arr);
                //printf("temp = %d\n",temp);
                if(temp < 0)
                {
                    perror("\nsorry,Error at command");
                    exit(1);
                    printf("\n");
                }

            }
            else if(pid_2 <0)
            {
                perror("\nSorry, Error in creating grand child");
                exit(1);
            }
            else
            {
                fprintf(stderr,"\npid = %d",pid_2);
                wait(&status);
                if(status != 0)
                {
                    fprintf(stderr,"\n%s with pid %d exited Abnormally",temp_arr[0],pid_2);
                }
                else
                {
                    fprintf(stderr,"\n%s with pid %d exited normally",temp_arr[0],pid_2);
                }
                exit(0);
            }
        }
        else
        {
            temp = execvp(temp_arr[0],temp_arr);
            if(temp < 0)
            {
                perror("Sorry ,Error in creating child");
                exit(1);
            }
        }
        
    }
    else if(pid < 0)
    {
        perror("sorry,Fail to create the child");
    }
    else
    {
        if(flag_background == 0)
        {
            wait(NULL);
        }
    }
    

}