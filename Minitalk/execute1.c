#include "ft_minitalk.h"

int main(int ac, char *argv[])
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("Failed Froking");
        exit(EXIT_FAILURE);
    }else if (pid == 0)
    {
       printf("The PID is >>>>>> [%d] <<<<<<<\n", getpid());
       char *args[] = {"Hello", "I am Amone", "Academy", NULL};
        if(execv("./ex2", args) == -1)
        {
            perror("Execution Failure");
            exit(EXIT_FAILURE);
        }

    }
    else
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }
    printf("Back to exc1\n");
    return (0);
}