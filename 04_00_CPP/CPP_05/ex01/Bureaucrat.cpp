/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:18:05 by jrim              #+#    #+#             */
/*   Updated: 2022/11/27 14:58:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//-------------- orthodox canonical form ----------------//
Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	// std::cout << GRY << "(Bureaucrat: default constructor)" << DFT << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// std::cout << GRY << "(Bureaucrat: constructor: " << this->_name << ")" << DFT << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
{
	// std::cout << GRY << "(Bureaucrat: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	// std::cout << GRY << "(Bureaucrat: copy asignment)" << DFT << std::endl;
	// this->_name = ref._name;
	this->_grade = ref._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << GRY << "(Bureaucrat: destructor: " << this->_name << ")" << DFT << std::endl;
}

//----------------------- getter ------------------------//
const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//---------------------- exception ----------------------//
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error: Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error: Grade Too Low");
}

//--------------------- insertion -----------------------//
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out	<< b.getName() << ", bureaucrat grade " 
		<< BLU << b.getGrade() << DFT << "." << std::endl;
	return (out);
}