//Write a program which creates two processes and that two process can communicate
//with each other by using concept of shared memory.
//Server 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>


int main()
{
    int shmid = 0;
    int shmsize = 100;
    int key = 1234;
    char *ptr = NULL;

    printf("Client application is running...\n");

    shmid = shmget(key, shmsize, 0666);  //Just created

    ptr = shmat(shmid, NULL, 0);    //attached

    if(ptr != NULL)
    {
        printf("Shared Memory attached successfully...\n");
    }

    return 0;
}

