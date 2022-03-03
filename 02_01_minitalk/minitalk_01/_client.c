/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:07 by jrim              #+#    #+#             */
/*   Updated: 2022/03/03 17:03:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_arg(int argc, char **argv, int *srv_pid);
void	display_clt_err(int err_type);
void	action(int sig);
void	send_msg(char *msg, int pid);

int	main(int argc, char **argv)
{
	int		clt_pid;
	int		srv_pid;

	check_arg(argc, argv, &srv_pid);
	clt_pid = getpid();
	ft_putstr_fd("> client pid is [\033[0;33m", 1);
	ft_putnbr_fd(clt_pid, 1);
	ft_putstr_fd("\033[0;37m]\n", 1);
	ft_putstr_fd("> message is sent to [\033[0;33m", 1);
	ft_putnbr_fd(srv_pid, 1);
	ft_putstr_fd("\033[0;37m]\n", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_msg(argv[2], srv_pid);
	while (1)
		pause();
	return (0);
}

void	check_arg(int argc, char **argv, int *srv_pid)
{
	int	idx;

	if (argc != 3)
		display_clt_err(0);
	idx = -1;
	while (argv[1][++idx])
		if (ft_isdigit(argv[1][idx]) == 0)
			display_clt_err(1);
	*srv_pid = ft_atoi(argv[1]);
	if (*srv_pid <= 100 || *srv_pid > 999999)
		display_clt_err(1);
}

void	display_clt_err(int err_type)
{
	if (err_type == 0)
		ft_putstr_fd("usage : ./client [server pid] [message to send]\n", 1);
	else
		ft_putstr_fd("error : invalid pid number\n", 1);
	exit(1);
}

void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		received++;
	else
	{
		ft_putstr_fd("> server has received [\033[0;33m", 1);
		ft_putnbr_fd(received, 1);
		ft_putstr_fd("\033[0;37m] characters\n", 1);
		exit(0);
	}
}

void	send_msg(char *msg, int pid)
{
	int		bit;
	char	ch;

	while (*msg)
	{
		bit = 8;
		ch = *msg++;
		while (bit--)
		{
			if (ch >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}
