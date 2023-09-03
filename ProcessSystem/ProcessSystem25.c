//Mutitasking in linux chapter start
//MutliThreading using pThread Library
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

//void *______(void *_____)
//{}
void * ThreadProc(void *ptr) //ThreadProc mhnj thread procedure hai just apn apl nav del hai nav windows programming madhe vaperto
{
    printf("Inside Thread\n");
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,      //Address of pthread_t structre object
                         NULL,      //Thread attributes
                         ThreadProc,//Address of callback function
                         NULL);     //parameters of callback function

    if(ret != 0)
    {
        printf("Unable to create to thread.\n");
        return -1;
    }

    printf("Thread is created with ID : %lu\n",TID);

    return 0;
}