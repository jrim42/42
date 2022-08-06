/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:21:53 by jrim              #+#    #+#             */
/*   Updated: 2022/08/06 12:59:30 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

// 	1 : read one line
// 	0 : read last line (EOF)
// -1 : error 

// get_next_line
int	get_next_line(char **line);

// utils
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int ch);
char	*ft_strndup(char *str, int len);
char	*ft_strjoin(char *s1, char *s2);

//------------------- get_next_line ---------------------//

int	get_next_line(char **line)
{
	static char	*depot;
	char		*buf;
	int			byte;
	char		*tmp;
	char		*eol;

	buf = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buf)
		return (ERROR);
	if (!depot)
	{
		depot = ft_strndup("", 0);
		while ((byte = read(0, buf, 1)) > 0)
		{
			buf[byte] = '\0';
			tmp = depot;
			depot = ft_strjoin(depot, buf);
			free(tmp);
		}
	}
	free(buf);
	eol = ft_strchr(depot, '\n');
	if (eol)
	{
		*line = ft_strndup(depot, eol - depot);
		depot += eol - depot + 1;
		return (ONE_LINE);
	}
	else
	{
		*line = ft_strndup(depot, ft_strchr(depot, '\0') - depot);
		return (LAST_LINE);
	}
}

//------------------------ utils ------------------------//

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, int ch)
{
	int	len;
	int i;

	len = ft_strlen(str) + 1;
	i = -1;
	while (++i < len)
	{
		if (str[i] == (char)ch)
			return(str + i);
	}
	return (NULL);
}

char	*ft_strndup(char *str, int len)
{
	char	*new_str;
	int 	i;

	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*new_str;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return (NULL);
	while (++i < s1_len)
		new_str[i] = s1[i];
	while (i - s1_len < s2_len)
		new_str[i] = s2[i - s1_len];
	new_str[i] = '\0';
	return (new_str);
}
