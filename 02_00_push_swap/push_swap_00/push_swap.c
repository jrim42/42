#include "push_swap.h"

void    push_swap(int argc, char **argv);

void    push_swap(int argc, char **argv)
{
    t_stack *stk_a;
    t_stack *stk_b;

    stk_init(&stk_a);
    stk_a->name = 'a';
    stk_init(&stk_b);
    stk_a->name = 'b';
    stk_fill(stk_a, argc, argv);
    stk_display_all(stk_a, stk_b);
    // size == 1 일때는 개행만 출력
    if (stk_a->size == 3)
        printf("stk_sort_3\n");
    else if (stk_a->size == 5)
        printf("stk_sort_5\n");
    else
        stk_quicksort(stk_a, stk_a->top, stk_a->top->prev, 0, stk_a->size - 1);
    stk_display_all(stk_a, stk_b);
    //free?
}
