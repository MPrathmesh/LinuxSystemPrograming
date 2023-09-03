#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

//stat System call now it gives what type of file
int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficent arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    if(S_ISREG(sobj.st_mode))
    {
        printf("Its a regular file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("It is directory file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("It is symbolic link file\n");
    }


    return 0;
}