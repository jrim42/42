/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:48 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 17:30:35 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define NAME1 "S1"
#define NAME2 "S2"

int	main(void)
{
	ScavTrap	s1(NAME1);
	ScavTrap	s2(NAME2);

	std::cout << "---------------------------------------" << std::endl;	
	s1.attack(NAME2);
	s2.takeDamage(s1.getDamage());
	std::cout << "---------------------------------------" << std::endl;	
	s2.attack(NAME1);
	s1.takeDamage(s2.getDamage());
	std::cout << "---------------------------------------" << std::endl;	
	s2.guardGuate();
	std::cout << "---------------------------------------" << std::endl;	
	return (0);
}