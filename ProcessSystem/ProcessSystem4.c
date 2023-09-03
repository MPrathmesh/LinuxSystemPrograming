//Fork System call
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int PID = 0;

    Ret = fork();

    if(Ret == 0) //child
    {
        printf("Child Process is running\n");
        printf("Child says :  PID of parent process is : %d\n",getppid()); //7483
        printf("Child says : PID of child process is : %d\n",getpid());  //7484
    }
    else    //Parent
    {
        printf("Parent process is running\n");
        printf("Parent says : PID of child process is : %d\n",Ret); //7484
        printf("Parent says : PID of parent process is : %d\n",getpid()); //7483
        printf("Parent says : PID of parent process of parent ie Terminal is : %d\n",getppid()); //6476
    }

    return 0;
}