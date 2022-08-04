/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:02:51 by jrim              #+#    #+#             */
/*   Updated: 2022/08/04 18:57:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 실행 원리
** 1. used[255] 배열에 argv[2]의 아스키 번호에 따라 1로 만든다. 예를 들어 '0'이 argv[2]에 있으면 used[48] = 1 로 실행한다.
** 2. used[255]와 argv[1]의 아스키 번호에 따라 비교하여 같으면 if문을 실행시켜 argv[1]를 출력한다.
**    그리고 만약 argv[1] 안에서 중복되는 문자가 있어 다시 출력하는 것을 방지하기 위해 한번 출력한 문자에
**    해당되는 used[255] 에 2를 삽입한다.
*/

#include <unistd.h>

void	ft_inter(char **argv);

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv);
	write(1, "\n", 1);
}

void	ft_inter(char **argv)
{
	int	used[255] = {0, };
	int	i;
	int	j;
	
	i = 3;
	while (i-- > 0)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (i == 2 && used[(unsigned char)argv[i][j]] == 0)
				used[(unsigned char)argv[i][j]] = 1;
			else if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
			{
				write(1, &argv[i][j], 1);
				used[(unsigned char)argv[i][j]] = 2;
			}
		}
	}
}