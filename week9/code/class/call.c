#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
printf("call:pid=%d.ppid=%d\n",getpid(),getppid());
system("/home/rlk/linuxprogram/week9/code/test3");
printf("after calling\n");
}
