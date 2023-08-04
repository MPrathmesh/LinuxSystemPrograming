//Write a program which creates 4 number of threads and our main thread
//waits till all the thread terminates.
#include<stdio.h>
#include<pthread.h>

#define THREADS 4

void* ThreadProc(void* ptr)
{
    int i  = pthread_self();
    int TID = *(int*)ptr;
    printf("Thread %d is running ID is : %d\n", TID, i);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID[THREADS];
    int ret[THREADS];
    int i;

    for(i = 0; i < THREADS;i++)
    {
        ret[i] = i;
        if(pthread_create(&TID[i], NULL, ThreadProc, &ret[i]) != 0)
        {
            printf("Unable to create thread ID : %d\n", ret[i]);
            return -1;
        }
    }

    for(int i = 0; i < THREADS; ++i)
    {
        pthread_join(TID[i], NULL);
    }

    printf("All threads are created successfully.\n");
    printf("Main thread finsih.\n");
    pthread_exit(NULL);

    return 0;
}