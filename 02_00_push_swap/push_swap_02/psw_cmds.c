/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:40:29 by jrim              #+#    #+#             */
/*   Updated: 2022/02/10 23:37:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_push(char *cmd, t_stack *from, t_stack *to, int *cmd_cnt);
void	cmd_swap(char *cmd, t_stack *stk, int *cmd_cnt);
void	cmd_rotate(char *cmd, t_stack *stk, int *cmd_cnt);
void	cmd_rev_rotate(char *cmd, t_stack *stk);
void	rrr_helper(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt);

void	cmd_push(char *cmd, t_stack *from, t_stack *to, int *cmd_cnt)
{
	stk_push(to, stk_pop(from));
	write(1, cmd, 2);
	write(1, "\n", 1);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_swap(char *cmd, t_stack *stk, int *cmd_cnt)
{
	t_node	*cur_top;
	int		tmp;

	cur_top = stk->top;
	if (cur_top && cur_top->next)
	{
		tmp = cur_top->data;
		cur_top->data = cur_top->next->data;
		cur_top->next->data = tmp;
	}
	if (cmd == NULL)
		return ;
	write(1, cmd, 2);
	write(1, "\n", 1);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rotate(char *cmd, t_stack *stk, int *cmd_cnt)
{
	t_node	*cur_top;

	cur_top = stk->top;
	stk->top = cur_top->next;
	if (cmd == NULL)
		return ;
	write(1, cmd, 2);
	write(1, "\n", 1);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rev_rotate(char *cmd, t_stack *stk)
{
	t_node	*cur_top;

	cur_top = stk->top;
	stk->top = cur_top->prev;
	if (cmd == NULL)
		return ;
	write(1, cmd, 3);
	write(1, "\n", 1);
}

void	rrr_helper(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt)
{
	int	cnt;

	cnt = 0;
	while (cnt < ra_cnt && cnt < rb_cnt)
	{
		cmd_rev_rotate("rrr", a);
		cmd_rev_rotate(0, b);
		cnt++;
	}
	if (cnt < ra_cnt)
	{
		while (cnt++ < ra_cnt)
			cmd_rev_rotate("rra", a);
	}
	else if (cnt < rb_cnt)
	{
		while (cnt++ < rb_cnt)
			cmd_rev_rotate("rrb", b);
	}
}
