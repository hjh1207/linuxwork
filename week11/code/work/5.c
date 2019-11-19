#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<stdlib.h>
#include<fcntl.h>
#define MAX 128
int main()
{ 
  int num;
  int fd;
  char buffer[MAX];
  struct stat buf;
  int pid;
  if((pid=fork())<0)
  {
     perror("failed fork!\n");
     return -1;
  }
  if(pid==0)
  {   
      printf("child is writing!\n");
      fd=open("test1.txt",O_RDWR|O_TRUNC|O_CREAT,0750);
      num=read(0,buffer,MAX);
      write(fd,buffer,num);
  }
  else 
  {
      printf("parent is writing!\n");
      fd=open("test1.txt",O_RDWR|O_TRUNC|O_CREAT,80750);
      num=read(0,buffer,MAX);
      write(fd,buffer,num);
  }
}
