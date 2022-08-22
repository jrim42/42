/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:01:03 by jrim              #+#    #+#             */
/*   Updated: 2022/08/22 12:35:30 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//------------- constructor and destructor -------------//

ScavTrap::ScavTrap(): ClapTrap(), _keeper(false)
{
	std::cout << GRY << "(ScavTrap: default constructor)" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _keeper(false)
{
	std::cout << GRY << "(ScavTrap: constructor with name)" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << GRY << "(ScavTrap: destructor)" << DFT << std::endl;
}

//---------------------- operator -----------------------//

ScavTrap & ScavTrap::operator=(ScavTrap const & ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

//---------------------- actions -----------------------//

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << _name 
		<< " attacks " << target 
		<< ", causing " << _attack << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << _name 
		<< " has got " << amount << " points of damage! ";
	if (amount >= _energy)
	{
		_energy = 0;
		std::cout << "RIP, " << _name << "..." << std::endl;
	}
	else
	{
		_energy -= amount;
		std::cout << _energy << " energy points left." << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << _name 
		<< " has been repaired of " << amount 
		<< " points of energy!" << std::endl;
	if (_energy == 0)
	{
		_energy = amount;
		std::cout << "ScavTrap " << _name << " has come back alive with " 
			<< _energy << " of energy points" << std::endl; 
	}
	else
	{
		_energy += amount;
		std::cout << "ScavTrap " << _name << " has gained " << amount << " of energy points, " 
			<< "now having " << _energy << " of energy points." << std::endl;

	}
}

unsigned int	ScavTrap::getDamage(void)
{
	return (_attack);
}


void	ScavTrap::guardGuate(void)
{
	if (_energy == 0)
		return ;
	std::cout << "ScavTrap " << _name << " is now in a gate keeper mode" << std::endl;
	this->_keeper = true;
}