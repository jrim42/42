#include "dll_stack.h"

void    stk_display_one(t_stack *stk)
{
    t_node  *tmp;
    int     size;

    tmp = stk->top;
    size = stk->size;
    printf("|");
    while (size--)
    {
        printf(" %d |", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void    data_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
void    stk_quicksort(t_stack *stk, t_node *start, t_node *end)
{
    t_node  *pivot;
    t_node  *left;
    t_node  *right;
    int     tmp;

    if (start->next == end)
        return;
    pivot = start;
    left = start->next;
    right = end;
    while (left->next != right)
    {
        while (left->data < pivot->data)
            left = left->next;
        while (right->data > pivot->data && right->prev != start)
            right = right->prev;
        if (left == right)
        {
            tmp = left->data;
            left->data = pivot->data;
            pivot->data = tmp;
        }
        else
        {
            tmp = right->data;
            right->data = left->data;
            left->data = tmp;
        }
        stk_display_one(stk);
        stk_quicksort(stk, start, right->prev);
        stk_quicksort(stk, right->next, end);
    }
}
*/

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
