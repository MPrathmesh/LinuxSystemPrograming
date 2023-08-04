//Write a program which creates single thread and we have to pass paramter
//to that thread from main thread.
#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Value of recived from main thread is : %d\n", (int)ptr);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 21;

    ret = pthread_create(&TID,
                        NULL,
                        ThreadProc,
                        (int *)no); 

    if (ret != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }

    printf("Thread is created with ID : %lu\n", TID);
    pthread_join(TID, NULL);
    printf("End of main thread.\n");
    
    return 0;
}