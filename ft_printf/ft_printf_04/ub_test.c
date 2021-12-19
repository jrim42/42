#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int len;

    // len = printf("|%.d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%10.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%10.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = printf("|% .d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|% .1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|% .3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|% .5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|% .7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = printf("|%+.d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%+.1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%+.3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%+.5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%+.7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = printf("|%.d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.1d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.5d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // len = ft_printf("|%.d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%10.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%10.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|% .d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|% .1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|% .3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|% .5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|% .7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%+.d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%+.1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%+.3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%+.5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%+.7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%.d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.1d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.5d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // len = printf("|%10.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%10.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%10.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%10.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    printf("-----------------------------\n");

    len = printf("|%-10.1p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = printf("|%-10.3p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = printf("|%-10.5p|\n", (void *)255) - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%-10.1p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%-10.3p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%-10.5p|\n", (void *)255) - 3;
    printf("len : %d\n", len);

    printf("-----------------------------\n");

    // len = printf("|%-010.1s|\n", "abc") - 3;
    // printf("len : %d\n", len);
    // len = printf("|%-010.3s|\n", "abc") - 3;
    // printf("len : %d\n", len);
    // len = printf("|%-010.5s|\n", "abc") - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%-010.1s|\n", "abc") - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%-010.3s|\n", "abc") - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%-010.5s|\n", "abc") - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // len = printf("|%04d|\n", 9) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%03d|\n", 15) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%04d|\n", 9) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%03d|\n", 15) - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // len = printf("|%04d|\n", -9) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%03d|\n", -15) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%04d|\n", -9) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%03d|\n", -15) - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // len = printf("|%.2u|\n", 1) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.4u|\n", 15) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%.2u|\n", 1) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.4u|\n", 15) - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // len = printf("|%04x|\n", 9) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%01x|\n", 10) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // len = ft_printf("|%04x|\n", 9) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%01x|\n", 10) - 3;
    // printf("len : %d\n", len);

    // printf("-----------------------------\n");

    // printf("|%-010c|\n", 'a');
    // printf("|%-010s|\n", "abc");
    // printf("|%010c|\n", 'a');
    // printf("|%010s|\n", "abc");
    // printf("|%-10c|\n", 'a');
    // printf("|%-10s|\n", "abc");
    // printf("|%10c|\n", 'a');
    // printf("|%10s|\n", "abc");

    // printf("\n");

    // ft_printf("|%-010c|\n", 'a');
    // ft_printf("|%-010s|\n", "abc");
    // ft_printf("|%010c|\n", 'a');
    // ft_printf("|%010s|\n", "abc");
    // ft_printf("|%-10c|\n", 'a');
    // ft_printf("|%-10s|\n", "abc");
    // ft_printf("|%10c|\n", 'a');
    // ft_printf("|%10s|\n", "abc");

    // printf("-----------------------------\n");

    // printf("|%-4d|\n", -14);
	// printf("|%-5d|\n", -15);
	// printf("|%-6d|\n", -16);

    // ft_printf("|%-4d|\n", -14);
	// ft_printf("|%-5d|\n", -15);
	// ft_printf("|%-6d|\n", -16);

    printf("-----------------------------\n");

    printf("|% 1s|\n", "");
	ft_printf("|% 1s|\n", "");

    printf("-----------------------------\n");

    printf("|%#10X|\n", 255);
    printf("|%#010x|\n", 255);
    printf("|%#010p|\n", (void *)255);

    ft_printf("|%#10X|\n", 255);
    ft_printf("|%#010x|\n", 255);
    ft_printf("|%#010p|\n", (void *)255);

    printf("-----------------------------\n");

    len = printf("|%010.c|\n", 255);
    printf("%d\n", len);
    len = printf("|%010.3c|\n", 255);
    printf("%d\n", len);
    len = printf("|%010.5c|\n", 255);
    printf("%d\n", len);
    len = printf("|%010c|\n", 255);
    printf("%d\n", len);

    len = ft_printf("|%010.c|\n", 255);
    printf("%d\n", len);
    len = ft_printf("|%010.3c|\n", 255);
    printf("%d\n", len);
    len = ft_printf("|%010.5c|\n", 255);
    printf("%d\n", len);
    len = ft_printf("|%010c|\n", 255);
    printf("%d\n", len);

    printf("-----------------------------\n");

    // len = printf("|%10k|\n") - 3;
    // printf("%d\n", len);
    // printf("|%k10|\n");
    // printf("|%#.10m|\n");

    // // ft_printf("|%10k|\n");
    // // // ft_printf("|%#10|\n");
    // // //  printf("|%#.10m|\n");

    // printf("|%-010c|\n", 0);

    len = printf("|%010%|\n");
    printf("%d\n", len);
    len = printf("|%-010%|\n");
    printf("%d\n", len);
    
    len = printf("|%10.5d|\n", -256);
    printf("%d\n", len);
    len = printf("|%010.5d|\n", -256);
    printf("%d\n", len);
    len = printf("|%-010.5d|\n", -256);
    printf("%d\n", len);
}