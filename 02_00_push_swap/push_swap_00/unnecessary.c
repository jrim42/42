#include "push_swap.h"

void    stk_display_all(t_stack *stk_a, t_stack *stk_b);

void    stk_display_all(t_stack *stk_a, t_stack *stk_b)
{
    t_node  *tmp_a;
    t_node  *tmp_b;
    int     size_a;
    int     size_b;

    tmp_a = stk_a->top;
    size_a = stk_a->size;
    tmp_b = stk_b->top;
    size_b = stk_b->size;
    printf(" a |");
    while (size_a--)
    {
        printf(" %d |", tmp_a->data);
        tmp_a = tmp_a->next;
    }
    printf("\n");
    printf(" b |");
    while (size_b--)
    {
        printf(" %d |", tmp_b->data);
        tmp_b = tmp_b->next;
    }
    printf("\n");
}