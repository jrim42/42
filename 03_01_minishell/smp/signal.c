#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void h_INT(int signum)
{
    if (signum != SIGINT)
        return;
    printf("ctrl + c\n");
    exit(0);
}

void h_QUIT(int signum)
{
    if (signum != SIGQUIT)
        return;
    printf("ctrl + \\\n");
    exit(0);
}

void h_STOP(int signum)
{
    if (signum != SIGSTOP)
        return;
    printf("ctrl + z\n");
    exit(0);
}

int main(void)
{
    char *line;

    signal(SIGINT, h_INT);
    signal(SIGQUIT, h_QUIT);
    signal(SIGSTOP, h_STOP);
    while (1)
    {
        line = readline("> ");
        if (line)
        {
            printf("> %s\n", line);
            add_history(line);
            free(line);
            line = NULL;
        }
        else
        {
            printf("exit\n");
            break;
        }
    }
    return (0);
}