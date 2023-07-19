//Write a program which create hole of size 1kb at the of file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define FILE_NAME "fileWithHole.txt"
#define HOLE_SIZE 1024 //1kb

int main(int argc, char *argv[])
{
    int fd = 0;
    int offset = 0;

    fd = open(FILE_NAME, O_RDWR | O_CREAT);
    if(fd == -1)
    {
        printf("Unable to open this file\n");
        return -1;
    }
    
    //Move the file offset to the end of the file.
    offset = lseek(fd, 0, SEEK_END);
    if(offset == -1)
    {
        printf("Cannot reach to end of file\n");
        close(fd);
        return -1;
    }

    //Move the file offset further to create a hole of size HOLE_SIZE
    offset = lseek(fd, HOLE_SIZE, SEEK_CUR);
    if(offset == -1)
    {
        printf("Error to create the hole\n");
        close(fd);
        return -1;
    }

    //Write one byte at the current offset to create the hole
    if(write(fd, "", 1) != 1)
    {
        printf("Error Writing to create the error\n");
        close(fd);
        return -1;
    }

    printf("Hole of size %d bytes creted at the end of the file.\n",HOLE_SIZE);

    close(fd);

    return 0;
}