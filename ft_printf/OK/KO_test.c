#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("---- %%d and prec ----\n");
    printf("%.0d\n", 0);
    printf("%.d\n", 0);
    printf("%.1d\n", 0);
    printf("Bla %.2di bla %.5dsbla bla %.dx bla %.d\n", 127, 42, 1023, 0);
    printf("%.4d%.2d%.20d%.0d%.0d%.d%.d%.d\n", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);
    printf("----------------------\n");
    ft_printf("%.0d\n", 0);
    ft_printf("%.d\n", 0);
    ft_printf("%.1d\n", 0);
    ft_printf("Bla %.2di bla %.5dsbla bla %.dx bla %.d\n", 127, 42, 1023, 0);
    ft_printf("%.4d%.2d%.20d%.0d%.0d%.d%.d%.d\n", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);

    printf("---- %%x and prec ----\n");
    printf("%.0x\n", 0);
    printf("%.x\n", 0);
    printf("%.1x\n", 0);
    printf("----------------------\n");
    ft_printf("%.0x\n", 0);
    ft_printf("%.x\n", 0);
    ft_printf("%.1x\n", 0);

    printf("---- %%p and prec ----\n");
    printf("%.0p\n", 0);
    printf("%.p\n", 0);
    printf("%.1p\n", 0);
    printf("----------------------\n");
    ft_printf("%.0p\n", 0);
    ft_printf("%.p\n", 0);
    ft_printf("%.1p\n", 0);
}