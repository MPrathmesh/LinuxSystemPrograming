//Write a program which accept directory name form user and write information of all regular
//file in and then read the contents from that file.
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void listRegularFiles(const char *directory, const char *outputFile) 
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    int fd = 0;

    // Open the directory
    dp = opendir(directory);
    if (dp == NULL) 
    {
        printf("Error opening directory\n");
        return;
    }

    // Open the output file for writing
    fd = open(outputFile, O_WRONLY | O_CREAT);
    if (fd == -1) 
    {
        printf("Error opening output file\n");
        closedir(dp);
        return;
    }

    // Loop through the directory entries
    while ((entry = readdir(dp)) != NULL) 
    {
        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);

        // Get file stats
        if (stat(filePath, &sobj) == 0) 
        {
            // Check if it's a regular file
            if (S_ISREG(sobj.st_mode)) 
            {
                // Write file name and size to the output file
                dprintf(fd, "%s - %ld bytes - iNode No -%ld\n", entry->d_name, sobj.st_size, sobj.st_ino);

                // Open the file for reading
                int fd2 = open(filePath, O_RDONLY);
                if (fd2 == -1) 
                {
                    perror("Error opening file for reading");
                    close(fd);
                    closedir(dp);
                    return;
                }

                // Read and print the file contents
                char buffer[4096];
                ssize_t bytesRead;
                while ((bytesRead = read(fd2, buffer, sizeof(buffer))) > 0) 
                {
                    write(STDOUT_FILENO, buffer, bytesRead); // Print contents to stdout
                }

                close(fd2);
            }
        }
    }

    close(fd);
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory_name> <output_file_name>\n", argv[0]);
        return 1;
    }

    const char *directory = argv[1];
    const char *outputFile = argv[2];

    listRegularFiles(directory, outputFile);

    return 0;
}
