#include "push_swap.h"

int     err_check(t_list *lst);

void    push_swap(t_list *lst)
{
    //err_check
    if (err_check(lst) == 0)
        write(1, "Error\n", 6);
    //sort
    //display
}

int     err_check(t_list *lst)
{
    t_list  *tmp;

    while (lst)
    {
        //정수 범위 확인
        tmp = lst->next;
        while (tmp)
        {
            tmp = tmp->next;
            if (lst->content == tmp->content)
                return (0);
        }
        lst = lst->next;
    }
    return (1);
}