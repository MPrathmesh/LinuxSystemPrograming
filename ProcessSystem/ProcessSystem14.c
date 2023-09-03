//exec system call
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    //Ha code ProcessSystem13.c link ahe
    printf("Inside child process - PID of prarent process is %d\n", getppid());

    return 0;
}