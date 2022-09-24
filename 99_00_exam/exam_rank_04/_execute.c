/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _execute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:32 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 17:20:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microsh.h"

void msh_exec(t_info *ptr, char **env)
{
	t_info	*tmp;

	tmp = ptr;
	while (tmp)
	{
		if (strcmp("cd", tmp->argv[0]) == 0)
		{
			if (tmp->size < 2)
				exit_cd_1();
			else if (chdir(tmp->argv[1]))
				exit_cd_2(tmp->argv[1]);
		}
		else
			exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}

void exec_cmd(t_info *tmp, char **env)
{
	pid_t	pid;
	int 	status;
	int 	pipe_open;

	pipe_open = 0;
	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
		exec_child(tmp, env);
	else
		exec_parent(tmp, pid, &status, pipe_open);
}

void exec_parent(t_info *tmp, pid_t pid, int *status, int pipe_open)
{
	waitpid(pid, status, 0);
	if (pipe_open)
	{
		close(tmp->fd[STDOUT]);
		if (!tmp->next || tmp->type == TYPE_BREAK)
			close(tmp->fd[STDIN]);
	}
	if (tmp->prev && tmp->prev->type == TYPE_PIPE)
		close(tmp->prev->fd[STDIN]);
}

void exec_child(t_info *tmp, char **env)
{
	if (tmp->type == TYPE_PIPE && dup2(tmp->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
	if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->prev->fd[STDIN], STDIN) < 0)
		exit_fatal();
	if ((execve(tmp->argv[0], tmp->argv, env)) < 0)
		exit_execve(tmp->argv[0]);
	exit(EXIT_SUCCESS);
}