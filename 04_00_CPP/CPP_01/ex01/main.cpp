/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:48:23 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 19:13:36 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;

	zombies = zombieHorde(5, "zom");
	for (int idx = 0; idx < 5; idx++)
		zombies[idx].announce();
    
	delete [] zombies;
	// system("leaks zombieHorde | grep leaked");
	return (0);
}