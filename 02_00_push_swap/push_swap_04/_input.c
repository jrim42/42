/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _input.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:43:55 by jrim              #+#    #+#             */
/*   Updated: 2022/02/19 15:10:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stk_fill(t_stk *stk, int argc, char **argv);
int			check_num(char **input);
int			check_dup(t_stk *stk);
void		err_exit(void);
long long	ft_atoll(char *str);

void	stk_fill(t_stk *stk, int argc, char **argv)
{
	char		**input;
	int			idx_1;
	int			idx_2;
	long long	data;

	idx_1 = 0;
	while (idx_1++ < argc - 1)
	{
		input = ft_split(argv[idx_1], ' ');
		if (!input || check_num(input) == 0)
			err_exit();
		idx_2 = -1;
		while (input[++idx_2])
		{
			data = ft_atoll(input[idx_2]);
			if (data > INT_MAX || data < INT_MIN)
				err_exit();
			stk_push(stk, nd_init(data));
			free(input[idx_2]);
		}
		free(input);
	}
	if (check_dup(stk) == 0)
		err_exit();
}

int	check_num(char **input)
{
	int	idx_1;
	int	idx_2;
	int	digit_cnt;

	idx_1 = 0;
	while (input[idx_1])
	{
		idx_2 = 0;
		digit_cnt = 0;
		if (input[idx_1][idx_2] == '-' || input[idx_1][idx_2] == '+')
			idx_2++;
		while (input[idx_1][idx_2] == '0')
			idx_2++;
		while (ft_isdigit(input[idx_1][idx_2]))
		{
			idx_2++;
			digit_cnt++;
		}
		if (input[idx_1][idx_2] || digit_cnt > 10)
			return (0);
		idx_1++;
	}
	return (1);
}

int	check_dup(t_stk *stk)
{
	int		cnt_1;
	int		cnt_2;
	t_node	*tmp;
	t_node	*cur;

	cnt_1 = 0;
	tmp = stk->top;
	while (cnt_1 < stk->size)
	{
		cnt_2 = cnt_1 + 1;
		cur = tmp->next;
		while (cnt_2 < stk->size)
		{
			if (tmp->data == cur->data)
				return (0);
			cur = cur->next;
			cnt_2++;
		}
		tmp = tmp->next;
		cnt_1++;
	}
	return (1);
}

void	err_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

long long	ft_atoll(char *str)
{
	unsigned long	num;
	int				sign;
	char			*ptr;

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
	if (num > LONG_MAX)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return ((long long)num * sign);
}
