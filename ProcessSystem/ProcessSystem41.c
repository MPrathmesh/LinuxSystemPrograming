//Inter Process Communication(IPC)
//Using Shared Memory
//Server for shared Memory
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

    printf("Server application is running...\n");

    shmid = shmget(key, shmsize, IPC_CREAT | 0666);  //Just created

    printf("Shared memory allocated successfully....\n");

    ptr = shmat(shmid, NULL, 0);    //attached

    if(ptr != NULL)
    {
        printf("Shared Memory attached successfully...\n");
    }

    return 0;
}