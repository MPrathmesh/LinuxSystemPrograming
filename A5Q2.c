//Write a program which accept file name from user which contains information
//of employee, we have to read all contents of that file.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#pragma pack(1)
struct Employee
{
    int EID;
    char Ename[20];
    int Age;
};


int main(int argc, char *argv)
{
    struct Employee eobj;
    char Fname[20];
    int fd = 0;

    printf("Enter file name : \n");
    scanf("%s", Fname);

    fd = open(Fname,O_RDONLY);

    read(fd, &eobj, sizeof(eobj));

    printf("Employee ID : %d \n", eobj.EID);
    printf("Employee Name : %s \n", eobj.Ename);
    printf("EMployee : %d \n",eobj.Age);

    return 0;
}