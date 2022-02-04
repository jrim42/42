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
    char        name;
    t_node      *top;
}               t_stack;

// typedef struct       s_stk
// {
//     struct s_stack   *a;
//     struct s_stack   *b;
// }                    t_stk;

//push_swap.c
void    push_swap(int argc, char **argv);

//push_swaP_input.c
void    stk_fill(t_stack *stk, int argc, char **argv);
int     check_num(char **input);
int     check_dup(t_stack *stk);
void    err_exit(void);

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

//push_swap_sort.c
int     stk_min(t_stack *stk);
int     stk_max(t_stack *stk);
void    stk_quicksort(t_stack *stk, t_node *head, t_node *tail, int left, int right);

//unnecessary.c
void    stk_display_all(t_stack *stk_a, t_stack *stk_b);
void    data_swap(int *a, int *b);

#endif