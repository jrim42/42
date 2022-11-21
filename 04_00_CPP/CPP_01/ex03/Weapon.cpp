/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:23:24 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 19:40:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//-------------- constructor/destructor ----------------//
Weapon::Weapon(std::string type)
{
	// std::cout << GRY << "(weapon: constructor: " << type <<  ")" << DFT << std::endl;
	this->type = type;
}

Weapon::~Weapon(void)
{
	// std::cout << GRY << "(weapon: destructor)" << DFT << std::endl;
}

//-------------------- getter/setter -------------------//
const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}