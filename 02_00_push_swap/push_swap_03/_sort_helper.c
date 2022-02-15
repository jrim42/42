/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:05:39 by jrim              #+#    #+#             */
/*   Updated: 2022/02/16 00:49:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a2b_helper(t_elm *elm, int size);
int	b2a_helper(t_elm *elm, int size);

int	a2b_helper(t_elm *elm, int size)
{
	t_stk	*a;
	t_stk	*b;

	a = elm->a;
	b = elm->b;
	if (b->size == 0 && is_sorted(a, a->size) == 1)
		exit(0); // 명령어 정리하는 곳으로 가야함.
	else if (size <= 1)
		return (1);
	else if (size == 2)
	{
		sort_2(elm, a);
		return (1);
	}
	else if (size == 3)
	{
		sort_3(elm, a);
		return (1);
	}
	return (0);
}

int	b2a_helper(t_elm *elm, int size)
{
	int		cnt;
	t_stk	*a;
	t_stk	*b;

	a = elm->a;
	b = elm->b;
	if (size == 0)
		return (1);
	else if (size == 1)
	{
		cmd_push(10, elm, NULL);
		return (1);
	}
	else if (is_sorted(a, a->size) == 1 && is_rev_sorted(b, b->size) == 1)
	{
		cnt = b->size;
		while (cnt--)
			cmd_push(10, elm, NULL);
		return (1);
	}
	return (0);
}
