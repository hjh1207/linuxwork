#include<unistd.h>
#include<iostream>
#include<cstring>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;
int main()
{
  int fd;
  FILE *file;
  char *s="hello,world\n";
  if((fd=open("test.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
  {
	cout<<"error open file"<<endl;
	return -1;
  }
  if((file=fopen("test2.txt","w"))==NULL)
  {
	cout<<"error open file"<<endl;
	return -1;
  }
  cout<<"file has been opened"<<endl;
  sleep(15);
  if(write(fd,s,strlen(s))<strlen(s))
  {
	cout<<"write error"<<endl;
	return -1;
  }
  if(fwrite(s,sizeof(char),strlen(s),file)<strlen(s))
  {
	cout<<"write error in 2"<<endl;
	return -1;
  }
  cout<<"after write"<<endl;
  sleep(15);
  cout<<"after sleep"<<endl;
  close(fd);
  return 0;
}
