/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:26:20 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 20:42:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << BLU << this->name << DFT << " attacks with his ";
	if (this->weapon == NULL)
		std::cout << BLU << "fist" << DFT << std::endl;
	else
		std::cout << BLU << this->weapon->getType() << DFT << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}