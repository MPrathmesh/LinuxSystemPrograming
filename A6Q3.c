//Write a program which accept directory name and file name from user and create file in that directory
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv)
{
    char DirName[30];
    char FileName[30];

    printf("Enter Directory Name : \n");
    scanf("%s", DirName);

    printf("Enter File name : \n");
    scanf("%s", FileName);

    char filePath[20];
    sprintf(filePath, "%s/%s",DirName, FileName);

    if(creat(filePath, 0777) == -1)
    {
        printf("Unable to create file");
        return -1;
    }

    printf("File created successfully at '%s'\n", filePath);

    return 0;
}