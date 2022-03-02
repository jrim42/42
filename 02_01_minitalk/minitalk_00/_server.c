/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:10 by jrim              #+#    #+#             */
/*   Updated: 2022/03/02 19:32:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    recieve_msg(int sig);
void    recieve_len(int sig, int *len, int *cur_bit, char **msg);
void    display_msg(int *len, char **msg, int *idx);
int     ft_power(int num, int cnt);

int main(int argc, char **argv)
{
    int pid;

    if (argc != 1 || argv[1])
    {
        ft_putstr_fd("usage : ./server [no argument needed]", 1);
        return (1);
    }
    pid = getpid();
    ft_putstr_fd("[server pid] : ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, (void *)recieve_msg);
    signal(SIGUSR2, (void *)recieve_msg);
    while (1)
        pause();
    return (0);
}

void    recieve_msg(int sig)
{
    static int  len = 0;
    static int  ch = 0;
    static int  cur_bit = 0;
    static int  idx = 0;
    static char *msg = 0;

    // if (sig == SIGUSR2)
    //     printf("SIGUSR2 = 1\n");
    // else
    //     printf("SIGUSR1 = 0\n");
    if (len == 0)
        recieve_len(sig, &len, &cur_bit, &msg);
    else
    {
        if (sig == SIGUSR2)
            ch += ft_power(2, cur_bit);
        if (cur_bit == 7)
        {
            msg[idx++] = ch;
            cur_bit = 0;
            if (ch == 0)
                return (display_msg(&len, &msg, &idx));
            ch = 0;
            printf("msg[%d] : %c\n", idx - 1, msg[idx - 1]);
            return ;
        }
        cur_bit++;
    }
}

void    recieve_len(int sig, int *len, int *cur_bit, char **msg)
{
    static int  val = 0;

    if (sig == SIGUSR2)
        val += ft_power(2, *cur_bit);
    if (*cur_bit == 31)
    {
        *msg = (char *)malloc((val + 1) * sizeof(char));
        if (!msg)
            exit(1);
        *len = 1;
        *cur_bit = 0;
        val = 0;
        return ;
    }
    (*cur_bit)++;
}

void    display_msg(int *len, char **msg, int *idx)
{
    if (*msg)
    {
        ft_putendl_fd(*msg, 1);
        free(*msg);
        *msg = 0;
    }
    *len = 0;
    *idx = 0;
}

int     ft_power(int num, int cnt)
{
    if (cnt == 0)
        return (1);
    return (num * ft_power(num, cnt - 1));
}
