/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:02:53 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 18:58:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char **argv);

int	main(int argc, char **argv)
{

	if (argc == 3)
		ft_union(argv);
	write(1, "\n", 1);
	return (0);
}

void	ft_union(char **argv)
{
	int	used[255] = {0, };
	int	i;
	int	j;

	i = 0;
	while (++i < 3)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!used[(unsigned char)argv[i][j]])
			{
				used[(unsigned char)argv[i][j]] = 1;
				write(1, &argv[i][j], 1);
			}
		}
	}
}