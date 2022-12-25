/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:24:59 by jrim              #+#    #+#             */
/*   Updated: 2022/12/25 17:16:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//-------------- orthodox canonical form ----------------//
Intern::Intern(void)
{
	// std::cout << GRY << "(Intern: default constructor)" << DFT << std::endl;
}

Intern::Intern(const Intern& ref)
{
	// std::cout << GRY << "(Intern: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref)
{
	// std::cout << GRY << "(Intern: copy assignment)" << DFT << std::endl;
	if (this != &ref) {}
	return (*this);
}

Intern::~Intern(void)
{
	// std::cout << GRY << "(Intern: destructor)" << DFT << std::endl;
}

//------------------------ utils ------------------------//
AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm		*forms[3];

	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentPardonForm(target);
	
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i]->getName())
			return (forms[i]);
	}
	throw FormatNotFoundException();
}

const char *Intern::FormatNotFoundException::what(void) const throw()
{
	return ("Error: Intern: Format Not Found");
}