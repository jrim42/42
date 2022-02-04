#include "push_swap.h"

void    push_swap(int argc, char **argv);

void    push_swap(int argc, char **argv)
{
    t_stack *stk_a;
    t_stack *stk_b;

    stk_init(&stk_a);
    stk_init(&stk_b);
    stk_fill(stk_a, argc, argv);
    stk_display_all(stk_a, stk_b);
    stk_quicksort(stk_a, stk_a->top, stk_a->top->prev, 0, stk_a->size - 1);
    stk_display_all(stk_a, stk_b);
}
