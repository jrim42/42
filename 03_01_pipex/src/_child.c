/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _child.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:16:24 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/04 18:02:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int fd1, int infile, char **av, char **env);
void	child2(int fd0, int outfile, char **av, char **env);

void	child1(int fd1, int infile, char **av, char **env)
{
	int		from_infile;
	int		to_out;
	char	**needed_args;
	char	*cmd1;

	from_infile = dup2(infile, STDIN_FILENO);
	close(infile);
	to_out = dup2(fd1, STDOUT_FILENO);
	close(fd1);
	if (from_infile < 0 || to_out < 0)
	{
		perror("dup2() returns -1");
		exit(EXIT_FAILURE);
	}
	cmd1 = parsing(env, av[2]);
	needed_args = ft_split(av[2], ' ');
	execve(cmd1, needed_args, env);
	double_free(needed_args);
	free(cmd1);
	perror("lol");
}

void	child2(int fd0, int outfile, char **av, char **env)
{
	int		fromcmd1;
	char	*cmd2;
	char	**cmd2_args;
	int		to_outfile;

	fromcmd1 = dup2(fd0, STDIN_FILENO);
	close(fd0);
	to_outfile = dup2(outfile, STDOUT_FILENO);
	close(outfile);
	if (fromcmd1 < 0 || to_outfile < 0)
	{
		perror("dup2() returns -1");
		exit(EXIT_FAILURE);
	}
	cmd2 = parsing(env, av[3]);
	cmd2_args = ft_split(av[3], ' ');
	execve(cmd2, cmd2_args, env);
	double_free(cmd2_args);
	free(cmd2);
	perror("not lol");
}