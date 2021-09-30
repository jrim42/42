/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:34:50 by jrim              #+#    #+#             */
/*   Updated: 2021/09/25 13:34:52 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_cnt;

void	print_queen(char *queen);
void	set_queen(int row, int *flag, char *queen);
int		check_dia(char *queen, int row, int col);

int	ft_ten_queens_puzzle(void)
{
	int		flag[10];
	char	queen[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		flag[i] = 0;
		queen[i] = '0';
		i++;
	}
	set_queen(0, flag, queen);
	return (g_cnt);
}

void	print_queen(char *queen)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &queen[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	set_queen(int row, int *flag, char *queen)
{
	int	col;

	col = 0;
	if (row == 10)
	{
		print_queen(queen);
		g_cnt++;
		return ;
	}
	while (col < 10)
	{
		if (flag[col] != 1)
		{
			queen[row] = col + '0';
			if (check_dia(queen, row, col) == 1)
			{
				flag[col] = 1;
				set_queen(row + 1, flag, queen);
				flag[col] = 0;
			}
		}
		col++;
	}
}

int	check_dia(char *queen, int row, int col)
{
	int	i;

	i = 1;
	while (row - i >= 0 && col - i >= 0)
	{
		if (queen[row - i] == col - i + '0')
			return (0);
		i++;
	}
	i = 1;
	while (col + i <= 9)
	{
		if (queen[row - i] == col + i + '0')
			return (0);
		i++;
	}
	return (1);
}
