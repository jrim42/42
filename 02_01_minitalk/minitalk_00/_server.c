/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 14:45:00 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    display_srv_err(void);

int main(int argc, char **argv)
{
    int pid;

    if (argc != 1)
        display_srv_err();
    pid = getpid();
    //pid display
    ft_putstr_fd("server pid : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    //
    signal(SIGUSR1, );
    signal(SIGUSR2, );
    return (0);
}

void    display_srv_err(void)
{
    ft_putstr_fd("usage : ./server [no argument needed]", 1);
    exit(1);
}