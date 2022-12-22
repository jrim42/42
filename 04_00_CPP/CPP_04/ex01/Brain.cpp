/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:24:24 by jrim              #+#    #+#             */
/*   Updated: 2022/12/22 15:32:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//-------------- orthodox canonical form ----------------//
Brain::Brain(void) 
{
	// std::cout << GRY << "(Brain: default constructor)" << DFT << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "...";
}

Brain::Brain(const Brain& ref) 
{
	// std::cout << GRY << "(Brain: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Brain& Brain::operator=(const Brain& ref)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref.getIdea(i);
	return (*this);
}

Brain::~Brain(void) 
{
	// std::cout << GRY << "(Brain: destructor)" << DFT << std::endl;
}

//------------------------ utils ------------------------//
std::string	Brain::getIdea(const int& idx) const
{
	return (this->ideas[idx]);
}

std::ostream& operator<<(std::ostream& out, const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		std::cout << (i + 1) << "th idea : " << brain.getIdea(i) << std::endl;
	return (out);
}