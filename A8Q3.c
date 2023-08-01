//Write a program which creates three diffrent processes internally as process2, process3, process4.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid2= 0;
    int pid3= 0;
    int pid4= 0;
    int Exit_status1 = 0;
    int Exit_status2 = 0;
    int Exit_status3 = 0;

    printf("Main Process PID is : %d\n",getpid());

    pid2 = fork();
    if(pid2 == 0)
    {
        printf("Process 2 PID : %d\n",getpid());
        exit(Exit_status1);
        //printf("Process 2\n");
    }
    else if(pid2 < 0)
    {
        printf("Unable to create second process.\n");
        return -1;
    }

    pid3 = fork();
    if(pid3 == 0)
    {
        printf("Process 3 PID : %d\n",getpid());
                exit(Exit_status2);

        //printf("Process 3\n");
    }
    else if(pid3 < 0)
    {
        wait(NULL);
        printf("Unable to create third process.\n");
        //printf("Process 3");
    }

    pid4 = fork();
    if(pid4 == 0)
    {
        //wait(NULL);
        printf("Process 4 PID : %d\n",getpid());
                exit(Exit_status3);

        //printf("Process 4\n");
    }
    else if(pid4 < 0)
    {
        printf("Unable to create fourth process.\n");
        printf("Process 4\n");    
    }

    return 0;
}