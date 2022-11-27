/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:48 by jrim              #+#    #+#             */
/*   Updated: 2022/11/27 15:51:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define CONTOUR "-------------------------------------------------------------------------" 
#define NAME1 "C1"
#define NAME2 "C2"

int	main(void)
{
	ClapTrap	c1(NAME1);
	ClapTrap	c2(NAME2);
	
	std::cout << CONTOUR << std::endl;
	c2.attack(NAME1);
	c1.takeDamage(c2.getDamage());
	c1.beRepaired(1);
	std::cout << CONTOUR << std::endl;
	c1.takeDamage(6);
	c1.takeDamage(7);
	c1.attack(NAME2);
	c1.beRepaired(3);
	std::cout << CONTOUR << std::endl;
	return (0);
}