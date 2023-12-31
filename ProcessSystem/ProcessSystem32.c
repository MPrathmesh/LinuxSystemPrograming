//Mutitasking in linux chapter start
//MutliThreading using pThread Library
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

//Function kadun return value gheychi
void * ThreadProc(void *ptr)
{
    int i = (int)ptr;
    printf("value of recived from main thread is : %d\n", (int)ptr);
    //pthread_exit((int *)(++i));
    pthread_exit(++i);

}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 11;
    int value = 0;

    ret = pthread_create(&TID,          //Address of pthread_t structre object
                         NULL,          //Thread attributes
                         ThreadProc,    //Address of callback function
                         (int *)no);    //parameters of callback function

    if(ret != 0)
    {
        printf("Unable to create to thread.\n");
        return -1;
    }

    printf("Thread is created with ID : %lu\n",TID);
    // pthread_join(TID,(void **)&value);
    pthread_join(TID,&value);
    printf("Return value form thread is : %d\n", value);
    printf("End of main thread.\n");

    return 0;
}