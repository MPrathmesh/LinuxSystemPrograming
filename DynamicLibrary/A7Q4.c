/*
    Write a program which create shared library which internally loads other shared library.
    The inner shared library provides the function to calculate the factorial of number
    Also write a program which will load that shared library and call the function.
*/
#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    ptr = dlopen("/home/prathamesh/Desktop/LSP/LSP_Assignment/DynamicLibrary/DSA7Q4Outer.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load outer function library,\n");
        return -1;
    }

    int (*Call_outer_libary)(int);
    Call_outer_libary = dlsym(ptr,"Call_inner_Library");
    if(Call_outer_libary == NULL)
    {
        printf("Unable to load outer function address.\n");
        dlclose(ptr);
        return -1;
    }

    int iValue = 0;
    printf("Enter a number : ");
    scanf("%d", &iValue);

    int Result = Call_outer_libary(iValue);
    
    printf("Factorial of %d is %d.\n",iValue, Result);

    return 0;
}