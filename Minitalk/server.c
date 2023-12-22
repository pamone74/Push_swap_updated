#include "ft_minitalk.h"

void	ft_bin_char(int signu, char *c)
{
	if (signu == SIGUSR1)
	{
		*c = (*c << 1) | 1;
	}
	else if(signu == SIGUSR2)
		*c <<= 1;
	
}

void	sig_handler(int sig_num, siginfo_t * info, void *context)
{
	static	int	i;
	static	int	pid;
	static	char	c;
	pid = info->si_pid;
	printf("Received signal %d, i: %d, pid: %d, c: %c\n", sig_num, i, pid, c);

	if(++i == 8)
	{
		i = 0;
		if(!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		c = '\0';
	}
	kill(pid, SIGUSR2);
}
int main(void)
{
	struct sigaction sa;
	printf("The server PID [%d]\n", getpid());
	//sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1) {
    perror("sigaction");
    exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1) {
	    perror("sigaction");
	    exit(EXIT_FAILURE);
	}
	
	volatile sig_atomic_t byte_ready = 0;

    while (1)
    {
        if (byte_ready)
        {
            byte_ready = 0;
        }
        pause();
    }
	return (0);

}