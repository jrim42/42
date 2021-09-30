/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:21:22 by jrim              #+#    #+#             */
/*   Updated: 2021/09/22 11:57:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	min_search(char **argv, int idx1, int idx2)
{
	int	i;

	i = 0;
	while (argv[idx1][i] != '\0' || argv[idx2][i] != '\0')
	{
		if (argv[idx2][i] == '\0' || argv[idx1][i] > argv[idx2][i])
			return (idx2);
		else if (argv[idx1][i] == '\0' || argv[idx1][i] < argv[idx2][i])
			return (idx1);
		i++;
	}
	return (idx2);
}

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_swap_params(char **argv, int idx1, int idx2)
{
	char	*tmp;

	tmp = argv[idx1];
	argv[idx1] = argv[idx2];
	argv[idx2] = tmp;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	min;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			min = min_search(argv, i, j);
			ft_swap_params(argv, i, min);
			j++;
		}
		i++;
	}
	ft_print_params(argc, argv);
	return (0);
}
