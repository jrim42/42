/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/10 23:32:45 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_stack *a, t_stack *b, t_pivot *piv, int size);
void	stk_b2a(t_stack *a, t_stack *b, t_pivot *piv, int size);
void	sort_2(t_stack *stk);

void	stk_a2b(t_stack *a, t_stack *b, t_pivot *piv, int size)
{
	t_node	*tmp;
	int		ra_cnt;
	int		pb_cnt;
	int		rb_cnt;

	printf("%s-------- a2b called! --------%s\n", GREEN, RESET);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		sort_2(a);
		return ;
	}
	init_detail(piv, &ra_cnt, &pb_cnt, &rb_cnt);
	select_piv(a, size, piv);
	while (size-- > 0)
	{
		tmp = a->top;
		if (tmp->data >= piv->b_piv)
			cmd_rotate("ra", a, &ra_cnt);
		else
		{
			cmd_push("pb", a, b, &pb_cnt);
			if (tmp->data >= piv->s_piv)
				cmd_rotate("rb", b, &rb_cnt);
		}
	}
	rrr_helper(a, b, ra_cnt, rb_cnt);
	stk_display_all(a, b);
	getchar();
	stk_a2b(a, b, piv, ra_cnt);
	stk_b2a(a, b, piv, rb_cnt);
	stk_b2a(a, b, piv, pb_cnt - rb_cnt);
}

void	stk_b2a(t_stack *a, t_stack *b, t_pivot *piv, int size)
{
	t_node	*tmp;
	int		rb_cnt;
	int		pa_cnt;
	int		ra_cnt;

	printf("%s-------- b2a called! --------%s\n", BLUE, RESET);
	if (size == 0)
		return ;
	else if (size == 1)
	{
		cmd_push("pa", b, a, NULL);
		return ;
	}
	init_detail(piv, &rb_cnt, &pa_cnt, &ra_cnt);
	select_piv(b, size, piv);
	while (size-- > 0)
	{
		tmp = b->top;
		if (tmp->data < piv->s_piv)
			cmd_rotate("rb", b, &rb_cnt);
		else
		{
			cmd_push("pa", b, a, &pa_cnt);
			if (tmp->data < piv->b_piv)
				cmd_rotate("ra", a, &ra_cnt);
		}
	}
	stk_a2b(a, b, piv, pa_cnt - ra_cnt);
	rrr_helper(a, b, ra_cnt, rb_cnt);
	stk_display_all(a, b);
	getchar();
	stk_a2b(a, b, piv, ra_cnt);
	stk_b2a(a, b, piv, rb_cnt);
}

void	sort_2(t_stack *stk)
{
	t_node	*nd_1;
	t_node	*nd_2;

	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap("sa", stk, NULL);
}