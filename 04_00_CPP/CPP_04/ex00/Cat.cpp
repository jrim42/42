/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:24:45 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 14:35:09 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//------------- constructor and destructor -------------//

Cat::Cat(void) : Animal()
{
	std::cout << GRY << "(Cat: default constructor)" << DFT << std::endl;
	_type = "cat";
}

Cat::Cat(const Cat & ref) : Animal()
{
	std::cout << GRY << "(Cat: copy constructor)" << DFT << std::endl;
	_type = ref.getType();
}

Cat::~Cat(void)
{
	std::cout << GRY << "(Cat: destructor)" << DFT << std::endl;
}

//------------------------------------------------------//

Cat & Cat::operator=(Cat const & ref)
{
	_type = ref._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meow... meow..." << std::endl;
}