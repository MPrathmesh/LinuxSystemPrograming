//Client.c File
/*
Write a program which is used to create shared library and that library should be loaded
at run time by the other program.
That Library should conatins funtion which accepts 2 file names from user and it will
comapare the contents of that file
*/

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    int (*fptr)(char[], char[]);

    ptr = dlopen("/home/prathamesh/Desktop/LSP/LSP_Assignment/DynamicLibrary/libraryQ2.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load libraryQ2.so library\n");
        return -1;
    }

    fptr = dlsym(ptr,"chkFiles");
    if(fptr == NULL)
    {
        printf("unable to load the address of function\n");
        dlclose(ptr);
        return -1;
    }
    
    int iRet = 0;

    iRet = fptr(argv[1], argv[2]);

    if(iRet == 0)
    {
        printf("The contents of the files are the same.\n");
    }
    else if(iRet == 1)
    {
        printf("The contents of the files are different.\n");   
    }
    else 
    {
        printf("Error: Unable to open files.\n");
    }

    dlclose(ptr);

    return 0;
}