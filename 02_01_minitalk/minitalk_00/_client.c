/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _client.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:07 by jrim              #+#    #+#             */
/*   Updated: 2022/02/26 21:31:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    int srv_pid;

    if (argc != 3)
        err_display(0); //client input error
    srv_pid = ft_atoi(argv[1]);
    if (srv_pid == 0)
        err_display(0); //pid error
    return (0);
}