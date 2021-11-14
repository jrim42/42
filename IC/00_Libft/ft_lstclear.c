#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *tmp;

    if (!del || !(*lst))
        return ;
    while (tmp)
    {
        tmp = (*lst);
        (*lst) = (*lst)->next;
        ft_lstdelone(*lst, del);
    }
    (*lst) = NULL;
}