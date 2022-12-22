/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:27:49 by jrim              #+#    #+#             */
/*   Updated: 2022/12/22 15:33:14 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//-------------- orthodox canonical form ----------------//
Dog::Dog(void) : Animal()
{
	// std::cout << GRY << "(Dog: default constructor)" << DFT << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& ref)
{
	// std::cout << GRY << "(Dog: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref)
{
	this->type = ref.type;
	this->brain = new Brain(*ref.getBrain());
	return (*this);
}

Dog::~Dog(void)
{
	// std::cout << GRY << "(Dog: destructor)" << DFT << std::endl;
	delete this->brain;
}

//------------------------ utils ------------------------//
void	Dog::makeSound(void) const
{
	std::cout << "woof... woof..." << std::endl;
}

const Brain	*Dog::getBrain(void) const
{
	if (this->brain)
		return (this->brain);
	return (NULL);
}