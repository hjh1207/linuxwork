#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include<sys/wait.h>

int main(int argc,char * argv[])
{
        int stat;
        int fd;
        int childpid;
        int i;
        for(i=0 ;i<1; i++){
                if(childpid = fork())
                        break;
        }

        if(childpid == -1){
                perror("failed to fork\n");
                return 1;
        }

        fd = open("tmp.dat",O_WRONLY|O_CREAT|O_APPEND,0666);

        if(fd < 0){
                perror("failed to open\n");
                return 1;
        }
        close(fd);
        return 0;
}

