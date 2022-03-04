/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/04 10:02:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_msg(int sig, siginfo_t *info, void *context);

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
	ft_putstr_fd("> server pid is [\033[0;33m", 1);
	ft_putnbr_fd(srv_pid, 1);
	ft_putstr_fd("\033[0;37m]\n", 1);
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
	static int		idx = 0;
	static pid_t	clt_pid = 0;
	static char		ch = 0;

	(void)context;
	if (clt_pid == 0)
	{
		clt_pid = info->si_pid;
		ft_putstr_fd("> message from [\033[0;33m", 1);
		ft_putnbr_fd(clt_pid, 1);
		ft_putstr_fd("\033[0;37m] : ", 1);
	}
	ch |= (sig == SIGUSR2);
	if (++idx == 8)
	{
		idx = 0;
		if (ch == 0)
		{
			kill(clt_pid, SIGUSR2); //if msg is over, send SIGUSER2 to client
			clt_pid = 0;
			ft_putstr_fd("\n", 1);
			exit(0);
			// return ;
		}
		ft_putchar_fd(ch, 1);
		ch = 0;
		kill(clt_pid, SIGUSR1); //if msg isn't over, send SIGUSER1 to client
	}
	else
		ch <<= 1;
}
