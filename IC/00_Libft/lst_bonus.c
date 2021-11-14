#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (0);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if (*lst == NULL)
        (*lst)->next = new;
    else
    {
        new->next = (*lst)->next;
        (*lst)->next = new;
    }
}

int     ft_lstsize(t_list *lst)
{
    t_list  *tmp;
    int     size;

    tmp = lst;
    size = 0;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *tmp;

    tmp = lst;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
            break ;
    }
    return (tmp);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;
    
    if (*lst == NULL)
        (*lst)->next = new;
    else
    {
        tmp = *lst;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new; //뭔가 더 해줘야할 것 같은데?
    }
}

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!(lst->content))
    {
        del(lst->content);
        free(lst->content);
    }
}

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *tmp;

    tmp = (*lst);
    while ((*lst)->next != NULL)
    {
        del(tmp->content);
        free(tmp);
        (*lst) = tmp->next;
        tmp = (*lst);
    }
}

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (lst == 0 || f == 0)
        return (0);
    f(lst->content);
}

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *tmp;

    if (lst == 0 || f == 0)
        return (0);
    new_lst = ft_lstnew(f(lst->content));
    tmp = lst;
    lst = lst->next;
    while (lst->next != NULL)
    {
        tmp->next = ft_lstnew((*f)(lst->content));
        if (!(tmp->next))
        {
            ft_lstclear(&new_lst, del);
            return (0);
        }
        // 하나라도 allocation fail 있을 시에 
        // 앞에 할당해 주었던 것 까지 전부 해제해 준 후에 return (0); 해줘야하나?
        lst = lst->next;
        tmp = tmp->next;
    }
    return (new_lst);
}