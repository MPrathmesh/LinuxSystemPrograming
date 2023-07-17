//Write a program which accept directory name from user and create new diretory of that name.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h> //this header file is useful for creting directory

int main(int argc, char *argv[])
{
    int fd = 0;
    char Dname[20];

    printf("Enter Directory name that you want create : \n");
    scanf("%s", Dname);

    fd = mkdir(Dname,0777);
    if(fd == -1)
    {
        printf("Unable to cretae Directory\n");
        return -1;
    }

    printf("Directory successfully created\n");

    return 0;
}