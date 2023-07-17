//Write a program which accept directory name and file name from user
//and check whether that file is present in that directory or not.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int chkFile(char Dir[], char F1[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    dp = opendir(Dir);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(F1, entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    chkFile(argv[1], argv[2]);

    return 0;
}
