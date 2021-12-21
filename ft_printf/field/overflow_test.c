#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    long long len;

    // printf("%d\n", ft_atoi("2147483648"));
    // printf("%d\n", ft_atoi("4294967295"));
    // printf("%d\n", ft_atoi("-2147483649"));
    // printf("%d\n", ft_atoi("-4294967295"));

    // len = printf("%2147483647");
    // printf("len : %lld\n", len);
    // len = printf("%4294967295");
    // printf("len : %lld\n", len);
    // len = printf("%-2147483649");
    // printf("len : %lld\n", len);
    // len = printf("%-4294967295");
    // printf("len : %lld\n", len);

    // len = printf("%2147483647d", 0);
    // printf("len : %lld\n", len);
    // len = printf("%4294967295d", 0);
    // printf("len : %lld\n", len);
    // len = printf("%-2147483649d", 0);
    // printf("len : %lld\n", len);
    // len = printf("%-4294967295d", 0);
    // printf("len : %lld\n", len);

    // len = printf("%2147483647");
    // printf("len = %lld\n", len);
    // len = printf("%-2147483647");
    // printf("len = %lld\n", len);
    // printf("----------\n");
    // len = printf("%2147483647c", 'A');
    // printf("len = %lld\n", len);
    // len = printf("%-2147483647c", 'A');
    // printf("len = %lld\n", len);
    // len = printf("%2147483647d", 1);
    // printf("len = %lld\n", len);
    // len = printf("%-2147483647d", 1);
    // printf("len = %lld\n", len);
    // printf("----------\n");
    // len = printf("%2147483647m");
    // printf("len = %lld\n", len);
    // len = printf("%-2147483647m");
    // printf("len = %lld\n", len);
    // len = printf("%2147483647mmm");
    // printf("len = %lld\n", len);
    // len = printf("%-2147483647mmm");
    // printf("len = %lld\n", len);

    // printf("----------\n");

    // len = ft_printf("%2147483647");
    // printf("len = %lld\n", len);
    // len = ft_printf("%-2147483647");
    // printf("len = %lld\n", len);
    // printf("----------\n");
    // len = ft_printf("%2147483647c", 'A');
    // printf("len = %lld\n", len);
    // len = ft_printf("%-2147483647c", 'A');
    // printf("len = %lld\n", len);
    // len = ft_printf("%2147483647d", 1);
    // printf("len = %lld\n", len);
    // len = ft_printf("%-2147483647d", 1);
    // printf("len = %lld\n", len);
    // printf("----------\n");
    // len = ft_printf("%2147483647m");
    // printf("len = %lld\n", len);
    // len = ft_printf("%-2147483647m");
    // printf("len = %lld\n", len);
    // len = ft_printf("%2147483647mmm");
    // printf("len = %lld\n", len);
    // len = ft_printf("%-2147483647mmm");
    // printf("len = %lld\n", len);

    // printf("----------\n");

    // len = printf("%2147483647c %c", 'A', 'B');
    // printf("len = %lld\n", len);
    // len = ft_printf("%2147483647c %c", 'A', 'B');
    // printf("len = %lld\n", len);

    // printf("----------\n");
    printf("----------\n");

    len = printf("%.2147483647");
    printf("len = %lld\n", len);
    len = printf("%.2147483648");
    printf("len = %lld\n", len);
    printf("----------\n");
    len = printf("%2147483647c", 'A');
    printf("len = %lld\n", len);
    len = printf("%2147483647d", 1);
    printf("len = %lld\n", len);
    printf("----------\n");
    len = printf("%.2147483647m");
    printf("len = %lld\n", len);
    len = printf("%.2147483647mmm");
    printf("len = %lld\n", len);
    len = printf("%05mmm");
    printf("\nlen = %lld\n", len);

    printf("----------\n");
    printf("----------\n");

    len = ft_printf("%.2147483647");
    printf("len = %lld\n", len);
    len = ft_printf("%.2147483648");
    printf("len = %lld\n", len);
    printf("----------\n");
    len = ft_printf("%2147483647c", 'A');
    printf("len = %lld\n", len);
    len = ft_printf("%2147483647d", 1);
    printf("len = %lld\n", len);
    printf("----------\n");
    len = ft_printf("%.2147483647m");
    printf("len = %lld\n", len);
    len = ft_printf("%.2147483647mmm");
    printf("len = %lld\n", len);
    len = ft_printf("%05mmm");
    printf("\nlen = %lld\n", len);

    printf("----------\n");
    printf("----------\n");

    len = printf("%5.3m %5.3d\n", 42);
    printf("len = %lld\n", len);
    len = ft_printf("%5.3m %5.3d\n", 42);
    printf("len = %lld\n", len);

    printf("----------\n");

    len = printf("m%2147483647m");
    printf("len = %lld\n", len);
    len = ft_printf("m%2147483647m");
    printf("len = %lld\n", len);
}

