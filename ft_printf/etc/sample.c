#include "../ft_printf.h"

int ft_printf(const char *form, ...);
int print_int(va_list ap);
int print_uns(va_list ap);

int	main(void)
{
	int	len;

	len = ft_printf("%d %u", 123, 2147483648);
	printf("\n%d\n", len);
}

int ft_printf(const char *form, ...)
{
	va_list ap;
	int		len;

	va_start(ap, form);
	len = print_int(ap);
	len += print_uns(ap);
	va_end(ap);
	return (len);
}

int print_int(va_list ap)
{
    int     num;
    int     len;
    char    *str;

    num = va_arg(ap, unsigned int);
    str = ft_itoa(num);
    len = ft_strlen(str);
    write(1, str, len);
    return (len);
}

int print_uns(va_list ap)
{
    long long   num;
    int         len;
    char        *str;

    num = va_arg(ap, int);
    if (num < 0)
        num = num + UINT_MAX + 1;
    str = ft_itoa(num);
    len = ft_strlen(str);
    write(1, str, len);
    return (len);
}