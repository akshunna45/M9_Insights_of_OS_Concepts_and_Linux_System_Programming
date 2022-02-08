/*
Write a program to compile & link any c/c++ program 
within child process by launching gcc 
using execl/execlp.
*/

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "unistd.h"
#include <fcntl.h>
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Error!! \nUsage :- executable sourcefilename destinationfilename\n");
        exit(-1);
    }

    char* arrlargc;
    for(int i=0;i<5;i++)
    {
        printf("After exact\n");
    }
    return 0;
}