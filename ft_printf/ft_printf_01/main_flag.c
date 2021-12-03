#include "ft_printf.h"

int main(void)
{
    printf("%10s\n", "abcd");
    printf("%3s\n", "abcd");
    printf("%10c\n", 'a');
    printf("%3c\n", 'a');
    ft_printf("%10s\n", "abcd");
    ft_printf("%3s\n", "abcd");
    ft_printf("%10c\n", 'a');
    ft_printf("%3c\n", 'a');
}