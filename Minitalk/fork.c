#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int  main(void)
{
    fork();
    //printf("Hello This is my first Fork() prgram PID = %d\n", getpid());
    while(1)
    {
        printf("Hello This is my first Fork() prgram PID = %d\n", getpid());
        
    }
}