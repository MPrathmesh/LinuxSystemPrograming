#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid Number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);  //accept input from command line argument
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is successfully opend with fd : %d\n",fd);
    }

    return 0;
}

//O_RDONLY  //Read Mode
//O_RDWR    //Read Write Mode
//O_WR      //Write Mode
//O_CREATE  //Create Mode