/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pivot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:39:07 by jrim              #+#    #+#             */
/*   Updated: 2022/02/15 23:03:46 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	piv_select(t_stk *stk, int size, t_piv *piv);
void	arr_fill(t_stk *stk, int *arr, int size);
void	arr_quicksort(int *arr, int start, int end);

void	piv_select(t_stk *stk, int size, t_piv *piv)
{
	int		s_idx;
	int		b_idx;
	int		*arr;

	s_idx = size / 3;
	b_idx = s_idx * 2;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return ;
	arr_fill(stk, arr, size);
	arr_quicksort(arr, 0, size - 1);
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

void	arr_quicksort(int *arr, int start, int end)
{
	int	piv;
	int	i;
	int	j;

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
