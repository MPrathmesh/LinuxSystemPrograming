//Write a program which accept directory name from user and print name of
//such a file having largest size.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[20];
    struct stat sobj;
    char nameCopy[30];
    int iMax = 0;

    printf("Enter name of directory : \n");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName, entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(nameCopy,name);
            }
        }
    }

    printf("Name of largest file : %s with size %d bytes \n",nameCopy,iMax);

    closedir(dp);

    return 0;
}