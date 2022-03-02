/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:07 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 20:58:20 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    check_arg(int argc, char **argv);
void    display_clt_err(int err_type);
void    action(int sig);
void    send_msg(char *msg, int pid);

int main(int argc, char **argv)
{
    int     pid;
    char    *msg;
    
    check_arg(argc, argv);
    pid = ft_atoi(argv[1]);
    ft_putstr_fd("[pid] : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    if (pid <= 100 || pid > 999999)
        display_clt_err(1);
    ft_putstr_fd("[received] : ", 1);
    signal(SIGUSR1, action);
    signal(SIGUSR2, action);
    msg = argv[2];
    send_msg(msg, pid);
    while (1)
        pause();
    return (0);
}

void check_arg(int argc, char **argv)
{
    int idx;

    if (argc != 3)
        display_clt_err(0);
    idx = -1;
    while (argv[1][++idx])
        if (ft_isdigit(argv[1][idx]) == 0)
            display_clt_err(1);
}

void    display_clt_err(int err_type)
{
    if (err_type == 0)
        ft_putstr_fd("[usage] : ./client [server pid] [message to send]", 1);
    else 
        ft_putstr_fd("[error] : ", 1);
    if (err_type == 1)
        ft_putendl_fd("invalid pid", 1);
    else if (err_type == 2)
        ft_putendl_fd("error type 2", 1);
    exit(1);
}

void    action(int sig)
{
    static int  received = 0;

    if (sig == SIGUSR1)
        ++received;
    else
    {
        ft_putchar_fd(received, 1);
        ft_putchar_fd('\n', 1);
        exit(0);
    }
}

void    send_msg(char *msg, int pid)
{
    int idx;
    int bit;
    int ch;

    idx = -1;
    while (msg[++idx])
    {
        ch = (int)msg[idx];
        bit = 8;
        while (bit--)
        {
            if (ch >> bit & 0x01)
                kill(pid, SIGUSR2);
            else 
                kill(pid, SIGUSR1);
            ch = ch >> 1;
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