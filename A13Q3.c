//Write a program which creates such a process which accept signals from the terminal.
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int sig_no)
{
    printf("\nRecevied signal : %d\n", sig_no);
}

int main()
{
    printf("Able to recevie signal...\n");
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    printf("Process is running PID : %d\n", getpid());
    //Use cntrl + c for SIGINT
    //Use kill -15 <PID> to second terminal

    while(1)
    {
        sleep(1);
    }

    return 0;
}