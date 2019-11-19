#include"my.h"
#define MAX 128
int  main()
{
int fd;
char buffer[MAX];
pid_t pid;
pid=fork();

if(pid<0)
{
perror("fork failed!\n");
return -1;
}
else if(pid==0){
printf("child input:");
fd=open("file.txt",O_RDWR|O_TRUNC|O_CREAT,0750); 
fgets(buffer,MAX,stdin);
write(fd,buffer,MAX);  
}
else
{
printf("parent input:");
fd=open("file.txt",O_RDWR|O_TRUNC|O_CREAT,0750); 
fgets(buffer,MAX,stdin);
write(fd,buffer,MAX); 
}
return 0;
}
