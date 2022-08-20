/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:23:24 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 20:24:12 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}