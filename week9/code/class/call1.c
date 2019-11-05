#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
char *args[]={"/home/rlk/linuxprogram/week9/code/test3",NULL};
printf("call:pid=%d.ppid=%d\n",getpid(),getppid());
execve("/home/rlk/linuxprogram/week9/code/test3",args,NULL);
printf("after calling\n");
}
