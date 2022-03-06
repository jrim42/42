/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:07 by jrim              #+#    #+#             */
/*   Updated: 2022/03/06 17:27:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(char *msg, int srv_pid);
void	confirm_sig(int sig);
void	check_arg(int argc, char **argv, int *srv_pid);
void	print_dfl_clt(int type, int num);

int	main(int argc, char **argv)
{
	int		clt_pid;
	int		srv_pid;

	check_arg(argc, argv, &srv_pid);
	clt_pid = getpid();
	print_dfl_clt(0, clt_pid);
	print_dfl_clt(1, srv_pid);
	signal(SIGUSR1, confirm_sig);
	signal(SIGUSR2, confirm_sig);
	send_msg(argv[2], srv_pid);
	while (1)
		pause();
	return (0);
}

void	send_msg(char *msg, int srv_pid)
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
				kill(srv_pid, SIGUSR2);
			else
				kill(srv_pid, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(srv_pid, SIGUSR1);
		usleep(100);
	}
}

void	confirm_sig(int sig)
{
	static int	ch_cnt = 0;

	if (sig == SIGUSR1)
		ch_cnt++;
	else
	{
		ft_putstr_fd("> server has received [\033[0;33m", 1);
		ft_putnbr_fd(ch_cnt, 1);
		ft_putstr_fd("\033[0;37m]-character message\n", 1);
		exit(0);
	}
}

void	check_arg(int argc, char **argv, int *srv_pid)
{
	int	idx;

	if (argc != 3)
	{
		ft_putstr_fd("usage : ./client [server pid] [message to send]\n", 1);
		exit(1);
	}
	idx = -1;
	while (argv[1][++idx])
	{
		if (ft_isdigit(argv[1][idx]) == 0)
		{
			ft_putstr_fd("error : invalid pid number\n", 1);
			exit(1);
		}
	}
	*srv_pid = ft_atoi(argv[1]);
	if (*srv_pid <= 100 || *srv_pid > 999998)
	{
		ft_putstr_fd("error : invalid pid number\n", 1);
		exit(1);
	}
}

void	print_dfl_clt(int type, int num)
{
	if (type == 0)
	{
		ft_putstr_fd("> client pid is [\033[0;33m", 1);
		ft_putnbr_fd(num, 1);
		ft_putstr_fd("\033[0;37m]\n", 1);
	}
	else if (type == 1)
	{
		ft_putstr_fd("> message is sent to [\033[0;33m", 1);
		ft_putnbr_fd(num, 1);
		ft_putstr_fd("\033[0;37m]\n", 1);
	}	
}
