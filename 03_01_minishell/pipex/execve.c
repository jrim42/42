#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *envp[] = {0};
    int a;
    
    a = open("file1", O_WRONLY);
    dup2(a, STDOUT_FILENO);
    execve("/bin/ls", argv, envp);
    return (0);
}