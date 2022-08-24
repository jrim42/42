/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:15:07 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 14:30:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//------------- constructor and destructor -------------//

Animal::Animal(void) : _type("none")
{
	std::cout << GRY << "(Animal: default constructor)" << DFT << std::endl;
}

Animal::Animal(const Animal & ref) : _type(ref._type)
{
	std::cout << GRY << "(Animal: copy constructor)" << DFT << std::endl;
}

Animal::~Animal(void)
{
	std::cout << GRY << "(Animal: destructor)" << DFT << std::endl;
}

//------------------------------------------------------//

Animal & Animal::operator=(Animal const & ref)
{
	_type = ref._type;
	return (*this);
}

std::string		Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{

}