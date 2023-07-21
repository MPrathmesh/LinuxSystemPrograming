//Write a program which accept directory name from user and combine all contents of the
//from the directory into one file name as AllCombine.txt.
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

void combineFiles(char *Dirname)
{
    DIR *dp = opendir(Dirname);
    int fd1 = 0;
    struct dirent *entry = NULL;
    struct stat sobj;
    char Buffer[1024];
    int fd2 = 0;
    char filePath[50];


    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return;
    }

    fd1 = open("AllCombine.txt", O_WRONLY | O_CREAT, 0777);
    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        closedir(dp);
        return;
    }


    while((entry = readdir(dp)) != NULL)
    {
        sprintf(filePath,"%s/%s",Dirname, entry->d_name);

        if(stat(filePath, &sobj) == -1)
        {
            printf("Unable to accessing the file Information\n");
            continue; //Skip this file and move to next file
        }

        if(S_ISREG(sobj.st_mode))
        {
            fd2 = open(filePath, O_RDONLY);
            if(fd2 == -1)
            {
                printf("Unable to open this file\n");
                continue; //skip this file and move to next file
            }

            int ret = 0;
            while((ret = read(fd2, Buffer, sizeof(Buffer))) > 0)
            {
                if(write(fd1, Buffer, ret) == -1)
                {
                    printf("Unable to write to combine file\n");
                    break;
                }
            }
            close(fd2);
        }
    }

    close(fd1);
    closedir(dp);
    
    printf("Contents of all regular files combined into 'AllCombine.txt' successfully.\n");
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <directory_name>\n",argv[0]);
        return -1;
    }

    combineFiles(argv[1]);

    return 0;
}