//Client.c File
/*
Write a program which is used to create shared library and that library should be loaded
at run time by the other program.
That library should conatins functions to perform the arithmatic operations like addition,
Subtraction, Division and Multiplication.
*/

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*Add)(int, int);
    int (*Sub)(int, int);
    int (*Mul)(int, int);
    int (*Div)(int, int);
    int iValue1 = 10;
    int iValue2 = 5;

    ptr = dlopen("/home/prathamesh/Desktop/LSP/LSP_Assignment/DynamicLibrary/libraryQ1.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    Add = dlsym(ptr,"Addition");
    Sub = dlsym(ptr,"Subtraction");
    Mul = dlsym(ptr,"Multiplication");
    Div = dlsym(ptr,"Division");
    if(!Add || !Sub || !Mul || !Div)
    {
        printf("Unable to load the addresses of function\n");
        dlclose(ptr);
        return -1;
    }

    printf("Addition is %d\n",Add(iValue1, iValue2));
    printf("Subtraction is %d\n",Sub(iValue1, iValue2));
    printf("Multiplication is %d\n",Mul(iValue1, iValue2));
    printf("Division is %d\n",Div(iValue1, iValue2));

    dlclose(ptr);

    return 0;
}