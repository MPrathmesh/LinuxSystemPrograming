#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

//stat System call it gives information about file
int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficent arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File name : %s\n",argv[1]);
    printf("File size is : %d\n", sobj.st_size);
    printf("Number of Links : %d\n", sobj.st_nlink);
    printf("Inode number : %d\n", sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of Blocks : %d\n",sobj.st_blocks);

    return 0;
}