//Write a program which accept file name and position from user and read 20 bytes from that position
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char Arr[20];

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }   

    lseek(fd, atoi(argv[1]), 0);

    ret = read(fd, Arr, 20);

    printf("Data from file is\n");
    write(1, Arr, ret);

    close(fd);

    return 0;
}