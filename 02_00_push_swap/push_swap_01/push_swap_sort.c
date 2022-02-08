/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:49:59 by jrim              #+#    #+#             */
/*   Updated: 2022/02/07 02:07:12 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_a2b(t_stack *a, t_stack *b, int size);
void	stk_b2a(t_stack *a, t_stack *b, int size);
int		stk_min(t_stack *stk);
int		stk_max(t_stack *stk);
void	arr_quicksort(int *arr, int start, int end);

void	stk_a2b(t_stack *a, t_stack *b, int size)
{
	int		ra_cnt;
	int		pb_cnt;
	int		cnt;
	int		piv;
	t_node	*tmp;

	printf("-----a2b called!-----\n");
	printf("[size : %d]\n", size);
	if (b->size == 0 && is_sorted(a) == 1)
	{
		printf("----exit from a2b----\n");
		exit(0);
	}
	else if (size <= 1)
	{
		printf("-----return-----\n");
		return ;
	}
	else if (size == 2)
	{
		sort_2(a);
		stk_display_all(a, b);
		printf("-----return-----\n");
		return ;
	}
	ra_cnt = 0;
	pb_cnt = 0;
	cnt = 0;
	piv = select_piv(a);
	printf("[piv : %d]\n", piv);
	while (size-- > 0)
	{
		tmp = a->top;
		if (tmp->data > piv)
		{
			cmd_rotate("ra", a);
			ra_cnt++;
		}
		else
		{
			cmd_push("pb", a, b);
			pb_cnt++;
		}
	}
	while (cnt++ < ra_cnt)
		cmd_rev_rotate("rra", a);
	stk_display_all(a, b);
	printf("[ra : %d]\n", ra_cnt);
	printf("[pb : %d]\n", pb_cnt);
	stk_a2b(a, b, ra_cnt);
	stk_b2a(a, b, pb_cnt);
}

void	stk_b2a(t_stack *a, t_stack *b, int size)
{
	int		rb_cnt;
	int		pa_cnt;
	int		cnt;
	int		piv;
	t_node	*tmp;

	printf("-----b2a called!-----\n");
	printf("[size : %d]\n", size);
	if (b->size == 0 && is_sorted(a) == 1)
	{
		printf("----exit from b2a----\n");
		exit(0);
	}
	else if (size == 0)
	{
		printf("-----return-----\n");
		return ;
	}
	else if (size == 1)
	{
		cmd_push("pa", b, a);
		stk_display_all(a, b);
		printf("-----return-----\n");
		return ;
	}
	else if (is_rev_sorted(b) == 1)
	{
		size = b->size;
		while (size--)
			cmd_push("pa", b, a);
		stk_display_all(a, b);
		printf("-----return-----\n");
		return ;	
	}
	rb_cnt = 0;
	pa_cnt = 0;
	cnt = 0;
	piv = select_piv(b);
	printf("[piv : %d]\n", piv);
	while (size-- > 0)
	{
		tmp = b->top;
		if (tmp->data < piv)
		{
			cmd_rotate("rb", b);
			rb_cnt++;
		}
		else
		{
			cmd_push("pa", b, a);
			pa_cnt++;
		}
	}
	while (cnt++ < rb_cnt)
		cmd_rev_rotate("rrb", b);
	stk_display_all(a, b);
	printf("[rb : %d]\n", rb_cnt);
	printf("[pa : %d]\n", pa_cnt);
	stk_a2b(a, b, pa_cnt);
	stk_b2a(a, b, rb_cnt);
}

int	stk_min(t_stack *stk)
{
	int		min;
	int		size;
	t_node	*tmp;

	min = 2147483647;
	size = stk->size;
	tmp = stk->top;
	while (size--)
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

void	arr_quicksort(int *arr, int start, int end)
{
    int piv;
    int i;
    int j;
    int tmp;

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
