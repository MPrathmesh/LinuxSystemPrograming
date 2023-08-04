//Write a program which is used to get thread id inside its thread function.
#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    pthread_t TID = pthread_self(); //Get the current thread ID
    printf("This thread ID is : %lu.\n", TID);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,
                        NULL,
                        ThreadProc,
                        NULL);

    if(ret != 0)
    {
        printf("Unable to create thread.\n");
        return -1;
    }
    printf("Thread is created with ID : %lu\n", TID);

    pthread_exit(NULL);

    return 0;
}