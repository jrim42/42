#include "libft.h"

/*
int ft_isalnum(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else if (c >= '0' &&  c <= '9')
        return (1);
    return (0);
}
*/

int ft_isalnum(int c)
{
    if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
        return (1);
    return (0);
}