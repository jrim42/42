/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:24:24 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 20:50:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//------------- constructor and destructor -------------//

Brain::Brain(void) 
{
	std::cout << GRY << "(Brain: default constructor)" << DFT << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "...";
}

Brain::Brain(const Brain & ref) 
{
	std::cout << GRY << "(Brain: copy constructor)" << DFT << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = ref.getIdea(i);
}

Brain::~Brain(void) 
{
	std::cout << GRY << "(Brain: destructor)" << DFT << std::endl;
}

//------------------------------------------------------//

Brain & Brain::operator=(Brain const & ref)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ref.getIdea(i);
	return (*this);
}

std::string	Brain::getIdea(const int & idx) const
{
	return (_ideas[idx]);
}

std::ostream& operator<<(std::ostream & out, const Brain & brain)
{
	for (int i = 0; i < 100; i++)
		std::cout << (i + 1) << "th idea : " << brain.getIdea(i) << std::endl;
	return (out);
}