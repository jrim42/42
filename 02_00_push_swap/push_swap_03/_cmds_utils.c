/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_cmds_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:51:58 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 20:07:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_helper(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt);

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
