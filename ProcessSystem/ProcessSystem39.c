//Inter Process Communication(IPC)
//Using named Pipe
//Client For Named Pipe
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
    char Buffer[100];

    fd = mkfifo(path, 0777);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    printf("Client is running and reading data from named pipe...\n");
    fd = open(path, O_WRONLY);

    read(fd, Buffer, 10);

    printf("Data from pipe is %s\n", Buffer);
    
    return 0;
}