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

    fd = open(argv[1],O_RDWR); 
    if(fd != -1)
    {
        printf("File is existing\n");
    }
    else
    {
        fd = creat(argv[1],0777);
        if(fd != 1)
        {
            printf("Now file gets created\n");
        }
    }

    return 0;
}
