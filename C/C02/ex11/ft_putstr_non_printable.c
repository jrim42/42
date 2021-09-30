/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:38:51 by jrim              #+#    #+#             */
/*   Updated: 2021/09/27 10:11:20 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dec2hex(unsigned char c)
{
	int		dec;

	dec = c;
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[dec / 16], 1);
	write(1, &"0123456789abcdef"[dec % 16], 1);
}

void	ft_putstr_non_printable(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			ft_dec2hex((unsigned char)str[i]);
		i++;
	}
}
