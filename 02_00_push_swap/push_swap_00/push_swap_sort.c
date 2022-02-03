#include "push_swap.h"

int     stk_min(t_stack *stk);
int     stk_max(t_stack *stk);
void    stk_quicksort(t_stack *stk, t_node *head, t_node *tail, int left, int right);

int stk_min(t_stack *stk)
{
    int     min;
    t_node *tmp;
    
    min = 2147483647;
    tmp = stk->top;
    while (tmp)
    {
        if (tmp->data < min)
            min = tmp->data;
        tmp = tmp->next;
    }
    return (min);
}

int stk_max(t_stack *stk)
{
    int max;
    t_node *tmp;

    max = -2147483648;
    tmp = stk->top;
    while (tmp)
    {
        if (tmp->data > max)
            max = tmp->data;
        tmp = tmp->next;
    }
    return (0);
}

void    stk_quicksort(t_stack *stk, t_node *head, t_node *tail, int left, int right)
{
    int     l_cnt;
    int     r_cnt;
    t_node  *l_node;
    t_node  *r_node;

    if (left >= right)
        return ;
    l_cnt = left;
    r_cnt = right;
    l_node = head->next;
    r_node = tail;
    while (l_cnt < r_cnt)
    {
        while (l_node->data < head->data && l_cnt <= right)
        {
            l_node = l_node->next;
            l_cnt++;
        }
        while (r_node->data > head->data && r_cnt > left)
        {
            r_node = r_node->prev;
            r_cnt--;
        }
        if (l_cnt < r_cnt)
            data_swap(&(l_node->data), &(r_node->data));
        else
            data_swap(&(head->data), &(r_node->data));
    }
    stk_quicksort(stk, head, r_node->prev, left, r_cnt - 1);
    stk_quicksort(stk, r_node->next, tail, r_cnt + 1, right);
}
