//Write a program which accept two directory name from user and move
//all files from source directory to destination directory
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

//This function move files one directory to another directory without losing data.
int move(char old[], char new[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    char oldName[50];
    char newName[50];

    dp = opendir(old);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldName, "%s/%s", old, entry->d_name);
        sprintf(newName, "%s/%s",new,entry->d_name);

        rename(oldName, newName);
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    move(argv[1],argv[2]);

    return 0;
}