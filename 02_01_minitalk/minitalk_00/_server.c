/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 15:35:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    display_srv_err(void);
void    sig_handler(int sig);
void    recieve_len(int *cur_bit);
void    ft_handler(int sig);

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

}

void ft_handler(int sig)
{
    printf("signal recieved.(%d)\n", SIGINT);
    sleep(2);
}

void    display_srv_err(void)
{
    ft_putstr_fd("usage : ./server [no argument needed]", 1);
    exit(1);
}