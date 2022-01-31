#ifndef DLL_STACK_H
# define DLL_STACK_H

# include <stdio.h>
# include <stdlib.h>

typedef struct      s_node
{
    int             data;
    struct s_node   *prev;
    struct s_node   *next;
}                   t_node;

typedef struct  s_stack
{
    int         size;
    t_node      *top;
}               t_stack;

void    stk_init(t_stack **stk);
t_node  *nd_init(int num);
void    stk_push(t_stack *stk, t_node *new_top);
t_node  *stk_pop(t_stack *stk);
void    stk_swap(t_stack *stk);
void    stk_rotate(t_stack *stk);
void    stk_rev_rotate(t_stack *stk);
void    stk_display_all(t_stack *stk_a, t_stack *stk_b);

void    stk_display_one(t_stack *stk);
void    data_swap(int *a, int *b);
void    stk_quicksort(t_stack *stk, t_node *head, t_node *tail, int left, int right);

#endif
