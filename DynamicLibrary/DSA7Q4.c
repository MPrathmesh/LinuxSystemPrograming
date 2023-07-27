#include<stdio.h>
#include<dlfcn.h>
#include"A7Q4.h"

int Call_inner_Library(int iNo)
{
    void *ptr = NULL;
    int (*Factorial)(int);

    ptr = dlopen("/home/prathamesh/Desktop/LSP/LSP_Assignment/DynamicLibrary/DSA7Q4Inner.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to inner library");
        return -1;
    }

    Factorial = dlsym(ptr, "Factorial");
    if(Factorial == NULL)
    {
        printf("Unable to load inner function address.\n");
        dlclose(ptr);
        return -1;
    }

    int iRet = Factorial(iNo);
    dlclose(ptr);

    return iRet;
}




