/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:48 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 18:00:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define NAME1 "S1"
#define NAME2 "F1"

int	main(void)
{
	ScavTrap	s1(NAME1);
	FragTrap	f1(NAME2);

	std::cout << "---------------------------------------" << std::endl;	
	s1.attack(NAME2);
	f1.takeDamage(s1.getDamage());
	f1.attack(NAME1);
	s1.takeDamage(f1.getDamage());
	std::cout << "---------------------------------------" << std::endl;	
	s1.guardGuate();
	f1.highFivesGuys();
	std::cout << "---------------------------------------" << std::endl;	
	return (0);
}