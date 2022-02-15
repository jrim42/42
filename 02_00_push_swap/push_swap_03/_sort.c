/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 23:04:35 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_elm *elm, t_piv *piv, int size);
void	stk_b2a(t_elm *elm, t_piv *piv, int size);
void	sort_2(t_stk *stk);
void	sort_3(t_stk *stk);

void	stk_a2b(t_elm *elm, t_piv *piv, int size)
{
	t_node	*tmp;
	int		ra_cnt;
	int		pb_cnt;
	int		rb_cnt;

	printf("%s-------- a2b called! --------%s\n", GREEN, RESET);
	if (a2b_helper(elm->a, elm->b, size) == 1)
		return ;
	det_init(piv, &ra_cnt, &pb_cnt, &rb_cnt);
	piv_select(elm->a, size, piv);
	while (size-- > 0)
	{
		tmp = elm->a->top;
		if (tmp->data >= piv->b_piv)
			cmd_rotate("ra", elm->a, &ra_cnt);
		else
		{
			cmd_push("pb", elm->a, elm->b, &pb_cnt);
			if (tmp->data >= piv->s_piv)
				cmd_rotate("rb", elm->b, &rb_cnt);
		}
	}
	rrr_helper(elm->a, elm->b, ra_cnt, rb_cnt);
	stk_display_all(elm->a, elm->b);
	getchar();
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

	printf("%s-------- b2a called! --------%s\n", BLUE, RESET);
	if (b2a_helper(elm->a, elm->b, size) == 1)
		return ;
	det_init(piv, &rb_cnt, &pa_cnt, &ra_cnt);
	piv_select(elm->b, size, piv);
	while (size-- > 0)
	{
		tmp = elm->b->top;
		if (tmp->data < piv->s_piv)
			cmd_rotate("rb", elm->b, &rb_cnt);
		else
		{
			cmd_push("pa", elm->b, elm->a, &pa_cnt);
			if (tmp->data < piv->b_piv)
				cmd_rotate("ra", elm->a, &ra_cnt);
		}
	}
	stk_a2b(elm, piv, pa_cnt - ra_cnt);
	rrr_helper(elm->a, elm->b, ra_cnt, rb_cnt);
	stk_display_all(elm->a, elm->b);
	getchar();
	stk_a2b(elm, piv, ra_cnt);
	stk_b2a(elm, piv, rb_cnt);
}

void	sort_2(t_stk *stk)
{
	printf("------- sort2 called! -------\n");
	t_node	*nd_1;
	t_node	*nd_2;

	nd_1 = stk->top;
	nd_2 = nd_1->next;
	if (nd_1->data > nd_2->data)
		cmd_swap("sa", stk, NULL);
}

void	sort_3(t_stk *stk)
{
	printf("------- sort3 called! -------\n");
	t_node	*nd_1;
	t_node	*nd_2;
	t_node	*nd_3;
	int		min;
	int		max;

	if (is_sorted(stk, 3) == 1)
		return ;
	nd_1 = stk->top;
	nd_2 = nd_1->next;
	nd_3 = nd_2->next;
	min = stk_min(stk, 3);
	max = stk_max(stk, 3);
	if (nd_2->data == min && nd_3->data == max)
		cmd_swap("sa", stk, 0);
	else if (nd_1->data == max)
		cmd_swap("sa", stk, 0);
	if (nd_1->data == min && nd_2->data == max)
	{
		cmd_rotate("ra", stk, 0);
		cmd_swap("sa", stk, 0);
		cmd_rev_rotate("rra", stk);
	}
	else if (nd_2->data == max && nd_3->data == min)
	{
		cmd_rotate("ra", stk, 0);
		cmd_swap("sa", stk, 0);
		cmd_rev_rotate("rra", stk);
		cmd_swap("sa", stk, 0);
	}
}
