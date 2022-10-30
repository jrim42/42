/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:27:08 by jrim              #+#    #+#             */
/*   Updated: 2022/10/30 22:52:04 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//-------------- constructor/destructor ----------------//
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

//------------------------ utils -----------------------//
void	HumanA::attack(void)
{
	std::cout 	<< RED << this->name << DFT << " attacks with his " 
				<< RED << weapon.getType() << DFT << std::endl;
}