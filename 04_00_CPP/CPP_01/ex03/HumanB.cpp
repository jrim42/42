/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:26:20 by jrim              #+#    #+#             */
/*   Updated: 2022/11/09 20:40:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//-------------- constructor/destructor ----------------//
HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
	// std::cout << GRY << "(humanB: constructor: " << name << ")" << DFT << std::endl;
}

HumanB::~HumanB(void)
{
	// std::cout << GRY << "(humanA: destructor: " << this->name << ")" << DFT << std::endl;
}

//------------------------ utils -----------------------//
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << BLU << this->name << DFT << " attacks with his ";
	if (this->weapon == NULL)
		std::cout << BLU << "fist" << DFT << std::endl;
	else
		std::cout << BLU << this->weapon->getType() << DFT << std::endl;
}