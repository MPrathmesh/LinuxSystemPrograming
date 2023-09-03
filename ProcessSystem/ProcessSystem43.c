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

    printf("Client application is running...\n");

    shmid = shmget(key, shmsize, 0666);  //Just created

    ptr = shmat(shmid, NULL, 0);    //attached

    if(ptr != NULL)
    {
        printf("Shared Memory attached successfully...\n");
    }

    *ptr = 'H';
    ptr++;
    *ptr = 'E';
    ptr++;
    *ptr = 'L';
    ptr++;
    *ptr = 'L';
    ptr++;
    *ptr = 'O';
    ptr++;
    *ptr = '\0';
    ptr++;

    printf("Data is written in shread memory successfully....\n");

    return 0;
}
