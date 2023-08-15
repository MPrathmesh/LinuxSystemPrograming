//Write a program which creates such a process and parent process will communicate with
//child process by sending signals.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int PID;

void sig_handler(int sig_no)
{
    if(sig_no == SIGINT)
    {
        printf("Received Signal from child\n");
    }
    printf("Recevied signal is %d\n", sig_no);
}

void child_process()
{
    printf("Child process started\n");
    sleep(2);
    printf("Sending signal to parent\n");
    kill(getppid(), SIGINT);
    printf("Child process is finished\n");
}

int main()
{
    printf("Able to receive the signal\n");
    signal(SIGINT, sig_handler);

    PID = fork();
    if(PID == -1)
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if(PID == 0)
    {
        child_process();
    }
    else
    {
        printf("Parent process is running..\n");
        pause();
        printf("Parent process is finished..\n");
    }


    return 0;
}