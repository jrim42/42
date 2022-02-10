#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"

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

typedef struct  s_detail
{
    int         ra_cnt;
    int         pb_cnt;
    int         rb_cnt;
    int         pa_cnt;
    int         b_piv;
    int         s_piv;
}               t_detail;

//push_swap.c
void    push_swap(int argc, char **argv);
void	select_piv(t_stack *stk, int size, t_detail *detail);
int		is_rev_sorted(t_stack *stk);
int		is_sorted(t_stack *stk);

//push_swap_input.c
void    stk_fill(t_stack *stk, int argc, char **argv);
void	arr_fill(t_stack *stk, int *arr, int size);
int     check_num(char **input);
int     check_dup(t_stack *stk);
void    err_exit(void);

//push_swap_cmds.c
void    cmd_push(char *cmd, t_stack *from, t_stack* to, int *cmd_cnt);
void    cmd_swap(char *cmd, t_stack *stk, int *cmd_cnt);
void    cmd_rotate(char *cmd, t_stack *stk, int *cmd_cnt);
void    cmd_rev_rotate(char *cmd, t_stack *stk);
void	rrr_helper(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt);

//push_swap_cmds_utils.c
void    stk_init(t_stack **stk);
t_node  *nd_init(int num);
void    stk_push(t_stack *stk, t_node *new_top);
t_node  *stk_pop(t_stack *stk);

//push_swap_sort.c
void    stk_a2b(t_stack *a, t_stack *b, t_detail* info, int size);
void    stk_b2a(t_stack *a, t_stack *b, t_detail* info, int size);
void	arr_quicksort(int *arr, int start, int end);

//push_swap_sort_utils.c
void	init_detail(t_detail *detail);
void	sort_2(t_stack *stk);
int     stk_min(t_stack *stk);
int     stk_max(t_stack *stk);

//unnecessary.c
void    stk_display_all(t_stack *stk_a, t_stack *stk_b);
void    data_swap(int *a, int *b);

#endif