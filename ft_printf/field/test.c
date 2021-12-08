#include <stdio.h>
#include <limits.h>

int main(void)
{
    int len;
    // printf("---------------------------\n");
    // printf("%d\n", 2147483648);
    // printf("%i\n", 2147483648);
    // printf("%d\n", LONG_MAX - 2147483647);
    // printf("---------------------------\n");
    //len = printf("%#d", 1);
    //printf("\n%d\n", len);
    // printf("%+d\n", -1);
    // printf("%05c\n", 'c');
    // printf("%05s\n", "str");

//--------------------------------------------//

    // printf("---------- flags ----------\n");
    // printf("%x\n", 10);
    // printf("%d\n", -10);
    // printf("%#x\n", -10);
    // // printf("%#d\n", 0x5);
    // printf("%#x\n", 10);
    // printf("%#X\n", 10);
    // printf("---------------------------\n");

//--------------------------------------------//

    printf("---------- width ----------\n");
    printf("%*d\n", 5, 42);
    printf("%*d\n", -5, 42);
    printf("%-*d\n", 5, 42);
    printf("%*d\n", 5, 42);
    printf("%5d\n", 42);
    printf("%-5d\n", 42);
    printf("%0*d\n", -5, 42);
    printf("%0*d\n", 5, 42);
    printf("%03d\n", 1);
    printf("%-3d\n", 1);
    printf("---------------------------\n");

//--------------------------------------------//

    printf("-------- precision --------\n");
    printf("%.c\n", 'a');
	printf("%.5c\n", 'a');
	printf("%.p\n", 10);
    printf("%.5p\n", 10);
	printf("%.s\n", "abc");
    printf("%.2s\n", "abc");
	printf("%.5s\n", "abc");
    printf("---------------------------\n");


    // printf("-------- char/str ---------\n");
    // printf("%10s\n", "abcd");
    // printf("%3s\n", "abcd");
    // printf("%-10s\n", "abcd");
    // printf("%-3s\n", "abcd");
    // printf("%.10s\n", "abcd");
    // printf("%.3s\n", "abcd");
    // printf("%.3s\n", "abcd");
    // printf("---------------------------\n");
}