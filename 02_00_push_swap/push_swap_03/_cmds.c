/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:40:29 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 23:02:59 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_swap(char *cmd, t_stk *stk, int *cmd_cnt);
void	cmd_push(char *cmd, t_stk *from, t_stk *to, int *cmd_cnt);
void	cmd_rotate(char *cmd, t_stk *stk, int *cmd_cnt);
void	cmd_rev_rotate(char *cmd, t_stk *stk);

void	cmd_swap(char *cmd, t_stk *stk, int *cmd_cnt)
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

void	cmd_push(char *cmd, t_stk *from, t_stk *to, int *cmd_cnt)
{
	stk_push(to, stk_pop(from));
	write(1, cmd, 2);
	write(1, "\n", 1);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rotate(char *cmd, t_stk *stk, int *cmd_cnt)
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

void	cmd_rev_rotate(char *cmd, t_stk *stk)
{
	t_node	*cur_top;

	cur_top = stk->top;
	stk->top = cur_top->prev;
	if (cmd == NULL)
		return ;
	write(1, cmd, 3);
	write(1, "\n", 1);
}
