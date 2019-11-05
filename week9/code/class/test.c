#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
int i;
printf("test:pid=%d,ppid=%d\n",getpid(),getppid());
for(i=0;i<argc;i++) 
printf("%s\n",argv[i]);
}
