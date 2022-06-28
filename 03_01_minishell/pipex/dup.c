#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int file1_fd;
    int file2_fd;
    int alpha;

    file1_fd = open("file1", O_WRONLY);
    file2_fd = open("file2", O_WRONLY);
    
    printf("%d %d\n", file1_fd, file2_fd);
    dup2(file1_fd, file2_fd);
    printf("%d %d\n", file1_fd, file2_fd);
    alpha = dup(file1_fd);
    // close(file1_fd);

    write(file2_fd, "HI", 2);
    write(alpha, "from alpha", 10);
    printf("%d\n", alpha);
    return (0);    
}
