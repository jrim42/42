#include <stdio.h>

int main(void)
{
    int num;

    num = printf("%d\n", 123);
    printf("num : %d\n", num);
    num = printf("%s\n", "apple");
    printf("num : %d\n", num);
    num = printf("%%\n");
    printf("num : %d\n", num);
    printf("%x\n", 2147483647);
    printf("%X\n", 255);
}