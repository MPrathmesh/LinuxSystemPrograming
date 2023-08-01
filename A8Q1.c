//Write a program in which parent process waits till its child process terminates.
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    int pid = 0;

    pid = fork();

    if(pid < 0)
    {
        printf("Unable to create child process.\n");
        return -1;
    }
    else if(pid == 0)
    {
        printf("Child process PID is : %d\n", getpid());

        for(int i = 1; i <= 5; i++)
        {
            printf("Child Process is working.\n");
            sleep(1);
        }
        printf("Child Process stop.\n");
    }
    else
    {
        printf("Parent Process waiting for child to termiante.\n");
        wait(NULL);
        printf("Child process terminated. Parent process finished.\n");
    }

    return 0;
}