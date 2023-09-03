#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

//operations on directory System call 
int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient argument\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("---------------------------------------\n");
    printf("Enteries from the directory file are : \n");
    printf("---------------------------------------\n");
    printf("File Name\t\t Inode Number \n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%20s : %d\n", entry->d_name, entry->d_ino);
    }
    printf("---------------------------------------\n");

    close(dp);
    return 0;
}