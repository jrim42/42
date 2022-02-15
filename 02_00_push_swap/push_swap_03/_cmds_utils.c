/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:51:58 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 23:02:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_display(t_stk *cmdlst);
void	rrr_helper(t_stk *a, t_stk *b, int ra_cnt, int rb_cnt);

void	cmd_display(t_stk *cmdlst)
{
	t_node	*tmp;
	int		size;

	tmp = cmdlst->top;
	size = cmdlst->size;
	while (size--)
	{
		if (tmp->data / 10 == 0)
			write(1, "s", 1);
		else if (tmp->data / 10 == 1)
			write(1, "p", 1);
		else if (tmp->data / 10 == 2)
			write(1, "r", 1);
		else if (tmp->data / 10 == 3)
			write(1, "rr", 2);
		if (tmp->data % 10 == 0)
			write(1, "a\n", 2);
		else if (tmp->data % 10 == 1)
			write(1, "b\n", 2);
		else
		{
			if (tmp->data / 10 == 0)
				write(1, "s\n", 2);
			else 
				write(1, "r\n", 2);
		}	
	}
}

void	rrr_helper(t_stk *a, t_stk *b, int ra_cnt, int rb_cnt)
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
