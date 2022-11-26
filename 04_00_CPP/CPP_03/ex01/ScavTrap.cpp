/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:01:03 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 18:04:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//-------------- orthodox canonical form ----------------//
ScavTrap::ScavTrap(): ClapTrap(), _keeper(false)
{
	std::cout << GRY << "(ScavTrap: default constructor)" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _keeper(false)
{
	std::cout << GRY << "(ScavTrap: constructor: " << this->_name << ")" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
	std::cout << GRY << "(ScavTrap: copy constructor)" << DFT << std::endl;
	*this = ref;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << GRY << "(ScavTrap: copy asignment)" << DFT << std::endl;
	this->_name = ref._name;
	this->_hit = ref._hit;
	this->_energy = ref._energy;
	this->_attack = ref._attack;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << GRY << "(ScavTrap: destructor: " << this->_name << ")" << DFT << std::endl;
}

//------------------------ utils ------------------------//
void	ScavTrap::attack(std::string const & target)
{
	if (this->_energy == 0 || this->_hit == 0)
		std::cout	<< "ScavTrap " << this->_name << " cannot attack " << target << "..." << std::endl;
	else
	{
		std::cout	<< "ScavTrap " << this->_name << " attacks " << target << ", causing " 
					<< RED << this->_attack << DFT << " points of damage!" << std::endl;
		this->_energy--;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "ScavTrap " << this->_name << " has got " 
				<< RED << amount << DFT << " points of damage! ";
	if (amount >= this->_hit)
	{
		this->_hit = 0;
		std::cout << "RIP, " << this->_name << "..." << std::endl;
	}
	else
	{
		this->_hit -= amount;
		std::cout << RED << this->_hit << DFT << " hit points left." << std::endl;
	}
}

void	ScavTrap::guardGuate(void)
{
	if (this->_hit == 0)
		std::cout	<< "ScavTrap " << this->_name << " cannot enter gate keeper mode..." << std::endl;
	else
	{
		std::cout 	<< "ScavTrap " << _name << " is now in a "
					<< RED << "gate keeper mode" << DFT << std::endl;
		this->_keeper = true;
	}
}