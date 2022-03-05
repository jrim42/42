/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/05 22:54:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_msg(int sig, siginfo_t *info, void *context);
void	print_ch(char ch, int *clt_pid);
void	print_dfl_msg_srv(int type, int num);

int	main(int argc, char **argv)
{
	int					srv_pid;
	struct sigaction	s_sigaction;

	if (argc != 1 || argv[1])
	{
		ft_putstr_fd("usage : ./server [no argument is needed]\n", 1);
		return (1);
	}
	srv_pid = getpid();
	print_dfl_msg_srv(0, srv_pid);
	s_sigaction.sa_sigaction = recieve_msg;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}

void	recieve_msg(int sig, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static pid_t	clt_pid = 0;
	static char		ch = 0;

	(void)context;
	if (clt_pid == 0)
	{
		clt_pid = info->si_pid;
		print_dfl_msg_srv(1, clt_pid);
	}
	ch |= (sig == SIGUSR2);
	if (++bit == 8)
	{
		bit = 0;
		print_ch(ch, &clt_pid);
		ch = 0;
	}
	else
		ch <<= 1;
}

void	print_ch(char ch, int *clt_pid)
{
	if (ch == 0)
	{
		kill(*clt_pid, SIGUSR2);
		(*clt_pid) = 0;
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	ft_putchar_fd(ch, 1);
	kill(*clt_pid, SIGUSR1);
}

void	print_dfl_msg_srv(int type, int num)
{
	if (type == 0)
	{
		ft_putstr_fd("> server pid is [\033[0;33m", 1);
		ft_putnbr_fd(num, 1);
		ft_putstr_fd("\033[0;37m]\n", 1);
	}
	else if (type == 1)
	{
		ft_putstr_fd("> message from [\033[0;33m", 1);
		ft_putnbr_fd(num, 1);
		ft_putstr_fd("\033[0;37m] : ", 1);
	}
}
