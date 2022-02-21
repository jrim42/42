/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:51:58 by jrim              #+#    #+#             */
/*   Updated: 2022/02/21 21:04:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_cleaner(t_elm *elm);
void	cmd_display_all(t_stk *cmdlst);
void	cmd_display_one(int cmd);

void	cmd_cleaner(t_elm *elm)
{
	int		size;
	t_node	*tmp;

	size = elm->cmdlst->size;
	tmp = elm->cmdlst->top->prev;
	while (size--)
	{	
		if (tmp->data == 31 && (tmp->prev->data == 21 || tmp->next->data == 21))
		{
			tmp->data = -1;
			if (tmp->next->data == 21)
				tmp->next->data = -1;
			else if (tmp->prev->data == 21)
				tmp->prev->data = -1;
		}
		if (tmp->data == 30 && (tmp->prev->data == 20 || tmp->next->data == 20))
		{
			tmp->data = -1;
			if (tmp->next->data == 20)
				tmp->next->data = -1;
			else if (tmp->prev->data == 20)
				tmp->prev->data = -1;
		}
		tmp = tmp->prev;
	}
}

void	cmd_display_all(t_stk *cmdlst)
{
	int		size;
	t_node	*tmp;

	size = cmdlst->size;
	if (size == 0)
		return ;
	tmp = cmdlst->top->prev;
	while (size--)
	{
		if (tmp->data != -1)
			cmd_display_one(tmp->data);
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
