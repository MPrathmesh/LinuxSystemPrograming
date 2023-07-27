/*
    Write a program which create static library which contains file name from user and which
    displays the information of that file.
*/
#include<stdio.h>

void DisplayInfo(char* filename);

int main()
{
    char filename[20];
    printf("Enter File Name : ");
    scanf("%s",filename);

    DisplayInfo(filename);

    return 0;
}

/*
    gcc -static A7Q5.c -o Myexe SLA7Q5.a
    ./Myexe
*/