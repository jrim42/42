#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int len;

//    // ------- zero & num ------
//     len = printf("|%01c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%01p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//    // ------- zero & num ------
//     len = printf("|%010c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%010p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//    // ------- '-' & num ------
//     len = printf("|%-10c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-10p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//    // ------ '-' & 0 & num ------
//     len = printf("|%-010c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%-010p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//    // ------ precision (1) ------
//     len = printf("|%.0c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.0p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//     // ------ precision (2) ------
//     len = printf("|%.1c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%.1p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//     //------ width & precision ------
//     len = printf("|%10.1c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.1p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);
//     printf("-----------------------------\n");
//     len = printf("|%1.10c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.10p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);
//     printf("-----------------------------\n");
//     len = printf("|%1.1c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%1.1p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);
//     printf("-----------------------------\n");
//     len = printf("|%10.10c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%10.10p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);

//     len = printf("|% 010d|\n", 42) - 3;
//     printf("    len : %d\n", len);

//     // ------ alternative form ------
//     len = printf("|%#10c|\n", 'a') - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10s|\n", "abc") - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10d|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10i|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10u|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10x|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10X|\n", 42) - 3;
//     printf("    len : %d\n", len);
//     len = printf("|%#10p|\n", (void *)42) - 3;
//     printf("    len : %d\n", len);


    len = printf("|%10.0d|\n", 12345) - 3;
    printf("len : %d\n", len);
    len = printf("|%010.0d|\n", 12345) - 3;
    printf("len : %d\n", len);
    len = printf("|%10.5d|\n", 12345) - 3;
    printf("len : %d\n", len);
    len = printf("|%010.5d|\n", 12345) - 3;
    printf("len : %d\n", len);

    len = ft_printf("|%10.0d|\n", 12345) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%010.0d|\n", 12345) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%10.5d|\n", 12345) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%010.5d|\n", 12345) - 3;
    printf("len : %d\n", len);

    len = printf("|%|\n") - 3;
    printf("len : %d\n", len);
    len = printf("|%3|\n") - 3;
    printf("len : %d\n", len);
    len = printf("|%3mno|\n") - 3;
    printf("len : %d\n", len);

    len = printf("|%*d|\n", -10, 123) - 3;
    printf("len : %d\n", len);
    len = printf("|%*d|\n", -010, 123) - 3;
    printf("len : %d\n", len);
    printf("--------------------\n");
    len = ft_printf("|%*d|\n", -10, 123) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%*d|\n", -010, 123) - 3;
    printf("len : %d\n", len);
    printf("--------------------\n");
    len = printf("|%5.10d|\n", 123) - 3;
    printf("len : %d\n", len);
    len = printf("|%5.010d|\n", 123) - 3;
    printf("len : %d\n", len);
    printf("--------------------\n");
    len = ft_printf("|%5.10d|\n", 123) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%5.010d|\n", 123) - 3;
    printf("len : %d\n", len);
    
    printf("--------------------\n");

    len = printf("|%5.+10s|\n", "123") - 3;
    printf("len : %d\n", len);
    len = printf("|%5.+010s|\n", "123") - 3;
    printf("len : %d\n", len);
    printf("--------------------\n");
    len = ft_printf("|%5.+10s|\n", "123") - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%5.+010s|\n", "123") - 3;
    printf("len : %d\n", len);

    printf("--------------------\n");

    len = printf("|%5.007s|\n", "123") - 3;
    printf("len : %d\n", len);
    printf("--------------------\n");
    len = ft_printf("|%5.007s|\n", "123") - 3;
    printf("len : %d\n", len);

    printf("--------------------\n");

    len = printf("|%5.007s|\n", "123") - 3;
    printf("len : %d\n", len);
    printf("--------------------\n");
    len = ft_printf("|%5.007s|\n", "123") - 3;
    printf("len : %d\n", len);


    printf("-----------------------------\n");

    printf("|%#10X|\n", 255);
    printf("|%#010x|\n", 255);
    printf("|%#010p|\n", (void *)255);

    ft_printf("|%#10X|\n", 255);
    ft_printf("|%#010x|\n", 255);
    ft_printf("|%#010p|\n", (void *)255);

    printf("-----------------------------\n");

    printf("-----------------------------\n");

    printf("|%+10d|\n", 255);
    printf("|%+010d|\n", 255);

    ft_printf("|%+10d|\n", 255);
    ft_printf("|%+010d|\n", 255);

    printf("% u\n", 10);
    printf("% u\n", -1);
    ft_printf("% u\n", 10);
    ft_printf("% u\n", -1);

    printf("%10.7d\n", -12345);
    ft_printf("%10.7d\n", -12345);
    printf("%010.7d\n", -12345);
    ft_printf("%010.7d\n", -12345);
    printf("%010d\n", -12345);
    ft_printf("%010d\n", -12345);
    printf("%010d\n", -12345);
    ft_printf("%010d\n", -12345);

    printf("-----------------------------\n");

    printf("%p\n", ULONG_MAX);
    ft_printf("%p\n", ULONG_MAX);
    printf("%p\n", ULLONG_MAX);
    ft_printf("%p\n", ULLONG_MAX);
    printf("%p\n", ULLONG_MAX + 1);
    ft_printf("%p\n", ULLONG_MAX + 1);

    printf("%x\n", ULONG_MAX);
    ft_printf("%x\n", ULONG_MAX);
    printf("%x\n", ULLONG_MAX);
    ft_printf("%x\n", ULLONG_MAX);
    printf("%x\n", ULLONG_MAX + 1);
    ft_printf("%x\n", ULLONG_MAX + 1);
}