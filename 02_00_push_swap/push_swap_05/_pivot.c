/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pivot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:39:07 by jrim              #+#    #+#             */
/*   Updated: 2022/02/20 16:07:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	piv_select(t_stk *stk, int size, t_piv *piv);
void	arr_fill(t_stk *stk, int *arr, int size);
void	arr_qsort(int *arr, int start, int end);

void	piv_select(t_stk *stk, int size, t_piv *piv)
{
	int		s_idx;
	int		b_idx;
	int		*arr;

	s_idx = size / 3;
	b_idx = s_idx * 2;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		exit(1);
	arr_fill(stk, arr, size);
	arr_qsort(arr, 0, size - 1);
	piv->s_piv = arr[s_idx];
	piv->b_piv = arr[b_idx];
	free(arr);
}

void	arr_fill(t_stk *stk, int *arr, int size)
{
	int		arr_idx;
	t_node	*tmp;

	arr_idx = 0;
	tmp = stk->top;
	while (size--)
	{
		arr[arr_idx] = tmp->data;
		arr_idx++;
		tmp = tmp->next;
	}
}

void	arr_qsort(int *arr, int start, int end)
{
	int	piv;
	int	left;
	int	right;

	piv = start;
	left = start + 1;
	right = end;
	if (start >= end)
		return ;
	while (left <= right)
	{
		while (arr[left] <= arr[piv] && left < end + 1)
			left++;
		while (arr[right] >= arr[piv] && right > start)
			right--;
		if (left > right)
			data_swap(&arr[right], &arr[piv]);
		else
			data_swap(&arr[right], &arr[left]);
		arr_qsort(arr, start, right - 1);
		arr_qsort(arr, right + 1, end);
	}
}
