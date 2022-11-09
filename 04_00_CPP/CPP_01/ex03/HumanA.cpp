/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:27:08 by jrim              #+#    #+#             */
/*   Updated: 2022/11/09 20:40:30 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//-------------- constructor/destructor ----------------//
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	// std::cout << GRY << "(humanA: constructor: " << name << ")" << DFT << std::endl;
}

HumanA::~HumanA(void)
{
	// std::cout << GRY << "(humanA: destructor: " << this->name << ")" << DFT << std::endl;
}

//------------------------ utils -----------------------//
void	HumanA::attack(void)
{
	std::cout 	<< RED << this->name << DFT << " attacks with his " 
				<< RED << weapon.getType() << DFT << std::endl;
}