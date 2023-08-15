//Write a program which is used to create unnamed pipe. Parent process creates new child
//process and both the process will communicate with each other.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int FD[2];
    int iRet = 0;
    char Arr[] = "Prathamesh More";
    char Buffer[512];

    pipe(FD);

    iRet = fork();

    if(iRet == 0)
    {
        close(FD[0]);
        write(FD[1], Arr, strlen(Arr));
        exit(0);
    }
    else
    {
        printf("Parent Process schudeled for reading from pipe.\n");
        close(FD[1]);
        read(FD[0], Buffer, sizeof(Buffer));
        printf("Data from PIPE is : %s\n", Buffer);
    }

    return 0;
}