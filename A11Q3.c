//Write a program which is used to predict the problem due to lack of synchronization.
#include<stdio.h>
#include<pthread.h>

int counter = 0;

void * ThreadProc(void *ptr)
{
    int i = 0;
    counter++;
    printf("Thread excuted with counter : %d\n", counter);
    for(i = 0; i < 0xFFFFFFFF; i++);
    printf("Thread completed with counter : %d\n", counter);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int ret = 0;

    ret = pthread_create(&TID1, NULL, ThreadProc, NULL);
    if(ret != 0)
    {
        printf("Unbale to create to thread.\n");
        return -1;
    }

    ret = pthread_create(&TID2, NULL, ThreadProc, NULL);
    if(ret != 0)
    {
        printf("Unbale to create to thread.\n");
        return -1;
    }


    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    printf("End of main thread.\n");

    return 0;
}