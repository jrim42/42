#include "dll_stack.h"

/*
int main(void)
{
    t_stack *stk_a;
    t_stack *stk_b;

    stk_init(&stk_a);
    stk_init(&stk_b);
    stk_push(stk_a, nd_init(3));
    stk_push(stk_a, nd_init(4));
    stk_push(stk_a, nd_init(1));
    stk_push(stk_a, nd_init(2));
    stk_push(stk_b, stk_pop(stk_a));
    stk_push(stk_b, stk_pop(stk_a));
    stk_swap(stk_a);
    stk_swap(stk_b);
    stk_push(stk_a, stk_pop(stk_b));
    stk_display_all(stk_a, stk_b);
    stk_push(stk_a, stk_pop(stk_b));
    stk_display_all(stk_a, stk_b);
    stk_rotate(stk_a);
    stk_display_all(stk_a, stk_b);
    stk_rev_rotate(stk_a);
    stk_display_all(stk_a, stk_b);
    return (0);
}
*/

int main(void)
{
    int     cnt;
    int     element;
    t_stack *stk;

    printf("array size : ");
    scanf("%d", &cnt);
    stk_init(&stk);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &element);
        stk_push(stk, nd_init(element));
    }
    stk_display_one(stk);
    stk_quicksort(stk, stk->top, stk->top->prev, 0, cnt - 1);
    stk_display_one(stk);
}