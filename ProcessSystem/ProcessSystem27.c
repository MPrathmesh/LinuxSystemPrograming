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
    int i = 0;
    for(i = 1; i <= 1000; i++)
    {
        printf("Thread with counter : %d\n", i);
    }
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

    pthread_join(TID,NULL);   //hai apleli main thread la thambun tevt jo parynt apla second thread ch kam purn hot nahi hai like exit system call process madhl ahe

    printf("End of main thread.\n");

    return 0;
}