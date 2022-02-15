/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:40:29 by jrim              #+#    #+#             */
/*   Updated: 2022/02/16 00:46:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_swap(int cmd, t_elm *elm, int *cmd_cnt);
void	cmd_push(int cmd, t_elm *elm, int *cmd_cnt);
void	cmd_rotate(int cmd, t_elm *elm, int *cmd_cnt);
void	cmd_rev_rotate(int cmd, t_elm *elm);

void	cmd_swap(int cmd, t_elm *elm, int *cmd_cnt)
{
	t_stk	*stk;
	t_node	*cur_top;
	int		tmp;

	stk_push(elm->cmdlst, nd_init(cmd));
	if (cmd == 0)
		stk = elm->a;
	else if (cmd == 1)
		stk = elm->b;
	cur_top = stk->top;
	if (cur_top && cur_top->next)
	{
		tmp = cur_top->data;
		cur_top->data = cur_top->next->data;
		cur_top->next->data = tmp;
	}
	cmd_display_one(cmd);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_push(int cmd, t_elm *elm, int *cmd_cnt)
{
	t_stk	*to;
	t_stk	*from;

	stk_push(elm->cmdlst, nd_init(cmd));
	if (cmd == 10)
	{
		from = elm->b;
		to = elm->a;
	}
	else if (cmd == 11)
	{
		from = elm->a;
		to = elm->b;
	}
	stk_push(to, stk_pop(from));
	cmd_display_one(cmd);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rotate(int cmd, t_elm *elm, int *cmd_cnt)
{
	t_node	*cur_top;

	stk_push(elm->cmdlst, nd_init(cmd));
	if (cmd == 20 || cmd == 22)
	{
		cur_top = elm->a->top;
		elm->a->top = cur_top->next;
	}
	if (cmd == 21 || cmd == 22)
	{
		cur_top = elm->b->top;
		elm->b->top = cur_top->next;
	}
	cmd_display_one(cmd);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rev_rotate(int cmd, t_elm *elm)
{
	t_stk	*stk;
	t_node	*cur_top;

	stk_push(elm->cmdlst, nd_init(cmd));
	if (cmd == 30 || cmd == 32)
	{
		cur_top = elm->a->top;
		elm->a->top = cur_top->prev;
	}
	if (cmd == 31 || cmd == 32)
	{
		cur_top = elm->b->top;
		elm->b->top = cur_top->prev;
	}
	cmd_display_one(cmd);
}
