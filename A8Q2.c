//Write a program which create three level process hierarchy where process 1
//create process 2 and it internally creates process 3.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid1= 0;
    int pid2 = 0;

    pid1 = fork();

    if(pid1 < 0)
    {
        printf("Unable to create second process.\n");
        return -1;
    }
    else if(pid1 == 0)
    {
        printf("Process 2 (PID : %d) created by process 1 (PID : %d)\n", getpid(), getppid());

        pid2 = fork();

        if(pid2 < 0)
        {
            printf("Unable to create third process.\n");
            return -1;
        }
        else if(pid2 == 0)
        {
            printf("Process 3 (PID : %d) created by Process 2 (PID : %d)\n",getpid(), getppid());
        }
        else
        {
            wait(NULL);
            printf("Process 2 (PID : %d) finished.\n", getpid());
        }
    }
    else
    {
        wait(NULL);
        printf("Process 1 (PID : %d) finished.\n", getpid());
    }

    return 0;
}