/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:18:14 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/04 18:00:37 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int inffd, int outffd, char **av, char **env);

void	pipex(int inffd, int outffd, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fds[2];
	int		status;

	pipe_error(pipe(fds));
	pid1 = fork();
	error_pid(pid1);
	if (pid1 == 0)
	{
		close(fds[0]);
		child1(fds[1], inffd, av, env);
	}
	pid2 = fork();
	error_pid(pid2);
	if (pid2 == 0)
	{
		close(fds[1]);
		child2(fds[0], outffd, av, env);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	int	infile;
	int	outfile;

	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infile < 0)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	else if (outfile < 0)
	{
		perror(av[ac - 1]);
		exit(EXIT_SUCCESS);
	}
	if (ac >= 2)
		pipex(infile, outfile, av, env);
}