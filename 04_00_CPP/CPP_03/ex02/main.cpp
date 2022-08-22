/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:48 by jrim              #+#    #+#             */
/*   Updated: 2022/08/22 12:44:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define NAME1 "\033[0;31mS1\033[0;37m"
#define NAME2 "\033[0;36mS2\033[0;37m"

int	main(void)
{
	ScavTrap	s1(NAME1);
	FragTrap	s2(NAME2);

	std::cout << "---------------------------------------" << std::endl;	
	s1.attack(NAME2);
	s2.takeDamage(s1.getDamage());
	std::cout << "---------------------------------------" << std::endl;	
	s2.attack(NAME1);
	s1.takeDamage(s2.getDamage());
	std::cout << "---------------------------------------" << std::endl;	
	s1.guardGuate();
	s2.highFivesGuys();
	std::cout << "---------------------------------------" << std::endl;	
	return (0);
}