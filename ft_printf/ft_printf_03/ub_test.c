#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int len;

    // len = printf("|%.d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = printf("|%.1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    len = printf("|%-10.3d|\n", -12345) - 3;
    printf("len : %d\n", len);
    // len = printf("|%.5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    len = printf("|%-10.7d|\n", -12345) - 3;
    printf("len : %d\n", len);

    // printf("\n");

    // // len = printf("|% .d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // // len = printf("|% .1d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = printf("|% .3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // // len = printf("|% .5d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = printf("|% .7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // // len = printf("|%+.d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // // len = printf("|%+.1d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = printf("|%+.3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // // len = printf("|%+.5d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = printf("|%+.7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // // len = printf("|%.d|\n", -12345) - 3;
    // // printf("len : %d\n", len);
    // // len = printf("|%.1d|\n", -12345) - 3;
    // // printf("len : %d\n", len);
    // len = printf("|%.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // // len = printf("|%.5d|\n", -12345) - 3;
    // // printf("len : %d\n", len);
    // len = printf("|%.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    printf("-----------------------------\n");

    // len = ft_printf("|%.d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // len = ft_printf("|%.1d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    len = ft_printf("|%-10.3d|\n", -12345) - 3;
    printf("len : %d\n", len);
    // len = ft_printf("|%.5d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    len = ft_printf("|%-10.7d|\n", -12345) - 3;
    printf("len : %d\n", len);

    // printf("\n");

    // // len = ft_printf("|% .d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // // len = ft_printf("|% .1d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = ft_printf("|% .3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // // len = ft_printf("|% .5d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = ft_printf("|% .7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // // len = ft_printf("|%+.d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // // len = ft_printf("|%+.1d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = ft_printf("|%+.3d|\n", 12345) - 3;
    // printf("len : %d\n", len);
    // // len = ft_printf("|%+.5d|\n", 12345) - 3;
    // // printf("len : %d\n", len);
    // len = ft_printf("|%+.7d|\n", 12345) - 3;
    // printf("len : %d\n", len);

    // printf("\n");

    // // len = ft_printf("|%.d|\n", -12345) - 3;
    // // printf("len : %d\n", len);
    // // len = ft_printf("|%.1d|\n", -12345) - 3;
    // // printf("len : %d\n", len);
    // len = ft_printf("|%.3d|\n", -12345) - 3;
    // printf("len : %d\n", len);
    // // len = ft_printf("|%.5d|\n", -12345) - 3;
    // // printf("len : %d\n", len);
    // len = ft_printf("|%.7d|\n", -12345) - 3;
    // printf("len : %d\n", len);

    printf("-----------------------------\n");

    len = printf("|%10.1p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = printf("|%10.3p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = printf("|%10.5p|\n", (void *)255) - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%10.1p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%10.3p|\n", (void *)255) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%10.5p|\n", (void *)255) - 3;
    printf("len : %d\n", len);

}