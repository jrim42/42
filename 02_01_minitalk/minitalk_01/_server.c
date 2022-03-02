/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 20:57:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    action(int sig, siginfo_t *info, void *context);
int     ft_power(int num, int cnt);

int main(int argc, char **argv)
{
    int                 pid;
    struct sigaction    s_sigaction; 

    if (argc != 1 || argv[1])
    {
        ft_putstr_fd("usage : ./server [no argument needed]", 1);
        return (1);
    }
    pid = getpid();
    ft_putstr_fd("[server pid] : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    s_sigaction.sa_sigaction = action;
    s_sigaction.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s_sigaction, NULL);
    sigaction(SIGUSR2, &s_sigaction, NULL);
    while (1)
        pause();
    return (0);
}

void    action(int sig, siginfo_t *info, void *context)
{
    static int      idx = 0;
    static pid_t    clt_pid = 0;
    static int      ch = 0;

    (void)context;
    if (clt_pid == 0)
        clt_pid = info->si_pid;
    ch |= (sig == SIGUSR2);
    if (++idx == 8)
    {
        idx = 0;
        if (ch == 0)
        {
            kill(clt_pid, SIGUSR2);
            clt_pid = 0;
            return ;
        }
        ft_putchar_fd(ch, 1);
        ch = 0;
        kill(clt_pid, SIGUSR1);
    }
    else
        ch <<= 1;
}