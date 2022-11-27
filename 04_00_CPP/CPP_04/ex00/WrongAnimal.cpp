/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:15:07 by jrim              #+#    #+#             */
/*   Updated: 2022/11/28 01:23:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//-------------- orthodox canonical form ----------------//
WrongAnimal::WrongAnimal(void) : type("none")
{
	// std::cout << GRY << "(WrongAnimal: default constructor)" << DFT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	// std::cout << GRY << "(WrongAnimal: copy constructor)" << DFT << std::endl;
	*this = ref;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	type = ref.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	// std::cout << GRY << "(WrongAnimal: destructor)" << DFT << std::endl;
}

//------------------------ utils ------------------------//
std::string		WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
}