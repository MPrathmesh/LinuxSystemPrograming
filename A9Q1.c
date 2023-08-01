//Write a program which creates new process which is responsible to write all file
//names which are present on desktop in demo.txt file should be created newly
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main()
{
    int pid = 0;

    pid = fork();

    if(pid < 0)
    {
        printf("Unable to create process.\n");
        return -1;
    }
    else if(pid == 0)
    {
        execl("./CA9Q1","NULL",NULL);
    }

    wait(NULL);

    return 0;
}