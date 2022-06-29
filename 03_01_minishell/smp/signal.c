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
    printf("ctrl + c print a new prompt on a newline\n");
}

void h_QUIT(int signum)
{
    if (signum != SIGQUIT)
        return;
    printf("ctrl + \\ do nothing\n");
}


int main(void)
{
    char *line;

    signal(SIGINT, h_INT);      // ctrl + c
    signal(SIGQUIT, h_QUIT);    // ctrl + '\'
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
            printf("\b\bctrl + d exit the shell\n");
            break;
        }
    }
    return (0);
}