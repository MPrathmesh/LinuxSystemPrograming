//exec system call
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;

    Ret = fork();

    if(Ret == 0)  //Child
    {
        execl("./ChildProcess","Demo","Hello","Marvellous",NULL); //execl l for list
        //Parameter 1 : Name of excutable
        //Parameter 2 : Multiple values separetd by, which are considered as command line arguments
            //argv[0] : Demo
            //argv[1] : Hello
            //argv[2] : Marvellous
        //Parameter 3 : Environment varible (NULL)
    }
    else    //Parent
    {
        printf("Parent is running with PID : %d\n", getpid());
    }

    return 0;
}