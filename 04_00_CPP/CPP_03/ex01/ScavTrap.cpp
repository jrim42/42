/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:01:03 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 20:16:02 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//------------- constructor and destructor -------------//

ScavTrap::ScavTrap(): ClapTrap(), _gate_keeper(false)
{
	std::cout << GRY << "(ScavTrap: default constructor)" << DFT << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap & ref): ClapTrap(ref), _gate_keeper(ref._gate_keeper)
{
	std::cout << GRY << "(ScavTrap: constructor with name)" << DFT << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _gate_keeper(false)
{
	std::cout << GRY << "(ScavTrap: copy constructor)" << DFT << std::endl;
	_name = name;
	_hit = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << GRY << "(ScavTrap: destructor)" << DFT << std::endl;
}

//---------------------- actions -----------------------//

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << _name 
		<< " attacks " << target 
		<< ", causing " << _attack << " points of damage!" << std::endl;
}

void	ScavTrap::guardGuate(void)
{
	std::cout << "ScavTrap " << _name 
		<< " is now in a gate keeper mode" << std::endl;
	this->_gate_keeper = true;
}