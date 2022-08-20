/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:48:23 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 19:48:52 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zom1;
	Zombie *zom2;
	
	zom1 = newZombie("zombie1");
	zom2 = newZombie("zombie2");
    
	randomChump("zombie3");
    
	zom2->announce();
	zom1->announce();
    
	delete zom1;
	delete zom2;
    
	return (0);
}