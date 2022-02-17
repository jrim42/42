/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:40:29 by jrim              #+#    #+#             */
/*   Updated: 2022/02/17 19:53:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_swap(int new_cmd, t_elm *elm, int *cmd_cnt);
void	cmd_push(int new_cmd, t_elm *elm, int *cmd_cnt);
void	cmd_rotate(int new_cmd, t_elm *elm, int *cmd_cnt);
void	cmd_rev_rotate(int new_cmd, t_elm *elm);

void	cmd_swap(int new_cmd, t_elm *elm, int *cmd_cnt)
{
	t_stk	*stk;
	t_node	*cur_top;
	int		tmp;

	stk_push(elm->cmdlst, nd_init(new_cmd));
	if (new_cmd == 0)
		stk = elm->a;
	else if (new_cmd == 1)
		stk = elm->b;
	cur_top = stk->top;
	if (cur_top && cur_top->next)
	{
		tmp = cur_top->data;
		cur_top->data = cur_top->next->data;
		cur_top->next->data = tmp;
	}
	cmd_display_one(new_cmd);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_push(int new_cmd, t_elm *elm, int *cmd_cnt)
{
	stk_push(elm->cmdlst, nd_init(new_cmd));
	if (new_cmd == 10)
		stk_push(elm->a, stk_pop(elm->b));
	else if (new_cmd == 11)
		stk_push(elm->b, stk_pop(elm->a));
	cmd_display_one(new_cmd);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rotate(int new_cmd, t_elm *elm, int *cmd_cnt)
{
	t_node	*cur_top;

	stk_push(elm->cmdlst, nd_init(new_cmd));
	if (new_cmd == 20 || new_cmd == 22)
	{
		cur_top = elm->a->top;
		elm->a->top = cur_top->next;
	}
	if (new_cmd == 21 || new_cmd == 22)
	{
		cur_top = elm->b->top;
		elm->b->top = cur_top->next;
	}
	cmd_display_one(new_cmd);
	if (cmd_cnt != NULL)
		(*cmd_cnt)++;
}

void	cmd_rev_rotate(int new_cmd, t_elm *elm)
{
	t_stk	*stk;
	t_node	*cur_top;
	
	//rr_cleaner(elm, new_cmd);
	stk_push(elm->cmdlst, nd_init(new_cmd));
	if (new_cmd == 30 || new_cmd == 32)
	{
		cur_top = elm->a->top;
		elm->a->top = cur_top->prev;
	}
	if (new_cmd == 31 || new_cmd == 32)
	{
		cur_top = elm->b->top;
		elm->b->top = cur_top->prev;
	}
	cmd_display_one(new_cmd);
}
