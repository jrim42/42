/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:48:23 by jrim              #+#    #+#             */
/*   Updated: 2022/10/30 18:33:57 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;
	int		idx;

	zombies = zombieHorde(5, "zom");
	idx = -1;
	while (++idx < 5)
		zombies[idx].announce();
    
	delete [] zombies;
	// std::cout << std::endl;
	// system("leaks zombieHorde | grep leaked");
	return (0);
}