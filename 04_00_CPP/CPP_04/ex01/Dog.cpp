/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:27:49 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 20:54:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

//------------- constructor and destructor -------------//

Dog::Dog(void) : Animal()
{
	std::cout << GRY << "(Dog: default constructor)" << DFT << std::endl;
	_type = "dog";
	_brain = new Brain();
}

Dog::Dog(const Dog & ref) : Animal()
{
	std::cout << GRY << "(Dog: copy constructor)" << DFT << std::endl;
	_type = ref.getType();
	_brain = new Brain(*ref.getBrain());
}

Dog::~Dog(void)
{
	std::cout << GRY << "(Dog: destructor)" << DFT << std::endl;
	delete _brain;
}

//------------------------------------------------------//

Dog & Dog::operator=(Dog const & ref)
{
	_type = ref._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "woof..! woof..!" << std::endl;
}

const Brain	*Dog::getBrain(void) const
{
	if (_brain)
		return (_brain);
	return (NULL);
}