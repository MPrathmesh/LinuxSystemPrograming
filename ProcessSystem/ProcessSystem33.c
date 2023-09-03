//Function Pointer Array using pthread
#include<stdio.h>
#include<pthread.h>

#define THREADS 3

void  *ThreadProc1(void* ptr)
{
    int i  = pthread_self();
    int TID = *(int*)ptr;
    printf("Thread %d is running ID is : %lu\n", TID, i);
    pthread_exit(NULL);
}

void  *ThreadProc2(void* ptr)
{
    int i  = pthread_self();
    int TID = *(int*)ptr;
    printf("Thread %d is running ID is : %lu\n", TID, i);
    pthread_exit(NULL);
}

void *ThreadProc3(void* ptr)
{
    int i  = pthread_self();
    int TID = *(int*)ptr;
    printf("Thread %d is running ID is : %lu\n", TID, i);
    pthread_exit(NULL);
}

int main()
{
    //char *Arr[3] = {ThreadProc1, ThreadProc2, ThreadProc3};
    pthread_t TID[THREADS];
    int ret = 0;
    int i;
    void (*ptr[THREADS])(void*) = {ThreadProc1, ThreadProc2, ThreadProc3};

    // for(i = 0; i < THREADS;i++)
    // {
    //     ret[i] = i;
    //     if(pthread_create(&TID[i], NULL, *Arr, &ret[i]) != 0)
    //     {
    //         printf("Unable to create thread ID : %d\n", ret[i]);
    //         return -1;
    //     }
    // }

    for(i = 0; i < 4; i++)
    {
        ret = pthread_create(&TID[i],NULL,(ptr[i]),NULL);
    }

    for(i = 0; i < THREADS; ++i)
    {
        pthread_join(TID[i], NULL);
    }

    printf("All threads are created successfully.\n");
    printf("Main thread finsih.\n");
    pthread_exit(NULL);

    return 0;
}