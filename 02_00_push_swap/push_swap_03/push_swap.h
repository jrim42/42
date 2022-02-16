/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:42:07 by jrim              #+#    #+#             */
/*   Updated: 2022/02/16 15:17:05 by jrim             ###   ########.fr       */
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

typedef struct s_stk
{
	int		size;
	t_node	*top;
}			t_stk;

typedef struct s_piv
{
	int	b_piv;
	int	s_piv;
}		t_piv;

typedef struct s_elm
{
	t_stk		*a;
	t_stk		*b;
	t_stk		*cmdlst;
	t_piv		*piv;
}				t_elm;

//push_swap.c
void	push_swap(int argc, char **argv);

// _input.c
void	stk_fill(t_stk *stk, int argc, char **argv);
int		check_num(char **input);
int		check_dup(t_stk *stk);
void	err_exit(void);

// _stack.c
void	stk_init(t_stk **stk);
t_node	*nd_init(int num);
void	stk_push(t_stk *stk, t_node *new_top);
t_node	*stk_pop(t_stk *stk);

// _cmds.c
void	cmd_swap(int new_cmd, t_elm *elm, int *cmd_cnt);
void	cmd_push(int new_cmd, t_elm *elm, int *cmd_cnt);
void	cmd_rotate(int new_cmd, t_elm *elm, int *cmd_cnt);
void	cmd_rev_rotate(int new_cmd, t_elm *elm);

// _cmds_utils.c
void	cmd_display_all(t_stk *cmd_lst);
void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt);
void	rr_cleaner(t_elm *elm, int new_cmd);

// _pivot.c
void	piv_select(t_stk *stk, int size, t_piv *piv);
void	arr_fill(t_stk *stk, int *arr, int size);
void	arr_quicksort(int *arr, int start, int end);

// _sort.c
void	stk_a2b(t_elm *elm, t_piv *piv, int size);
void	stk_b2a(t_elm *elm, t_piv *piv, int size);
void	sort_2(t_elm *elm, t_stk *stk);
void	sort_3(t_elm *elm, t_stk *stk);

// _sort_helper.c
int		a2b_helper(t_elm *elm, int size);
int		b2a_helper(t_elm *elm, int size);

// _sort_utils.c
void	det_init(t_piv *piv, int *cnt_1, int *cnt_2, int *cnt_3);
int		is_sorted(t_stk *stk, int size);
int		is_rev_sorted(t_stk *stk, int size);
int		stk_min(t_stk *stk, int size);
int		stk_max(t_stk *stk, int size);

// unnecessary.c
void	cmd_display_one(int cmd);
void	stk_display_all(t_stk *stk_a, t_stk *stk_b);
void	data_swap(int *a, int *b);

#endif
