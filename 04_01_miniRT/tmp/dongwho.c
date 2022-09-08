/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongwho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:44:57 by jrim              #+#    #+#             */
/*   Updated: 2022/09/08 16:02:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define MAX 10000

int	main(void)
{
	char	dh[20];
	FILE	*fp = fopen("goodluck.txt","r");
	char	buf[MAX] = {0,};

	scanf("%s", dh);
	fread(buf, 1, MAX, fp);
	printf("%s", buf);
	return (0);
}