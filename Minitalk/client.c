#include "ft_minitalk.h"

/*
Steps to handle the signals
    1. Create a signal handler function
    2.  Register the signal usin g signal function that takes two parameters ie 
        the signal number and the address of the signal handler function
    
*/

// Creating a handler function that ovarrides the default behavior of the of the signal 
// static int recieved_signal = 0;
// void	sig_handler(int sig_num, siginfo_t * info, void *context)
// {
    // static int	i;
// 
	// (void)context;
	// (void)info;
	// (void)sig_num;
	// recieved_signal = 1;
	// if (sig_num == SIGUSR2)
		// i++;
	// else if (sig_num == SIGUSR1)
		// printf("The number of bytes received\n");
// }
// 
// int	char_to_bin(char c, int pid)
// {
	// int	itr;
	// int	bit_index;
// 
	// bit_index = 7;
	// while (bit_index >= 0)
	// {
		// itr = 0;
		// if ((c >> bit_index) & 1)
			// kill(pid, SIGUSR1);
		// else
			// kill(pid, SIGUSR2);
		// while (recieved_signal == 0)
		// {
			// if(itr == 50)
			// {
				// printf("The server is not responding\n");
				// exit(1);
			// }
			// itr++;
			// usleep(100);
		// }
		// 
		// recieved_signal  = 0;
		// bit_index --;
	// }
	// return (0);
	// 
// }
// 
// int main(int argc, char *argv[])
// {
	// struct sigaction sa;
	// char	c;
	// int		pid;
	// int		i;
	// if(argc > 1)
	// {
		// pid= atoi(argv[1]);
		// sigemptyset(&sa.sa_mask);
		// sa.sa_sigaction = sig_handler;
		// sigaction(SIGUSR1, &sa, NULL);
		// sigaction(SIGUSR2, &sa, NULL);
		// i = 0;
		// while (argv[2][i])
		// {
			// char_to_bin(argv[2][i],pid);
			// i++;
		// }
		// char_to_bin('\0', pid);
	// }
// }

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t g_receiver = 0;

void sig_handler(int signum, siginfo_t *info, void *context)
{
    (void)context;
    (void)info;
    (void)signum;

    static int i = 0;

    if (signum == SIGUSR2)
    {
        i++;
    }
    else if (signum == SIGUSR1)
    {
        printf("Number of bytes received: %d\n", i / 8); // 8 bits make 1 byte
        i = 0;
    }
}

int char_to_bin(char c, int pid)
{
    int itr;
    int bit_index = 7;

    while (bit_index >= 0)
    {
        itr = 0;

        if ((c >> bit_index) & 1)
        {
            kill(pid, SIGUSR1);
        }
        else
        {
            kill(pid, SIGUSR2);
        }

        while (g_receiver == 0)
        {
            if (itr == 50)
            {
                printf("Error: No response from the server\n");
                exit(1);
            }

            itr++;
            usleep(100); // Adjust the sleep duration as needed
        }

        g_receiver = 0;
        bit_index--;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
        exit(1);
    }

    int server_pid = atoi(argv[1]);
    struct sigaction sa;

    // Set up signal handlers for SIGUSR1 and SIGUSR2
    //sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    sa.sa_sigaction = sig_handler;

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    int byte_index = 0;
    while (argv[2][byte_index])
    {
        char_to_bin(argv[2][byte_index], server_pid);
        byte_index++;
    }

    // Sending '\0' to indicate the end of the message
    char_to_bin('\0', server_pid);

    return 0;
}
