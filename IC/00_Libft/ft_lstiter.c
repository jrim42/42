#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!f)
        return (0);
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}