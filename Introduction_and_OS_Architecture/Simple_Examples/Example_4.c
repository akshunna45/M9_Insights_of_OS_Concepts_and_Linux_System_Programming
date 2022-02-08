#include "unistd.h"
#include "stdio.h"

int main()
{
    int ret = fork();
    
    if (0 == ret)
        for(size_t i=0;i<100;i++)
        {
            printf(" Hello from parent, Welcome to Linux Programming, ret = %d, PID = %d, PPID = %d \n", ret, getpid(), getppid());
            sleep(1);
        }
    else if (0<ret)
        for(size_t i=0;i<100;i++)   
        {
            printf(" Hello from child, Welcome to Linux Programming, ret = %d, PID = %d, PPID = %d \n", ret, getpid(), getppid());
            sleep(1);
        }
    else
    {
        perror("fork");
    }
    return 0; 
}