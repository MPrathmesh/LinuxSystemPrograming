//Write a program which creates two process as reader and writer and that processes should
//communicate with each other using FIFO.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

#define FIFO_NAME "myfifo"

void write_FIFO()
{
    int fd;
    char mess[] = "Hello there";

    fd = open(FIFO_NAME, O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open FIFO");
        return -1;
    }

    if((write(fd, mess, strlen(mess) + 1)) == -1) 
    {
        printf("Unable to write in FIFO");
        close(fd);
        return -1;
    }

    printf("Sent message to reader\n");
}

void read_FIFO()
{
    int fd;
    char Buffer[1024];
    int ret = 0;

    fd = open(FIFO_NAME, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open FIFO");
        return -1;
    }

    ret = read(fd, Buffer, sizeof(Buffer));
    if(ret == -1)
    {
        printf("unable to read in FIFO");
        close(fd);
        return -1;
    }

    printf("Message from writer is : %s\n", Buffer);

    close(fd);
}

int main()
{
    mkfifo(FIFO_NAME, 0666);

    int PID = fork();

    if(PID == 0)
    {
        read_FIFO();
    }
    else
    {
        write_FIFO();
    }

    return 0;
}