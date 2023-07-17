//Write a program which accept directory name from user and copy first 10 bytes
//from all regular files into newly created file named as Demo.txt
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0;

    printf("Enter Directory name : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {   
        fobj.FileSize = sobj.st_size;
        strcpy(fobj.FileName, entry->d_name);
        write(fd, &fobj, 11);
        printf("%s\n",entry->d_name);
    }

    closedir(dp);

    return 0;
}