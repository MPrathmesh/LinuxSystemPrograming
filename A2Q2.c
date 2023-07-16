//Write a program which accept file name from user and write string in that file
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to opend that file\n");
        return -1;
    }

    write(fd, "Prathamesh\n", 11);

    return 0;
}