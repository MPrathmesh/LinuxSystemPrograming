//Write a program which accept file name from user and print all information about that file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficent argument\n");
        return -1;
    }

    stat(argv[1], &sobj);

    printf("File name : %s\n", argv[1]);
    printf("File system number : %ld\n", sobj.st_dev);
    printf("Inode Number of file : %ld\n", sobj.st_ino);
    printf("Number of Links : %ld\n", sobj.st_nlink);
    printf("User ID of owner : %ld\n",sobj.st_uid);
    printf("Group ID of owner : %ld\n",sobj.st_gid);
    printf("Total size of file : %ld\n",sobj.st_size);
    printf("Number of blocks : %ld\n", sobj.st_blocks);
    printf("Block size for filesystem I/O : %ld\n",sobj.st_blksize);

    return 0;
}
