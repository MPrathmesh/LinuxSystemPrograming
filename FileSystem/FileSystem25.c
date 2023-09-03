#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invaild arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDWR | O_CREAT); //yeth jr file exist nasel tr cret system call mule te file create hote.
    if(fd != -1)
    {
        printf("File is succesfully open with fd %d\n", fd);
    }

    return 0;
}
