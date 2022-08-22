/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:40:59 by jrim              #+#    #+#             */
/*   Updated: 2022/08/22 12:43:20 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//------------- constructor and destructor -------------//

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << GRY << "(FragTrap: default constructor)" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << GRY << "(FragTrap: constructor with name)" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::~FragTrap()
{
	std::cout << GRY << "(FragTrap: destructor)" << DFT << std::endl;
}

//---------------------- operator -----------------------//

FragTrap & FragTrap::operator=(FragTrap const & ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

//---------------------- actions -----------------------//

void	FragTrap::highFivesGuys(void)
{
	std::cout << "positive high fives request from FragTrap " << _name << "!" << std::endl;
}
