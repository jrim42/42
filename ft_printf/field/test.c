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

    // printf("---------- width ----------\n");
    // printf("%*d\n", 5, 42);
    // printf("%*d\n", -5, 42);
    // printf("%-*d\n", 5, 42);
    // printf("%*d\n", 5, 42);
    // printf("%5d\n", 42);
    // printf("%-5d\n", 42);
    // printf("%0*d\n", -5, 42);
    // printf("%0*d\n", 5, 42);
    // printf("%03d\n", 1);
    // printf("%-3d\n", 1);
    // printf("---------------------------\n");

//--------------------------------------------//

    // printf("-------- precision --------\n");
    // printf("%5s\n", "abcd");
    // printf("%3s\n", "abcd");
    // printf("%3c\n", 'a');
    // printf("%03.d\n", 10);
	// printf("%03.i\n", 10);
	// printf("%03.u\n", 10);
    // printf("%03.d\n", -10);
	// printf("%03.i\n", -10);
	// printf("%03.u\n", -10);
	// printf("%#03.x\n", 10);
	// printf("%#03.X\n", 10);
    // printf("---------------------------\n");


    printf("-------- char/str ---------\n");
    printf("%10s\n", "abcd");
    printf("%3s\n", "abcd");
    printf("%-10s\n", "abcd");
    printf("%-3s\n", "abcd");
    printf("%.10s\n", "abcd");
    printf("%.3s\n", "abcd");
    printf("%.3s\n", "abcd");
    printf("---------------------------\n");
}