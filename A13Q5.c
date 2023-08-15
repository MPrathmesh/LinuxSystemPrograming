//Write a program which creates two process as sender and receiver in which sender process
//send signal to receiver process
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int sender_pid, receiver_pid;

void sig_handler(int sig_no)
{
    if(sig_no == SIGUSR1)
    {
        printf("Receiver: Received SIGUSR1 signal from sender\n");
    }
    printf("Recevied signal : %d\n", sig_no);
}

void sender_process()
{
    sleep(2);
    printf("Sending SIGUSR1 signal to receiver\n");
    kill(receiver_pid, SIGUSR1);
    printf("Sender process is finished\n");
}

void receiver_process()
{
    signal(SIGUSR1, sig_handler);
    receiver_pid = getpid();
    printf("Receiver process started PID: %d\n", receiver_pid);   
    while(1)
    {
        sleep(1);
    } 
}

int main()
{
    int PID = fork();
    if(PID == -1)
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if(PID == 0)
    {
        receiver_process();   
    }
    else
    {
        sender_pid = PID;
        printf("Sender process started PID %d\n", sender_pid);
        sender_process();
    }


    return 0;
}