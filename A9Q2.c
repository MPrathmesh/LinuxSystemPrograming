//Write a program which creates two process.
//Process 1 count number of capital characters from demo.txt file.
//and Process 2 count number of capital characters from hello.txt file
//Both the processes writes its count in count.txt file.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret1 = 0, ret2 = 0;
    int pid1 = 0, pid2 = 0;
    int status1, status2;

    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./Process1","NULL", NULL);
    }
    wait(&status1);

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./Process2","NULL",NULL);
    }

    wait(&status2);

    return 0;
}