//Write a program which accept file name from user and offset, remove all the data from that offset
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv)
{
    char FileName[30];
    int offset = 0;
    int fd = 0;

    printf("Enter file name : \n");
    scanf("%s", FileName);

    printf("Enter offset : \n");
    scanf("%d", &offset);

    //Open File
    fd = open(FileName, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    //set offset
    lseek(fd, offset, SEEK_SET);

    //delete data
    truncate(FileName,offset);

    return 0;
}