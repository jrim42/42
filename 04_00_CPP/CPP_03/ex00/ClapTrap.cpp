/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:18:05 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 19:50:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//------------- constructor and destructor -------------//

ClapTrap::ClapTrap(): _name("none"), _hit(10), _energy(10), _attack(0)
{
	std::cout << GRY << "(default constructor)" << DFT << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << GRY << "(constructor with name)" << DFT << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref):
	_name(ref._name), _hit(ref._hit), _energy(ref._energy), _attack(ref._attack)
{
	std::cout << GRY << "(copy constructor)" << DFT << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << GRY << "(destructor)" << DFT << std::endl;
}

//---------------------- actions -----------------------//

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << _name 
		<< " attacks " << target 
		<< ", causing " << _attack << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name 
		<< " has got " << amount << " points of damage!" << std::endl;
	if (amount >= _energy)
	{
		_energy = 0;
		std::cout << "RIP, " << _name << "..." << std::endl;
	}
	else
	{
		_energy -= amount;
		std::cout << _energy << " energy points are left for " << _name << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name 
		<< " has been repaired of " << amount 
		<< " points of energy!" << std::endl;
	if (_energy == 0)
	{
		_energy = amount;
		std::cout << "ClapTrap " << _name << " has come back alive with " 
			<< _energy << " of energy points" << std::endl; 
	}
	else
	{
		_energy += amount;
		std::cout << "ClapTrap " << _name << " has gained " << amount << " of energy points, " 
			<< "now having " << _energy << " of energy points." << std::endl;

	}
}

unsigned int	ClapTrap::getDamage(void)
{
	return (_attack);
}