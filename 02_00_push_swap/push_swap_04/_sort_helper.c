/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:05:39 by jrim              #+#    #+#             */
/*   Updated: 2022/02/19 23:58:33 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		a2b_helper(t_elm *elm, int size);
int		b2a_helper(t_elm *elm, int size);
void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt);
void	rrr_cleaner(t_elm *elm, int new_cmd);

int	a2b_helper(t_elm *elm, int size)
{
	t_stk	*a;
	t_stk	*b;

	a = elm->a;
	b = elm->b;
	if (b->size == 0 && is_sorted(a, a->size) == 1)
		return (1);
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
	if (b->size == 0 || size == 0)
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

void	rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt)
{
	int		cnt;
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
		while (cnt++ < ra_cnt)
			cmd_rev_rotate(30, elm);
	else if (cnt < rb_cnt)
		while (cnt++ < rb_cnt)
			cmd_rev_rotate(31, elm);
}

void	rrr_cleaner(t_elm *elm, int new_cmd)
{
	t_stk	*cmdlst;
	int		cur_cmd;

	cmdlst = elm->cmdlst;
	cur_cmd = cmdlst->top->data;
	if (cur_cmd < 20)
		return ;
	if ((cur_cmd == 20 || cur_cmd == 21) && new_cmd == 32)
	{
		free(stk_pop(cmdlst));
		if (cur_cmd == 20)
			stk_push(cmdlst, nd_init(31));
		else if (cur_cmd == 21)
			stk_push(cmdlst, nd_init(30));
	}
	else if (cur_cmd == 20 && new_cmd == 30)
		free(stk_pop(cmdlst));
	else if (cur_cmd == 21 && new_cmd == 31)
		free(stk_pop(cmdlst));
	else
		stk_push(elm->cmdlst, nd_init(new_cmd));
}
