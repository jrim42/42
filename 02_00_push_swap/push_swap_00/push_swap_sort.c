/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/05 21:51:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_stack *a, t_stack *b, int b_piv, int s_piv);
void	stk_b2a(t_stack *a, t_stack *b, int b_piv, int s_piv);
int		stk_min(t_stack *stk);
int		stk_max(t_stack *stk);
void	stk_quicksort(t_stack *stk, t_node *head, t_node *tail, int left, int right);

void	stk_a2b(t_stack *a, t_stack *b, int b_piv, int s_piv)
{
	int		size;
	int		ra_cnt;
	int		rb_cnt;
	int		pb_cnt;
	t_node	*tmp;

	size = a->size;
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	while (size--)
	{
		tmp = a->top;
		if (tmp->data >= b_piv)
		{
			cmd_rotate("ra", a);
			ra_cnt++;
		}
		else
		{
			cmd_push("pb", a, b);
			pb_cnt++;
			if (tmp->data < s_piv)
			{
				cmd_rotate("rb", b);
				rb_cnt++;
			}
		}
	}
	//stk_display_all(a, b);
	while (ra_cnt-- && rb_cnt--)
	{
		cmd_rev_rotate("rrr", a);
		cmd_rev_rotate(0, b);
	}
	while (ra_cnt-- > 0)
		cmd_rev_rotate("rra", a);
	while (rb_cnt-- > 0)
		cmd_rev_rotate("rrb", b);
}

void	stk_b2a(t_stack *a, t_stack *b, int b_piv, int s_piv)
{
	int		size;
	int		rb_cnt;
	int		pa_cnt;
	int		ra_cnt;
	t_node	*tmp;

	size = b->size;
	rb_cnt = 0;
	pa_cnt = 0;
	ra_cnt = 0;
	while (size--)
	{
		tmp = b->top;
		if (tmp->data >= b_piv)
		{
			cmd_rotate("rb", b);
			rb_cnt++;
		}
		else
		{
			cmd_push("pa", b, a);
			pa_cnt++;
			if (tmp->data < s_piv)
			{
				cmd_rotate("ra", a);
				ra_cnt++;
			}
		}
	}
	//stk_display_all(a, b);
	while (ra_cnt-- && rb_cnt--)
	{
		cmd_rev_rotate("rrr", a);
		cmd_rev_rotate(0, b);
	}
	while (ra_cnt-- > 0)
		cmd_rev_rotate("rra", a);
	while (rb_cnt-- > 0)
		cmd_rev_rotate("rrb", b);
}

int	stk_min(t_stack *stk)
{
	int		min;
	t_node	*tmp;

	min = 2147483647;
	tmp = stk->top;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	stk_max(t_stack *stk)
{
	int		max;
	t_node	*tmp;

	max = -2147483648;
	tmp = stk->top;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (0);
}

void	stk_quicksort(t_stack *stk, t_node *head, t_node *tail, int left, int right)
{
	int		l_cnt;
	int		r_cnt;
	t_node	*l_node;
	t_node	*r_node;

	if (left >= right)
		return ;
	l_cnt = left;
	r_cnt = right;
	l_node = head->next;
	r_node = tail;
	while (l_cnt < r_cnt)
	{
		while (l_node->data < head->data && l_cnt <= right)
		{
			l_node = l_node->next;
			l_cnt++;
		}
		while (r_node->data > head->data && r_cnt > left)
		{
			r_node = r_node->prev;
			r_cnt--;
		}
		if (l_cnt < r_cnt)
			data_swap(&(l_node->data), &(r_node->data));
		else
			data_swap(&(head->data), &(r_node->data));
	}
	stk_quicksort(stk, head, r_node->prev, left, r_cnt - 1);
	stk_quicksort(stk, r_node->next, tail, r_cnt + 1, right);
}
