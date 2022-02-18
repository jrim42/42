/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:51:58 by jrim              #+#    #+#             */
/*   Updated: 2022/02/18 12:02:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_cleaner(t_elm *elm);
void	cmd_display_all(t_stk *cmdlst);
void	cmd_display_one(int cmd);

void	cmd_display_all(t_stk *cmdlst)
{
	t_node	*tmp;
	int		size;
	int		cmd_cnt;

	tmp = cmdlst->top->prev;
	size = cmdlst->size;
	cmd_cnt = 0;
	while (size--)
	{
		if (tmp->data != -1)
		{
			cmd_display_one(tmp->data);
			cmd_cnt++;
		}
		tmp = tmp->prev;
	}
	printf("----- total : %d cmds -----\n", cmd_cnt);
}

void	cmd_cleaner(t_elm *elm)
{
	t_node	*tmp;
	int		size;
	int		prev_cmd;
	int		cur_cmd;
	int		next_cmd;

	tmp = elm->cmdlst->top->prev;
	size = elm->cmdlst->size;
	while (size--)
	{	
		prev_cmd = tmp->prev->data;
		cur_cmd = tmp->data;
		next_cmd = tmp->next->data;
		if (cur_cmd == 31 && (prev_cmd == 21 || next_cmd == 21))
		{
			tmp->data = -1;
			if (next_cmd == 21)
				tmp->next->data = -1;
			else if (prev_cmd == 21)
				tmp->prev->data = -1;
		}
		else if (tmp->data == 30 && (prev_cmd == 20 || next_cmd == 20))
		{
			tmp->data = -1;
			if (next_cmd == 20)
				tmp->next->data = -1;
			else if (prev_cmd == 20)
				tmp->prev->data = -1;
		}
		tmp = tmp->prev;
	}
}

void	cmd_display_one(int cmd)
{
	if (cmd / 10 == 0)
		write(1, "s", 1);
	else if (cmd / 10 == 1)
		write(1, "p", 1);
	else if (cmd / 10 == 2)
		write(1, "r", 1);
	else if (cmd / 10 == 3)
		write(1, "rr", 2);
	if (cmd % 10 == 0)
		write(1, "a\n", 2);
	else if (cmd % 10 == 1)
		write(1, "b\n", 2);
	else
	{
		if (cmd / 10 == 0)
			write(1, "s\n", 2);
		else
			write(1, "r\n", 2);
	}	
}
