//Write a program which accept file name and on mode and that program check whether our
//process can access that file in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 2)
    {
        printf("Insufficent number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2], "Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDWR;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to file open\n");
        return -1;
    }
    else
    {
        printf("Successfully file opend with fd %d\n",fd);
    }
    
    if(access(argv[1],F_OK) != 0)
    {
        printf("%s does not exist\n", argv[1]);
    }
    else
    {
        if(access(argv[1], R_OK) == 0)
        {
            printf("You have read access to %s\n", argv[1]);
        }
        if(access(argv[1], W_OK) == 0)
        {
            printf("You have write access to %s\n", argv[1]);
        }
        if(access(argv[1], X_OK) == 0)
        {
            printf("You have search access to %s\n", argv[1]);
        }
    }

    return 0;
}