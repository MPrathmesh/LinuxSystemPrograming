//Write a program which writes structure in file. Structures should conatins information of student.
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)
struct student
{
    int RollNo;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{   
    struct student sobj;
    char Fname[20];
    int fd = 0;

    sobj.RollNo = 11;
    sobj.Age = 21;
    sobj.Marks = 87.5;
    strcpy(sobj.Sname, "Prathamesh");

    printf("Enter the file name\n");
    scanf("%s", Fname);

    fd = creat(Fname, 0777);

    write(fd, &sobj, sizeof(sobj));

    return 0;
}
