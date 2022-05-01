#include "prompt.h"
#include "headers.h"


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
void prompt(char arr[]) 
{
   // printf("reached propmt\n");
   struct utsname uname_pointer;
   uname(&uname_pointer);
   checkhname(getenv("USER"));
   checkusername(uname_pointer.nodename);
   printf("%s@%s:%s$",getenv("USER"),uname_pointer.nodename,arr);
   //printf("\ninput arr = %s\n",arr);
}


