#include"my.h"
int main()
{
char *arg[]={"./test3","123","abc","hello","ncu","edu",NULL};
int ret;
printf("call3:pid=%d,ppid=%d\n",getpid(),getppid());
ret=execvp("test3",arg);
printf("after calling! ret=%d\n",ret);
return 0;
}
