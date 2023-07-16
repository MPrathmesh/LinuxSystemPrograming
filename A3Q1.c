//Write a program which accept two file names from user and copy the contents of an
//existing file into newly created file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int Copy(char F1[], char F2[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    fdSource = open(F1, O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fdDest = creat(F2, 0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource, Buffer, sizeof(Buffer))) != 0)
    {
        write(fdDest, Buffer, Ret);
        memset(Buffer, 0, sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);
}

int main(int argc , char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficent arguments\n");
        return -1;
    }

    Copy(argv[1], argv[2]);

    return 0;
}