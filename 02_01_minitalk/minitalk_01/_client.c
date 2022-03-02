/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:07 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 17:54:10 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    check_arg(int argc, char **argv);
void    display_clt_err(int err_type);
void    send_len(int len, int pid);
void    send_msg(char *msg, int pid);

int main(int argc, char **argv)
{
    int     pid;
    char    *msg;
    int     len;
    
    check_arg(argc, argv);
    pid = ft_atoi(argv[1]);
    ft_putstr_fd("[pid] : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    if (pid <= 100 || pid > 999999)
        display_clt_err(1);
    msg = argv[2];
    len = ft_strlen(msg);
    send_len(len, pid);
    send_msg(msg, pid);
    printf("%s\n", msg);
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

void    send_len(int len, int pid)
{
    int bit;

    bit = -1;
    while (++bit < 32)
    {
        if (len & 0x01)
            kill(pid, SIGUSR2);
        else 
            kill(pid, SIGUSR1);
        len = len >> 1;
        usleep(1000);
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
        bit = -1;
        while (++bit < 8)
        {
            if (ch & 0x01)
                kill(pid, SIGUSR2);
            else 
                kill(pid, SIGUSR1);
            ch = ch >> 1;
            usleep(1000);
        }
    }
}