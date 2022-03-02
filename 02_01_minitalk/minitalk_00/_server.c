/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 16:22:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    display_srv_err(void);
void    sig_handler(int sig);
int     bin2dec(long long num);
int     ft_power(int num, int cnt);
void    recieve_len(int *cur_bit);

int main(int argc, char **argv)
{
    int pid;
    int idx;

    if (argc != 1)
        display_srv_err();
    pid = getpid();
    //pid display
    ft_putstr_fd("server pid : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    //
    idx = 0;
    // signal(SIGINT, (void *)ft_handler);
    // while (1)
    // {
    //     pause();
    //     idx++;
    // }
    signal(SIGUSR1, (void *)sig_handler);
    signal(SIGUSR2, (void *)sig_handler);
    return (0);
}

void    sig_handler(int sig)
{
    static int  cnt = 0;
    static char str[8];
    int         cd;

    str[cnt] = sig + 48;
    cnt++;
    if (cnt > 7)
    {
        cnt = 0;
        cd = bin2dec(ft_atoi(str));
        ft_putnbr_fd(cd, 1);
    }
}

int     ft_power(int num, int cnt)
{
    if (cnt == 0)
        return (1);
    return (num * ft_power(num, cnt - 1));
}

int     bin2dec(long long num)
{
    int dec;
    int cnt;

    dec = 0;
    cnt = 0;
    while (num > 0)
    {
        dec += (num % 10) * ft_power(2, cnt);
        num /= 10;
        cnt++;
    }
    return (dec);
}

void    display_srv_err(void)
{
    ft_putstr_fd("usage : ./server [no argument needed]", 1);
    exit(1);
}