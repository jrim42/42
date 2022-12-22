/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:15:07 by jrim              #+#    #+#             */
/*   Updated: 2022/12/22 22:33:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//-------------- orthodox canonical form ----------------//
Animal::Animal(void) : type("none")
{
	// std::cout << GRY << "(Animal: default constructor)" << DFT << std::endl;
}

Animal::Animal(const Animal& ref)
{
	// std::cout << GRY << "(Animal: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Animal& Animal::operator=(const Animal& ref)
{
	type = ref.type;
	return (*this);
}

Animal::~Animal(void)
{
	// std::cout << GRY << "(Animal: destructor)" << DFT << std::endl;
}

//------------------------ utils ------------------------//
std::string		Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
}