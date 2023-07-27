/*
    Write a program which is used to create 2 shared libraries and that library should be
    loaded at run time by the other program.
    First library should conatains function to check whether the input number is prime or not.
    second library should contains function to check whether the input number is perfect or not.
*/
#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>

int main()
{
    void *prime_lib = NULL;
    void *perfect_lib = NULL;
    bool (*Prime)(int);
    bool (*Perfect)(int);

    prime_lib = dlopen("/home/prathamesh/Desktop/LSP/LSP_Assignment/DynamicLibrary/DLPrime.so", RTLD_LAZY);
    if(prime_lib == NULL)
    {
        printf("Unable to prime number library");
        return -1;
    }

    perfect_lib = dlopen("/home/prathamesh/Desktop/LSP/LSP_Assignment/DynamicLibrary/DLPerfect.so", RTLD_LAZY);
    if(perfect_lib == NULL)
    {
        printf("Unable to load perfect number library");
        dlclose(prime_lib);
        return -1;
    }

    Prime = dlsym(prime_lib, "chkPrime");
    if(!Prime)
    {
        printf("Unable to load Prime function address\n");
        dlclose(prime_lib);
        dlclose(perfect_lib);
        return -1;
    }

    Perfect = dlsym(perfect_lib, "chkPerfect");
    if(!Perfect)
    {
        printf("Unable to load Perfect function address\n");
        dlclose(prime_lib);
        dlclose(perfect_lib);
        return -1;
    }

    int iValue = 0;
    bool bRet1 = false;
    bool bRet2 = false;
    printf("Enter a number : ");
    scanf("%d ", &iValue);

    bRet1 = Prime(iValue);
    if(bRet1 == true)
    {
        printf("%d is prime number.\n", iValue);
    } 
    else
    {
        printf("%d is not prime number.\n", iValue);
    }

    bRet2 = Perfect(iValue);
    if(bRet2 == true)
    {
        printf("%d is perfect number.\n", iValue);
    } 
    else
    {
        printf("%d is not perfect number.\n", iValue);
    }

    dlclose(prime_lib);
    dlclose(perfect_lib);

    return 0;
}