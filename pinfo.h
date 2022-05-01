char arr1[100],arr2[100],arr3[100];
int command_pinfo(char pinfo_input[][500],char given_pinfo_path[])
{
    //printf("1Entered pinfo\n");
    int pid,temp;
    char process_status[500];
    int memory;
    char process_name[500];
    FILE * p1;
    FILE * p2;
    for(int i = 0;i< 100 ;i++)
    {
        arr1[i] = 0;
    }
    temp = strcmp(pinfo_input[1],"");
    strcpy(arr1, "/proc/");
    
    if(temp!=0)
    {
        strcat(arr1,pinfo_input[1]);
        //printf("Entered pid\n");
    }
    else
    {
        strcat(arr1,"self");
        //printf("Entered self\n");

    }
    //printf("arr1 =%s\n",arr1);
    for(int i = 0;i< 100 ;i++)
    {
        arr2[i] = 0;
    }
    strcpy(arr2,arr1);//arr2 = /proc/(self or pid)
    strcat(arr2,"/stat");//arr2 = /proc/(self or pid)/stat
    //printf("arr2 =%s\n",arr2);

    p1 = fopen(arr2,"r");
    if(p1 == NULL)
    {
        printf("ERROR in opening stats file\n");
        return 0;
    }
    fscanf(p1, "%d", &pid);
    fscanf(p1, "%s" , process_status);
    fscanf(p1, "%s" , process_name);
    //fclose(p1);
    
    for(int i = 0;i< 100 ;i++)
    {
        arr2[i] = 0;
    }
    strcpy(arr2,arr1);
    strcat(arr2,"/statm");
    //printf("arr2 = %s\n",arr2);

    p2 = fopen(arr2,"r");
    if(p2 == NULL)
    {
        printf("ERROR in opening stats file ");
        return 0;
    }
    fscanf(p2, "%d", &memory);
    
    strcpy(arr2,arr1);
    strcat(arr2,"/exe");

    for(int i = 0;i< 100 ;i++)
    {
        //arr2[i] = 0;
        arr3[i] = 0;
    }

    printf("pid = %d\n",pid);
    printf("Process status = %s\n",process_name);
    printf("Memory = %d\n",memory);
    readlink(arr2,arr3,sizeof(arr3));
    //printf("arr3 = %s\n",arr3);
    removimghomedir_path(given_pinfo_path,arr3);
    fclose(p2);
    fclose(p1);
    return 1;
}