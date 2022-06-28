#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int fd1[2];
    int fd2[2];
    char buffer[BUFSIZE];
    pid_t pid;

    if(pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        printf("pipe error");
        exit(1);
    }

    pid = fork();

    if (pid == -1)
    {
        printf("fork() error");
        exit(1);
    }
    if (pid == 0)
    {
        write(fd1[1], "(자식에서 입력)\n", 25);
        read(fd2[0], buffer, 25);
        printf("\n자식출력: %s\n", buffer);

    }
    else
    {
        write(fd2[1], "(부모에서 입력)", 25);
        read(fd1[0], buffer, BUFSIZE);
        printf("\n부모출력: %s\n", buffer);
    }
    return (0);
}