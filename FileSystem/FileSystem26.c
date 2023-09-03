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

    fd = creat(argv[1], 0777); //creat system call madhe jr tumhi existing file ch nav del tr exiting file madhla data delete hoto hai risky ahe
    if(fd != -1)
    {
        printf("File is succesfully created with fd %d\n", fd);
    }

    return 0;
}
