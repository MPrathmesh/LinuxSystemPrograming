//Write a program which accept file name which contains data of all file. We have to create all file again.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void ExtractFiles(char *inputFile)
{
    int fd1 = open(inputFile, O_RDONLY);
    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return;
    } 

    char Buffer[256];
    char fileName[30];
    char content[1024];
    int fd2 = 0;

    while(read(fd1, Buffer, sizeof(Buffer)))
    {   
        //"---" this are separaters
        if(strncmp(Buffer, "---", 3) == 0)
        {
            if(read(fd1, fileName, sizeof(fileName)) == 0)
            {
                break; //EOF
            }

            if(read(fd1, content, sizeof(content)) == 0)
            {
                break; //EOF
            }

            fd2 = open(fileName, O_WRONLY | O_CREAT, 0777);
            if(fd2 == -1)
            {
                printf("Unable to create file\n");
                continue;
            }

            if(write(fd2, content, strlen(content)) == -1)
            {
                printf("Unable to write in this file\n");
            }

            close(fd2);
            printf("File '%s' created successfully.\n", fileName);            
        }
    }
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    ExtractFiles(argv[1]);
    return 0;
}
