/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:48 by jrim              #+#    #+#             */
/*   Updated: 2022/11/27 15:10:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define CONTOUR "-------------------------------------------------------------------------" 
#define NAME1 "S1"
#define NAME2 "S2"

int	main(void)
{
	ScavTrap	s1(NAME1);
	ScavTrap	s2(NAME2);

	std::cout << CONTOUR << std::endl;	
	s1.attack(NAME2);
	s2.takeDamage(s1.getDamage());
	s2.takeDamage(80);
	s2.attack(NAME1);
	std::cout << CONTOUR << std::endl;	
	s1.guardGuate();
	std::cout << CONTOUR << std::endl;	
	return (0);
}