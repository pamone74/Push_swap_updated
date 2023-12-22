#include "ft_minitalk.h"

int sigrecived = 0;
void signal_handler(int signum) {
    if(signum == SIGUSR1)
    {
        sigrecived = 1;
        char **current_str = str;
        while (*current_str != NULL)
        {
            printf("%s ", *current_str);
            usleep(50000);
            current_str++;
        }
        printf("\n");
        printf("Helo there!");
    }
    
}

int main(void) {
    pid_t pid = getpid();
    printf("The PID [%d]\n", pid);
    signal(SIGUSR1, signal_handler);
    while (!sigrecived)
    {
       sleep(1);
    }

}
