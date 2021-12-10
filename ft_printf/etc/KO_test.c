#include "ft_printf.h"

int main(void)
{
    int len;

    // len = printf("|%d|\n", INT_MAX) - 3;
    // printf("len : %d\n", len);
	// len = printf("|%d|\n", INT_MIN) - 3;
    // printf("len : %d\n", len);
	// len = printf("|%d|\n", LONG_MAX) - 3;
    // printf("len : %d\n", len);
	len = printf("|%d|\n", LONG_MIN) - 3;
    printf("len : %d\n", len);
	// len = printf("|%d|\n", UINT_MAX) - 3;
    // printf("len : %d\n", len);
	// len = printf("|%d|\n", ULONG_MAX) - 3;
    // printf("len : %d\n", len);
	// len = printf("|%d|\n", 9223372036854775807LL) - 3;
    // printf("len : %d\n", len);
    len = printf("|%d %d %d %d %d %d %d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42) - 3;
    printf("len : %d\n", len);

    // len = ft_printf("|%d|\n", INT_MAX) - 3;
    // printf("len : %d\n", len);
	// len = ft_printf("|%d|\n", INT_MIN) - 3;
    // printf("len : %d\n", len);
	// len = ft_printf("|%d|\n", LONG_MAX) - 3;
    // printf("len : %d\n", len);
	len = ft_printf("|%d|\n", LONG_MIN) - 3;
    printf("len : %d\n", len);
	// len = ft_printf("|%d|\n", UINT_MAX) - 3;
    // printf("len : %d\n", len);
	// len = ft_printf("|%d|\n", ULONG_MAX) - 3;
    // printf("len : %d\n", len);
	// len = ft_printf("|%d|\n", 9223372036854775807LL) - 3;
    // printf("len : %d\n", len);
    len = ft_printf("|%d %d %d %d %d %d %d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42) - 3;
    printf("len : %d\n", len);
}