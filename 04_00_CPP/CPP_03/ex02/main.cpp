/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:48 by jrim              #+#    #+#             */
/*   Updated: 2022/11/27 16:11:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define CONTOUR "-------------------------------------------------------------------------" 
#define NAME1 "S1"
#define NAME2 "F1"

int	main(void)
{
	ScavTrap	s1(NAME1);
	FragTrap	f1(NAME2);

	std::cout << CONTOUR << std::endl;	
	s1.attack(NAME2);
	f1.takeDamage(s1.getDamage());
	f1.attack(NAME1);
	s1.takeDamage(f1.getDamage());
	std::cout << CONTOUR << std::endl;	
	f1.highFivesGuys();
	f1.takeDamage(80);
	f1.highFivesGuys();
	std::cout << CONTOUR << std::endl;
	return (0);
}