//Write a program which accept user defined signal from terminal.
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int sig_no)
{
    printf("Recevied signal : %d\n", sig_no);
}

int main()
{
    int sig_number;
    printf("Able to recive user defined signal...\n");
    printf("Process PID is : %d\n", getpid());

    printf("Enter the signal Number..\n");
    scanf("%d", &sig_number);

    if(sig_number > 0 && sig_number < _NSIG) //NSIG is total number of signals
    {
        signal(sig_number, sig_handler);
        printf("Send signals %d to the process.\n", sig_number);

        while(1)
        {
            sleep(1);
        }
    }
    else
    {
        printf("Invalid signal number.\n");
    }
    
    return 0;
}