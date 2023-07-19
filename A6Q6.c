//Write a program which accept directory name from user and create hole in file
//if size is less than 1kb & if it is greater than 1kb then truncate the remaining data.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    char FileName[30];
    char FilePath[20];
    int fd = 0;
    struct stat sobj;
    int offSet = 0;

    printf("Enter Directory Name : \n");
    scanf("%s", DirName);

    printf("Enter File Name : \n");
    scanf("%s", FileName);

    snprintf(FilePath, sizeof(FilePath), "%s/%s", DirName, FileName);

    fd = open(FilePath, O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file");
        return -1;
    }

    stat(FilePath, &sobj);
    offSet = sobj.st_size;

    if(offSet < 1024)
    {
        int hole = 1024 - offSet;
        lseek(fd,hole - 1, SEEK_END);

        write(fd, "",1);

        printf("Hole created in the file.\n");
    }
    else
    {
        truncate(FileName, 1024);
        printf("File truncated to 1kb.\n");
    }    

    close(fd);

    return 0;
}

