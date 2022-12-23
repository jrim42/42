/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:34:08 by jrim              #+#    #+#             */
/*   Updated: 2022/12/23 11:36:38 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//-------------- orthodox canonical form ----------------//
WrongCat::WrongCat(void) : WrongAnimal()
{
	// std::cout << GRY << "(WrongCat: default constructor)" << DFT << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& ref)
{
	// std::cout << GRY << "(WrongCat: copy constructor)" << DFT << std::endl;
	*this = ref;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	type = ref.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	// std::cout << GRY << "(WrongCat: destructor)" << DFT << std::endl;
}

//------------------------ utils ------------------------//
void	WrongCat::makeSound(void) const
{
}