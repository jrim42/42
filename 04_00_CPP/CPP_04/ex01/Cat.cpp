/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:24:45 by jrim              #+#    #+#             */
/*   Updated: 2022/12/22 15:35:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//-------------- orthodox canonical form ----------------//
Cat::Cat(void) : Animal()
{
	// std::cout << GRY << "(Cat: default constructor)" << DFT << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& ref)
{
	// std::cout << GRY << "(Cat: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Cat& Cat::operator=(const Cat& ref)
{
	this->type = ref.type;
	this->brain = new Brain(*ref.getBrain());
	return (*this);
}

Cat::~Cat(void)
{
	// std::cout << GRY << "(Cat: destructor)" << DFT << std::endl;
	delete this->brain;
}

//------------------------ utils ------------------------//
void	Cat::makeSound(void) const
{
	std::cout << "meow... meow..." << std::endl;
}

const Brain	*Cat::getBrain(void) const
{
	if (this->brain)
		return (this->brain);
	return (NULL);
}