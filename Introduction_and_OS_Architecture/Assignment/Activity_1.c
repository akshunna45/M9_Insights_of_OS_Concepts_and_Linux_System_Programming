/*

* Write a program to copy one file contents to other
* Using open,read,write,close system calls
* (like cp command, which takes source, destination files as cmd line args).

*/
// startup
// atexit
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "unistd.h"
#include <fcntl.h>
int main(int argc, char *argv[])
{
// printf();
#if 1
    char buf[100] = "";
    sprintf(buf, "Count = %d\n", argc);
#else
char buf[100] = "Count = ";
// sprintf(buf, " = %d\n", argc);
// convert from int to string
// strcat()
#endif
// write(1, buf, strlen(buf));

//printf("Arg = %s\n", argv[0]);

    if (argc < 3)
    {
        printf("Error!! \nUsage :- executable sourcefilename destinationfilename\n");
        exit(-1);
    }

    char *src_filename = argv[1];
    char *dest_filename = argv[2];

    //printf("Source file name = %s\n", src_filename);
    //printf("Destination file name = %s\n", dest_filename);

    int src_fd = open(src_filename, O_RDONLY);
    if (0 > src_fd)
    {
        perror("open");
        exit(-1);
    }
    int dest_fd = open(dest_filename, O_RDWR | O_CREAT);
    if (0 > dest_fd)
    {
        perror("open");
        exit(-1);
    }
    // printf("Source file descriptor = %d\n", src_fd);
    // printf("Destination file descriptor = %d\n", dest_fd);

    memset(buf, '\0', 100);

    int readBytes = read(src_fd, buf, 100);
    if (0 > readBytes)
    {
        perror("read");
        // exit(0);
    }

    // printf("File content = %s, nBytes = %d\n", buf, readBytes);

    int wrBytes = write(dest_fd, buf, readBytes);
    if (0 > wrBytes)
    {
        perror("read");
        // exit(0); 
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}