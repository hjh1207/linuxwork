#include"my.h"
int main()
{
int pid,s;
if((pid=fork())<0)
{
perror("fail to fork!\n");
return -1;
}
else if(pid==0)
{
printf("%d:child running now\n",getpid());
printf("%d:child exit now\n",getpid());
exit(120);
}
else
{
printf("%d:parent is waiting zombie now\n",getpid());
while((pid=wait(&s))!=-1)
{
if(WIFEXITED(s))
{printf("child %d is exiting normally exit code=%d \n",pid,WEXITSTATUS(s));}
else if(WIFSIGNALED(3))
{printf("child %d exit by signal no =%d\n",pid,WTERMSIG(s));}
else
{printf("not konw");}
}
}
exit(0);
}
