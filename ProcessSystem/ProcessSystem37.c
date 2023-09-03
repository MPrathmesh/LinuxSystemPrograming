//Inter Process Communication(IPC)
//Using named Pipe
//Server For Named Pipe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;

    char *path = "/tmp/mypipe";

    fd = mkfifo(path, 0777);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
    }

    return 0;
}