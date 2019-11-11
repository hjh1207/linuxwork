#include<setjmp.h>
#include"my.h"
static jmp_buf g_stack_env;
static void fun1(void);
static void fun2(void);
int main(void)
{
if(0==setjmp(g_stack_env)){
printf("normal flow\n");
fun1();
}else{
printf("long jump flow\n");
}
return 0;
}
static void fun1(void)
{
printf("enter func1\n");
fun2();
}
static void fun2(void)
{
printf("enter func2\n");
longjmp(g_stack_env,1);
printf("leave func2\n");
}
