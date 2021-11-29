#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int main(void)
{
    int num;
    char    *str = "42seoul";

    num = printf("%d\n", 123);
    printf("num : %d\n", num);
    num = printf("%%\n");
    printf("num : %d\n", num);
    num = printf("hello\n");
    printf("num : %d\n", num);
    num = printf("%s\n", "apple");
    printf("num : %d\n", num);
    num = printf("%%\n");
    printf("num : %d\n", num);
    printf("%x\n", 2147483647);
    printf("%X\n", 255);
    while (*str)
        write(1, str++, 1);
    printf("\n%\n");
}