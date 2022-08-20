/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:59:54 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 20:09:04 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombies;
	int		idx;

	zombies = new Zombie[N];
	idx = -1;
	while (++idx < N)
		zombies[idx].set_name(name + std::to_string(idx));
	return (zombies);
}