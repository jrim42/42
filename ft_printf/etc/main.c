#include "ft_printf.h"

int	main(void)
{
	int	len;

	// len = ft_printf("ft_printf\n");
	// ft_printf("%d\n", len);
	// printf("%u\n", -1);
	// len = ft_printf("%u\n", -1);
	// ft_printf("len = %d\n", len);
	// len = ft_printf("%c%c\n", '4', '2');
	// ft_printf("%d\n", len);
	// len = ft_printf("%s %s\n", "(not null)", 0);
	// ft_printf("%d\n", len);
	// len = ft_printf("%%x = %x\n", INT_MAX);
	// len = ft_printf("%%x = %x\n", 9);
	// len = ft_printf("%%x = %x\n", -9);
	// len = ft_printf("%%x = %x\n", -99);
	// len = ft_printf("%%x = %x\n", -100);
	// printf("--------------------\n");
	// printf("%%x = %x\n", 9);
	// printf("%%x = %x\n", -9);
	ft_printf("%%p = %p\n", (void *)0);
	ft_printf("%%p = %p\n", (void *)-1);
	len = printf("%%p = %p\n", (void *)-1);
	// printf("%%p = %p\n", (void *)10);
	// printf("%%p = %p\n", (void *)INT_MIN);
	// printf("%%p = %p\n", (void *)INT_MAX);
	// printf("%%p = %p\n", (void *)LONG_MIN);
	// printf("%%p = %p\n", (void *)LONG_MAX);
	// printf("%%x = %x\n", -99);
	// printf("%%x = %x\n", -100);
	// ft_printf("len = %d\n", len);
	// len = ft_printf("%x = %X\n", -255, -255);
	// ft_printf("len = %d\n", len);
}