/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:27:30 by jrim              #+#    #+#             */
/*   Updated: 2022/08/06 13:01:00 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int main(void)
{
	char 	*line;
	int			ret;

	line = NULL;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d %s\n", ret, line);
	free(line);
}