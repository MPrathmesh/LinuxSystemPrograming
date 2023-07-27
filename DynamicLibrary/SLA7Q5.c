//Static Shared File
#include<stdio.h>
#include<sys/stat.h>

void DisplayInfo(char* filename)
{
    struct stat sobj;

    stat(filename, &sobj);

    printf("File name : %s\n", filename);
    printf("File system number : %ld\n", sobj.st_dev);
    printf("Inode Number of file : %ld\n", sobj.st_ino);
    printf("Number of Links : %ld\n", sobj.st_nlink);
    printf("User ID of owner : %d\n",sobj.st_uid);
    printf("Group ID of owner : %d\n",sobj.st_gid);
    printf("Total size of file : %ld\n",sobj.st_size);
    printf("Number of blocks : %ld\n", sobj.st_blocks);
    printf("Block size for filesystem I/O : %ld\n",sobj.st_blksize);
}

/*
    gcc -c file_info.c
    ar rcs libfileinfo.a file_info.o
*/