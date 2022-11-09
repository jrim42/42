/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:49:46 by jrim              #+#    #+#             */
/*   Updated: 2022/11/09 19:20:57 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//-------------- constructor/destructor ----------------//
Zombie::Zombie(void)
{
	// std::cout << GRY << "(constructor)" << DFT << std::endl;
}

Zombie::Zombie(std::string name)
{
	// std::cout << GRY << "(constructor: " << name << ")" << DFT << std::endl;
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << RED << this->name << " is gone..." << DFT << std::endl;
	// std::cout << GRY << "(destructor: " << this->name << ")" << DFT << std::endl;
}

//------------------------ utils -----------------------//
void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}