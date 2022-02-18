/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:42:07 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 20:14:14 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}			t_stack;

typedef struct s_pivot
{
	int	b_piv;
	int	s_piv;
}		t_pivot;

//push_swap.c
void	push_swap(int argc, char **argv);

// _input.c
void	stk_fill(t_stack *stk, int argc, char **argv);
int		check_num(char **input);
int		check_dup(t_stack *stk);
void	err_exit(void);

// _stack.c
void	stk_init(t_stack **stk);
t_node	*nd_init(int num);
void	stk_push(t_stack *stk, t_node *new_top);
t_node	*stk_pop(t_stack *stk);

// _cmds.c
void	cmd_push(char *cmd, t_stack *from, t_stack *to, int *cmd_cnt);
void	cmd_swap(char *cmd, t_stack *stk, int *cmd_cnt);
void	cmd_rotate(char *cmd, t_stack *stk, int *cmd_cnt);
void	cmd_rev_rotate(char *cmd, t_stack *stk);

// _cmds_utils.c
void	rrr_helper(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt);

// _pivot.c
void	select_piv(t_stack *stk, int size, t_pivot *piv);
void	arr_fill(t_stack *stk, int *arr, int size);
void	arr_quicksort(int *arr, int start, int end);

// _sort.c
void	stk_a2b(t_stack *a, t_stack *b, t_pivot *piv, int size);
void	stk_b2a(t_stack *a, t_stack *b, t_pivot *piv, int size);
void	sort_2(t_stack *stk);
void	sort_3(t_stack *stk);

// _sort_helper.c
int 	a2b_helper(t_stack *a, t_stack *b, int size);
int 	b2a_helper(t_stack *a, t_stack *b, int size);

// _sort_utils.c
void	init_detail(t_pivot *piv, int *cnt_1, int *cnt_2, int *cnt_3);
int		is_sorted(t_stack *stk, int size);
int		is_rev_sorted(t_stack *stk, int size);
int		stk_min(t_stack *stk, int size);
int		stk_max(t_stack *stk, int size);

// unnecessary.c
void	stk_display_all(t_stack *stk_a, t_stack *stk_b);
void	data_swap(int *a, int *b);

#endif