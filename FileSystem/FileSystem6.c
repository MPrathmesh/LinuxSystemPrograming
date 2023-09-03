#include<stdio.h>
#include<fcntl.h>

//Creating File by System Call
int main(int argc, char *argv[])
{
    int fd = 0;


    printf("Usage : Name_of_Excutable Name_of_File\n");

    if(argc != 2)
    {
        printf("Invalid Number of arguments\n");
        return -1;
    }

    fd = creat(argv[1], 0777);  //accept input from command line argument
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    else
    {
        printf("File is successfully created with fd : %d\n",fd);
    }

    return 0;
}

//O_RDONLY  //Read Mode
//O_RDWR    //Read Write Mode
//O_WR      //Write Mode
//O_CREATE  //Create Mode