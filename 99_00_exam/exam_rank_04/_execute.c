/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _execute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:05:32 by jrim              #+#    #+#             */
/*   Updated: 2022/09/24 15:00:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void exec_cmd(t_base *temp, char **env)
{
	pid_t pid;
	int status;
	int pipe_open;

	pipe_open = 0;
	if (temp->type == TYPE_PIPE || (temp->prev && temp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(temp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0) //child
	{
		if (temp->type == TYPE_PIPE && dup2(temp->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
		if (temp->prev && temp->prev->type == TYPE_PIPE && dup2(temp->prev->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if ((execve(temp->argv[0], temp->argv, env)) < 0)
			exit_execve(temp->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else //parent
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(temp->fd[STDOUT]);
			if (!temp->next || temp->type == TYPE_BREAK)
				close(temp->fd[STDIN]);
		}
		if (temp->prev && temp->prev->type == TYPE_PIPE)
			close(temp->prev->fd[STDIN]);
	}
}

void exec_cmds(t_base *ptr, char **env)
{
	t_base *temp;

	temp = ptr;
	while (temp)
	{
		if (strcmp("cd", temp->argv[0]) == 0)
		{
			if (temp->size < 2)
				exit_cd_1();
			else if (chdir(temp->argv[1]))
				exit_cd_2(temp->argv[1]);
		}
		else
			exec_cmd(temp, env);
		temp = temp->next;
	}
}