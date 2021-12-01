#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("fxxking ft_printf\n");
	ft_printf("%d\n", len);
	len = ft_printf("%u %d\n", 123, -123);
	ft_printf("%d\n", len);
	len = ft_printf("%c%c\n", '4', '2');
	ft_printf("%d\n", len);
	len = ft_printf("%s %s\n", "(not null)", 0);
	ft_printf("%d\n", len);
	len = ft_printf("%x = %X\n", -255, -255);
	ft_printf("%d\n", len);
}