/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:34:08 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 14:38:06 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//------------- constructor and destructor -------------//

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << GRY << "(WrongCat: default constructor)" << DFT << std::endl;
	_type = "wrong cat";
}

WrongCat::WrongCat(const WrongCat & ref) : WrongAnimal()
{
	std::cout << GRY << "(WrongCat: copy constructor)" << DFT << std::endl;
	_type = ref.getType();
}

WrongCat::~WrongCat(void)
{
	std::cout << GRY << "(WrongCat: destructor)" << DFT << std::endl;
}

//------------------------------------------------------//

WrongCat & WrongCat::operator=(WrongCat const & ref)
{
	_type = ref._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "wrong meow..." << std::endl;
}