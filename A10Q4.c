//Write a program which creates single thread and it accept one value from 
//user and it return some value to the caller thread.
#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    int i = (int)ptr;
    printf("Value of recived from main thread is : %d\n", (int)ptr);
    pthread_exit(++i);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 11;
    int value = 0;

    ret = pthread_create(&TID,
                        NULL,
                        ThreadProc,
                        (int *)no);

    if(ret != 0)
    {
        printf("Unable to create to thread.\n");
        return -1;
    }
    printf("Thread is created with ID : %lu\n",TID);
    pthread_join(TID, &value);
    printf("Return value from thread is : %d\n", value);

    printf("End of main thread.\n");
    pthread_exit(NULL);


    return 0;
}