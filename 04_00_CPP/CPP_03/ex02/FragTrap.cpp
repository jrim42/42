/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:40:59 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 18:03:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//-------------- orthodox canonical form ----------------//
FragTrap::FragTrap(): ClapTrap()
{
	std::cout << GRY << "(FragTrap: default constructor)" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << GRY << "(FragTrap: constructor: " << this->_name << ")" << DFT << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap(const FragTrap& ref)
{
	std::cout << GRY << "(FragTrap: copy constructor: " << this->_name << ")" << DFT << std::endl;
	*this = ref;
}

FragTrap & FragTrap::operator=(FragTrap const & ref)
{
	std::cout << GRY << "(FragTrap: copy asignment)" << DFT << std::endl;
	this->_name = ref._name;
	this->_hit = ref._hit;
	this->_energy = ref._energy;
	this->_attack = ref._attack;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << GRY << "(FragTrap: destructor: " << this->_name << ")" << DFT << std::endl;
}

//------------------------ utils ------------------------//
void	FragTrap::attack(std::string const & target)
{
	if (this->_energy == 0 || this->_hit == 0)
		std::cout	<< "FragTrap " << this->_name << " cannot attack " << target << "..." << std::endl;
	else
	{
		std::cout	<< "FragTrap " << this->_name << " attacks " << target << ", causing " 
					<< RED << this->_attack << DFT << " points of damage!" << std::endl;
		this->_energy--;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "FragTrap " << this->_name << " has got " 
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

void	FragTrap::highFivesGuys(void)
{
	if (this->_hit == 0)
		std::cout	<< "FragTrap " << this->_name << " cannot request positive highfive..." << std::endl;
	else
		std::cout 	<< RED << "positive high fives " << DFT
					<< "request from FragTrap " << _name << "!" << std::endl;
}