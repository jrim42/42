#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void handler(int signum)
{
    if (signum != SIGINT)
        return;
    printf("ctrl + c\n");
    // rl_on_new_line();
    // rl_replace_line("", 1);
    // rl_redisplay();
}

int main(void)
{
    char *line;

    signal(SIGINT, handler);
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