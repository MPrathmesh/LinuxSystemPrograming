//Write ap program which accept directory name from user and print all files names from that directory
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;

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
        printf("%s\n", entry->d_name);
    }

    return 0;
}