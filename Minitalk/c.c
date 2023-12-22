
#include "ft_minitalk.h"
void sig_handler(int sinum, siginfo_t * info, void *context)
{
    (void)context;
    (void)info;
    (void)sinum;
    printf("Signal Handler function called\n");
}
int main(void)
{
    printf("PID [%d]\n", getpid());
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    sigaction(SIGINT, &sa, NULL);
    while(1)
        sleep(1);
    return 0;
}