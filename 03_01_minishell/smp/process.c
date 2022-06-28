#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    pid_t pid;
    
    pid = fork();
    if (pid == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("(child process is running)\n");
            sleep(1);
        }
        printf("child process is done\n");
        exit(0);  
    }
    if (pid > 0)
    {
        printf("parent process is waiting (%d)\n", pid);
        wait(NULL);
        printf("parent process is done (%d)\n", pid);
    }
    return 0;
}