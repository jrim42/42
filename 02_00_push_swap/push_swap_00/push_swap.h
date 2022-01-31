#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

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

//push_swap.c
void    push_swap(t_list *lst);
int     err_check(t_list *lst);

//push_swap_cmds.c
void    commands(char *cmd, t_stack *a, t_stack *b);
void    cmd_push(char *cmd, t_stack *from, t_stack* to);
void    cmd_swap(char *cmd, t_stack *stk);
void    cmd_rotate(char *cmd, t_stack *stk);
void    cmd_rev_rotate(char *cmd, t_stack *stk);

//push_swap_utils.c
void    stk_init(t_stack **stk);
t_node  *nd_init(int num);
void    stk_push(t_stack *stk, t_node *new_top);
t_node  *stk_pop(t_stack *stk);

#endif