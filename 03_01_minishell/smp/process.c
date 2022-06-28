#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
    {
        printf("fork() error\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("CPID : %d\n", getpid());
        for (int i = 0; i < 3; i++)
        {
            printf("(child process is running)\n");
            sleep(1);
        }
        printf("child process is done\n");
        exit(0);  
    }
    else if (pid > 0)
    {
        printf("PPID : %d\n", getpid());
        printf("parent process is waiting for %d\n", pid);
        wait(NULL); // 부모프로세스에서만 사용이 가능합니다.
        printf("parent process is done\n");
    }
    return 0;
}