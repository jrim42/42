/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:15:07 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 14:21:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//------------- constructor and destructor -------------//

WrongAnimal::WrongAnimal(void) : _type("none")
{
	std::cout << GRY << "(WrongAnimal: default constructor)" << DFT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & ref) : _type(ref._type)
{
	std::cout << GRY << "(WrongAnimal: copy constructor)" << DFT << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << GRY << "(WrongAnimal: destructor)" << DFT << std::endl;
}

//------------------------------------------------------//

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & ref)
{
	_type = ref._type;
	return (*this);
}

std::string		WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{

}