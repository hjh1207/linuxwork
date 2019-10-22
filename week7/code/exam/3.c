#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<string.h>
#include<stdlib.h>
#define MAX 128
int chmd();

int chmd (char *filename)
{
  int c;
  mode_t mode=S_IWUSR;
  printf(" 0. 0700\n 1. 0400\n 2. 0200 \n 3. 0100\n "); 
  printf("Please input your choice(0-3):");
  scanf("%d",&c);
  switch(c)
  {
	case 0: chmod(filename,S_IRWXU);break;
	case 1: chmod(filename,S_IRUSR);break;
	case 2: chmod(filename,S_IWUSR);break;
	case 3: chmod(filename,S_IXUSR);break;
	default:printf("You have a wrong choice!\n");	
  }
  return(0);
}

void main()
{
  int fd;
  int num; 
  int choice;
  char *filename;
  char buffer[MAX];
  struct stat buf;
  char* path="/bin/ls";
  char* argv[4]={"ls","-l",filename,NULL};
  while(1)
  {
  printf("********************************\n");
  printf("0. 退出\n");
  printf("1. 创建新文件\n");
  printf("2. 写文件\n");
  printf("3. 读文件\n");
  printf("4. 修改文件权限\n");
  printf("5. 查看当前文件的权限\n");	
  printf("********************************\n");
  printf("Please input your choice(0-5):");
  scanf("%d",&choice); 
	switch(choice)
	{
		case 0:close(fd); 
		exit(0); 
		case 1:
		printf("please input filename:");
		scanf("%s", filename);
		strcat(filename, ".txt");
		fd=open(filename,O_RDWR|O_TRUNC|O_CREAT,0750); 
		if(fd==-1)
		printf("File Create Failed!\n");
		else
		printf("fd = %d\n",fd); 
		break;
		case 2: 
		num=read(0,buffer,MAX); 
		write(fd,buffer,num); 
		break;
		case 3:
		read(fd,buffer,MAX);
		write(1,buffer,num);
		break;
		case 4:
		chmd (filename);
		printf("Change mode success!\n");
		break;
		case 5:
		execv(path,argv);	
		break; 
		default:
		printf("You have a wrong choice!\n");
	}
  } 
}
