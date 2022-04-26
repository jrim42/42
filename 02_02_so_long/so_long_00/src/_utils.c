/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:32:21 by jrim              #+#    #+#             */
/*   Updated: 2022/04/26 19:38:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_msg_display(char *msg1, int num, char *msg2);

void	_msg_display(char *msg1, int num, char *msg2)
{
	if (msg1 != 0)
		ft_putstr_fd(msg1, 1);
	ft_putnbr_fd(num, 1);
	if (msg2 != 0)
		ft_putstr_fd(msg2, 1);
	write(1, "\n", 1);
}
