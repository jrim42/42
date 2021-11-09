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
    t_list  *tmp_node;

    if (*lst == NULL)
    {
        *lst = new; // (*lst)->next = new; 둘 중에 뭐가 맞는건지 확인해보기
    }
    else
    {
        
    }
}

int     ft_lstsize(t_list *lst)
{
    t_list  *tmp_node;
    int     size;

    tmp_node = lst;
    size = 0;
    while (tmp_node->next != NULL)
    {
        tmp_node = tmp_node->next;
        size++;
    }
    return (size);
}

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *tmp_node;

    tmp_node = lst;
    while (tmp_node->next != NULL)
    {
        tmp_node = tmp_node->next;
        if (tmp_node->next == NULL)
            break ;
    }
    return (tmp_node);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp_node;
    
    if (*lst == NULL)
    {
        *lst = new;
    }
    else
    {
        tmp_node = *lst;
        while (tmp_node->next != NULL)
        {
            tmp_node = tmp_node->next;
        }
        tmp_node->next = new;
    }
}

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    
}

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    
}

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    
}

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    
}