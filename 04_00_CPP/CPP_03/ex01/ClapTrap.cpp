/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:18:05 by jrim              #+#    #+#             */
/*   Updated: 2022/11/27 15:01:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//-------------- orthodox canonical form ----------------//
ClapTrap::ClapTrap(void): _name("unknown"), _hit(10), _energy(10), _attack(0)
{
	std::cout << GRY << "(ClapTrap: default constructor)" << DFT << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << GRY << "(ClapTrap: constructor: " << this->_name << ")" << DFT << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << GRY << "(ClapTrap: copy constructor)" << DFT << std::endl;
	*this = ref;
}

ClapTrap & ClapTrap::operator=(const ClapTrap& ref)
{
	std::cout << GRY << "(ClapTrap: copy asignment)" << DFT << std::endl;
	this->_name = ref._name;
	this->_hit = ref._hit;
	this->_energy = ref._energy;
	this->_attack = ref._attack;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GRY << "(ClapTrap: destructor: " << this->_name << ")" << DFT << std::endl;
}

//------------------------ utils ------------------------//
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy == 0 || this->_hit == 0)
		std::cout	<< "ClapTrap " << this->_name << " cannot attack " << target << "..." << std::endl;
	else
	{
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target << ", causing " 
					<< RED << this->_attack << DFT << " points of damage!" << std::endl;
		this->_energy--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "ClapTrap " << this->_name << " has got " 
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0 || this->_hit == 0)
		std::cout	<< "ClapTrap " << this->_name << " cannot repair itself..." << std::endl;
	else
	{
		this->_hit += amount;
		std::cout	<< "ClapTrap " << this->_name << " has been repaired of " 
					<< RED << amount << DFT << " points, now having "
					<< RED << this->_hit << DFT << " of hit points." << std::endl; 
		this->_energy--;
	}
}

unsigned int	ClapTrap::getDamage(void)
{
	return (this->_attack);
}
