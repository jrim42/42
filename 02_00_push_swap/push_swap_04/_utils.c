/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:54:44 by jrim              #+#    #+#             */
/*   Updated: 2022/02/20 15:58:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(char *str);
void		det_init(t_piv *piv, int *cnt_1, int *cnt_2, int *cnt_3);
void		data_swap(int *a, int *b);
void		stk_display_all(t_stk *stk_a, t_stk *stk_b);

long long	ft_atoll(char *str)
{
	long long	num;
	int			sign;
	char		*ptr;

	num = 0;
	sign = 1;
	ptr = (char *)str;
	ptr += ft_isspace_or_issign(str, &sign);
	while (ft_isdigit(*ptr) == 1 && *ptr != '\0')
	{
		num += (*ptr) - '0';
		if (ft_isdigit(*(ptr + 1)) == 1 && *(ptr + 1) != '\0')
			num *= 10;
		ptr++;
	}
	return ((long long)num * sign);
}

void	det_init(t_piv *piv, int *cnt_1, int *cnt_2, int *cnt_3)
{
	piv->b_piv = 0;
	piv->s_piv = 0;
	*cnt_1 = 0;
	*cnt_2 = 0;
	*cnt_3 = 0;
}

void	data_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	stk_display_all(t_stk *stk_a, t_stk *stk_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = stk_a->top;
	size_a = stk_a->size;
	tmp_b = stk_b->top;
	size_b = stk_b->size;
	printf("%s a |", YELLOW);
	while (size_a--)
	{
		printf(" %d |", tmp_a->data);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	printf(" b |");
	while (size_b--)
	{
		printf(" %d |", tmp_b->data);
		tmp_b = tmp_b->next;
	}
	printf("%s\n", RESET);
}
