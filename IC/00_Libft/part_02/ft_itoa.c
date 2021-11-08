#include "libft.h"

int numlen(int n)
{
    int len;

    len = 0;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    int     sign;
    int     total_len;
    char    *str;
    int     idx;

    if (n < 0)
        sign = 1;
    else
        sign = 0;
    total_len = sign + numlen(n) + 1;
    str = (char *)malloc(total_len * sizeof(char));
    if (!(str))
        return (0);
    idx = total_len - 1;
    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    while (n > 0)
    {
        str[idx--] = n % 10;
        n /= 10;
    }
    return (str);
}