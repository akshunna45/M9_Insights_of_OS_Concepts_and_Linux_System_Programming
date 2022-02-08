#include "unistd.h"
#include "stdio.h"

int main()
{
    int ret = fork();
    printf(" Hello, Welcome to Linux Programming, ret = %d, PID = %d, PPID = %d \n", ret, getpid(), getppid());
    return 0; 
}