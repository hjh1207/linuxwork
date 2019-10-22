#include<stdio.h>
int main(int argc,char *argv[])
{
  printf("hello");
  setvbuf(stdout,NULL,_IONBF,0);
  while(1);
}
