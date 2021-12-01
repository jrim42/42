#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int         num;
    long long   ll_num;
    char    *str;

    str = (char *)calloc(10, sizeof(char));
    num = printf("%p\n", str);
    free(str);
    num = printf("%p\n", str);
    printf("num : %d\n\n", num);
    num = printf("%10.d\n", 123);
    printf("num : %d\n", num);
    num = printf("%d\n", 2147483647);
    printf("num : %d\n", num);
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
    num = printf("%x\n", 0x123);
    printf("num : %d\n", num);
    printf("%X\n", 255);
    printf("%X\n", -2147483647);
    printf("%X\n", -255);
    num = -1;
    printf("%X\n", num);
    ll_num = num + 4294967295 + 1;
    printf("%llX\n", ll_num);
    printf("%d\n", 0XFFFFFF01);
    printf("%d\n", 0XFFFFFFFF);
}