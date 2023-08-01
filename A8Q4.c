//Write a program which creates two processes as process2 an process3 and our
//parent process terminates till both the processes terminates.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid1 = 0;
    int pid2 = 0;

    pid1 = fork();
    if(pid1 < 0)
    {
        printf("Unable to create process 2.\n");
        return -1;
    }
    else if(pid1 == 0)
    {
        execl("./Process1","NULL",NULL);
    }
    wait(NULL);

    pid2 = fork();
    if(pid2 < 0)
    {
        printf("Unable to create process 2.\n");
        return -1;
    }
    else if(pid2 == 0)
    {
        execl("./Process2","NULL",NULL);
    }
    wait(NULL);
    
    printf("PrathameshParent Process PID is %d\n", getpid());
    printf("Parent Process terminates");

    return 0;
}