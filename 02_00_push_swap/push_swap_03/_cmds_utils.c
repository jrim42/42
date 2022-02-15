/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmds_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:51:58 by jrim              #+#    #+#             */
/*   Updated: 2022/02/16 00:41:53 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_display_all(t_stk *cmdlst);
void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt);

void	cmd_display_all(t_stk *cmdlst)
{
	t_node	*tmp;
	int		size;

	tmp = cmdlst->top->prev;
	size = cmdlst->size;
	while (size--)
	{
		cmd_display_one(tmp->data);
		tmp = tmp->prev;
	}
	printf("----- total : %d cmds -----\n", cmdlst->size);
}

void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt)
{
	int	cnt;
	t_stk	*a;
	t_stk	*b;

	cnt = 0;
	a = elm->a;
	b = elm->b;
	while (cnt < ra_cnt && cnt < rb_cnt)
	{
		cmd_rev_rotate(32, elm);
		cnt++;
	}
	if (cnt < ra_cnt)
	{
		while (cnt++ < ra_cnt)
			cmd_rev_rotate(30, elm);
	}
	else if (cnt < rb_cnt)
	{
		while (cnt++ < rb_cnt)
			cmd_rev_rotate(31, elm);
	}
}
