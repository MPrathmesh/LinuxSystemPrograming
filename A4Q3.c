//Write a which accept two file names from user and check whether 
//contents of that two files are equal or not.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

void chkFiles(char F1[], char F2[])
{
    char Buffer1[1024];
    char Buffer2[1024];
    int ret = 0;

    struct stat obj1, obj2;

    fstat(F1,&obj1);
    fstat(F2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are different as sizes are different\n");
        return -1;
    }

    while((ret = read(F1, Buffer1, sizeof(Buffer1))) != 0)
    {
        ret = read(F2, Buffer2, sizeof(Buffer2));
        if(memcmp(Buffer1, Buffer2, ret) != 0)
        {
            break;;
        }
    }

    if(ret == 0)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both files are different\n");
    }

    close(F1);
    close(F2);
}

int main(int argc, char *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open files\n");
        return -1;
    }

    chkFiles(argv[1], argv[2]);


    return 0;
}