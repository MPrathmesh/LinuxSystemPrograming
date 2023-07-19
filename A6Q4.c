//Write a program which accept directory name from user and delete all 
//such files whoes size is greter than 100 bytes.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

void deleteFiles(char *DirName)
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[20];
    struct stat sobj;


    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory");
        return;

    }
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(sobj.st_size > 100)
        {
            unlink(name);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficent arguments\n");
        printf("Usage : %s <Dirctory_Name>\n",argv[0]);
        return -1;
    }

    char *DirName = argv[1];

    deleteFiles(DirName);

    return 0;
}