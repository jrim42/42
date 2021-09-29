/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ch_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:30:28 by nakkim            #+#    #+#             */
/*   Updated: 2021/09/29 18:48:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_map.h"

char	*get_ch_map(void)
{
	int		byte;
	char	*buff;

	byte = 1;
	buff = (char *)malloc(sizeof(char) * 10000001);
	while (byte == 1)
		byte = read(0, buff, 1000);
	if (byte < 5)
	{
		free(buff);
		return (0);
	}
	if (!get_input(buff, byte))
		return (0);
	return (buff);
}

int	get_input(char *buff, int byte)
{
	int	index;
	int	lines;
	int	digit;

	index = byte - 5;
	lines = 0;
	digit = 1;
	while (index >= 0)
	{
		if (!(buff[index] >= '0' && buff[index] <= '9'))
		{
			free(buff);
			return (0);
		}
		lines += (buff[index--] - 48) * digit;
		digit *= 10;
	}
	while (lines-- > 0)
		byte += read(0, buff + byte, 1000);
	buff[byte] = '\0';
	return (1);
}
