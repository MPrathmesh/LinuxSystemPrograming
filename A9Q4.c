//Write a program which is used to increase the priority by 5.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int ret = 0;

    ret = nice(5);

    printf("Current Priority of process is %d\n",ret);

    ret = nice(10);

    printf("Current Priority of process is %d\n",ret);

    return 0;
}