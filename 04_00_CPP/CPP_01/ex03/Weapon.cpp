/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:23:24 by jrim              #+#    #+#             */
/*   Updated: 2022/11/09 20:40:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//-------------- constructor/destructor ----------------//
Weapon::~Weapon(void)
{
	// std::cout << GRY << "(weapon: default constructor)" << DFT << std::endl;
}

Weapon::Weapon(std::string type)
{
	// std::cout << GRY << "(weapon: constructor: " << type <<  ")" << DFT << std::endl;
	this->type = type;
}

//-------------------- getter/setter -------------------//
const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}