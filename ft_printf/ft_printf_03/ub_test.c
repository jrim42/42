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

    printf("-----------------------------\n");

    len = printf("|%10.3d|\n", -12345) - 3;
    printf("len : %d\n", len);
    len = printf("|%10.7d|\n", -12345) - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%10.3d|\n", -12345) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%10.7d|\n", -12345) - 3;
    printf("len : %d\n", len);

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

    len = printf("|%-010.1s|\n", "abc") - 3;
    printf("len : %d\n", len);
    len = printf("|%-010.3s|\n", "abc") - 3;
    printf("len : %d\n", len);
    len = printf("|%-010.5s|\n", "abc") - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%-010.1s|\n", "abc") - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%-010.3s|\n", "abc") - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%-010.5s|\n", "abc") - 3;
    printf("len : %d\n", len);

    printf("-----------------------------\n");

    len = printf("|%04d|\n", 9) - 3;
    printf("len : %d\n", len);
    len = printf("|%03d|\n", 15) - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%04d|\n", 9) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%03d|\n", 15) - 3;
    printf("len : %d\n", len);

    printf("-----------------------------\n");

    len = printf("|%04d|\n", -9) - 3;
    printf("len : %d\n", len);
    len = printf("|%03d|\n", -15) - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%04d|\n", -9) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%03d|\n", -15) - 3;
    printf("len : %d\n", len);

    printf("-----------------------------\n");

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

    len = printf("|%04x|\n", 9) - 3;
    printf("len : %d\n", len);
    len = printf("|%01x|\n", 10) - 3;
    printf("len : %d\n", len);

    printf("\n");

    len = ft_printf("|%04x|\n", 9) - 3;
    printf("len : %d\n", len);
    len = ft_printf("|%01x|\n", 10) - 3;
    printf("len : %d\n", len);

    printf("-----------------------------\n");
}