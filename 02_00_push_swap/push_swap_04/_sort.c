/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/21 21:47:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_elm *elm, t_piv *piv, int size);
void	stk_b2a(t_elm *elm, t_piv *piv, int size);

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
