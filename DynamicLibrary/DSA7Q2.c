//Write a which accept two file names from user and check whether 
//contents of that two files are equal or not.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include"A7Q2.h"

int chkFiles(char F1[], char F2[])
{
    int fd1 = 0;
    int fd2 = 0;
    fd1 = open(F1, O_RDONLY);
    fd2 = open(F2, O_RDONLY);
    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open files\n");
        return -1;
    }

    char Buffer1[1024];
    char Buffer2[1024];
    int ret1 = 0;
    int ret2 = 0;
    int diff = 0;

    do
    {
        ret1 = read(fd1, Buffer1, sizeof(Buffer1));
        ret2 = read(fd2, Buffer2, sizeof(Buffer2));

        if(ret1 != ret2 || memcmp(Buffer1, Buffer2, ret1) != 0)
        {
            diff = 1;
        }
    } while (ret1 > 0);

    close(fd1);
    close(fd2);

    return diff;
}