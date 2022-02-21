/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/21 18:57:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_elm *elm, t_piv *piv, int size);
void	stk_b2a(t_elm *elm, t_piv *piv, int size);
void	sort_2(t_elm *elm, t_stk *stk);
void	sort_3(t_elm *elm, t_stk *stk);

void	stk_a2b(t_elm *elm, t_piv *piv, int size)
{
	t_node	*tmp;
	int		ra_cnt;
	int		pb_cnt;
	int		rb_cnt;

	if (a2b_helper(elm, size) == 1)
		return ;
	det_init(piv, &ra_cnt, &pb_cnt, &rb_cnt);
	piv_select(elm->a, size, piv);
	while (size-- > 0)
	{
		tmp = elm->a->top;
		if (tmp->data >= piv->b_piv)
			cmd_rotate(20, elm, &ra_cnt);
		else
		{
			cmd_push(11, elm, &pb_cnt);
			if (tmp->data >= piv->s_piv)
				cmd_rotate(21, elm, &rb_cnt);
		}
	}
	rrr_helper(elm, ra_cnt, rb_cnt);
	stk_a2b(elm, piv, ra_cnt);
	stk_b2a(elm, piv, rb_cnt);
	stk_b2a(elm, piv, pb_cnt - rb_cnt);
}

void	stk_b2a(t_elm *elm, t_piv *piv, int size)
{
	t_node	*tmp;
	int		rb_cnt;
	int		pa_cnt;
	int		ra_cnt;

	if (b2a_helper(elm, size) == 1)
		return ;
	det_init(piv, &rb_cnt, &pa_cnt, &ra_cnt);
	piv_select(elm->b, size, piv);
	while (size-- > 0)
	{
		tmp = elm->b->top;
		if (tmp->data < piv->s_piv)
			cmd_rotate(21, elm, &rb_cnt);
		else
		{
			cmd_push(10, elm, &pa_cnt);
			if (tmp->data < piv->b_piv)
				cmd_rotate(20, elm, &ra_cnt);
		}
	}
	stk_a2b(elm, piv, pa_cnt - ra_cnt);
	rrr_helper(elm, ra_cnt, rb_cnt);
	stk_a2b(elm, piv, ra_cnt);
	stk_b2a(elm, piv, rb_cnt);
}

void	sort_2(t_elm *elm, t_stk *stk)
{
	t_node	*nd_1;
	t_node	*nd_2;

	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap(0, elm, NULL);
}

void	sort_3(t_elm *elm, t_stk *stk)
{
	t_node	*nd;
	int		min;
	int		max;

	if (is_sorted(stk, 3) == 1)
		return ;
	nd = stk->top->next;
	min = stk_min(stk, 3);
	max = stk_max(stk, 3);
	if (nd->data == min && nd->next->data == max)
		cmd_swap(0, elm, 0);
	else if (nd->prev->data == max)
		cmd_swap(0, elm, 0);
	if (nd->data == max && (nd->prev->data == min || nd->next->data == min))
	{
		cmd_rotate(20, elm, 0);
		cmd_swap(0, elm, 0);
		cmd_rev_rotate(30, elm);
		nd = stk->top->next;
		if (nd->data == min && nd->next->data == max)
			cmd_swap(0, elm, 0);
	}
}
