#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pipefd1[2];
    int pipefd2[2];
    int pipefd3[2];

    pipe(pipefd1);
    pipe(pipefd2);
    pipe(pipefd3);
    printf("%d %d\n", pipefd1[0], pipefd1[1]);
    printf("%d %d\n", pipefd2[0], pipefd2[1]);
    printf("%d %d\n", pipefd3[0], pipefd3[1]);
}