/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimjeesoo <rimjeesoo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/10 16:50:27 by rimjeesoo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_stack *a, t_stack *b, t_detail* info, int size);
void	stk_b2a(t_stack *a, t_stack *b, t_detail* info, int size);
void	arr_quicksort(int *arr, int start, int end);

void	stk_a2b(t_stack *a, t_stack *b, t_detail* info, int size)
{
	int			cnt;
	t_node		*tmp;

	printf("%s-------- a2b called! --------%s\n", GREEN, RESET);
	printf("[size : %d]\n", size);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		sort_2(a);
		return ;
	}
	init_detail(info);
	cnt = 0;
	select_piv(a, size, info);
	while (size-- > 0)
	{
		tmp = a->top;
		if (tmp->data >= (info->b_piv))
			cmd_rotate("ra", a, &(info->ra_cnt));
		else
		{
			cmd_push("pb", a, b, &(info->pb_cnt));
			if (tmp->data >= info->s_piv)
				cmd_rotate("rb", a, &(info->rb_cnt));
		}
	}
	rrr_helper(a, b, info->ra_cnt, info->rb_cnt);
	stk_display_all(a, b);
	getchar();
	stk_a2b(a, b, info, (info->ra_cnt));
	stk_b2a(a, b, info, (info->rb_cnt));
	stk_b2a(a, b, info, (info->pb_cnt) - (info->rb_cnt));
}

void	stk_b2a(t_stack *a, t_stack *b, t_detail* info, int size)
{
	int			cnt;
	t_node		*tmp;

	printf("%s-------- b2a called! --------%s\n", BLUE, RESET);
	printf("[size : %d]\n", size);
	if (size == 0)
		return ;
	else if (size == 1)
	{
		cmd_push("pa", b, a, NULL);
		return ;
	}
	init_detail(info);
	cnt = 0;
	select_piv(b, size, info);
	//printf("[piv : %d]\n", piv);
	while (size-- > 0)
	{
		tmp = b->top;
		if (tmp->data < (info->s_piv))
			cmd_rotate("rb", b, &(info->rb_cnt));
		else
		{
			cmd_push("pa", b, a, &(info->pa_cnt));
			if (tmp->data < (info->b_piv))
				cmd_rotate("ra", b, &(info->rb_cnt));
		}
	}
	stk_a2b(a, b, info, (info->pa_cnt) - (info->ra_cnt));
	rrr_helper(a, b, info->ra_cnt, info->rb_cnt);
	stk_display_all(a, b);
	getchar();
	stk_a2b(a, b, info, (info->ra_cnt));
	stk_b2a(a, b, info, (info->rb_cnt));
}

void	arr_quicksort(int *arr, int start, int end)
{
	int	piv;
	int	i;
	int	j;
	int	tmp;

	piv = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (arr[i] <= arr[piv] && i < end + 1)
			i++;
		while (arr[j] >= arr[piv] && j > start)
			j--;
		if (i > j)
			data_swap(&arr[j], &arr[piv]);
		else
			data_swap(&arr[j], &arr[i]);
		arr_quicksort(arr, start, j - 1);
		arr_quicksort(arr, j + 1, end);
	}
}
