/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:07 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 16:21:36 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//-------------- orthodox canonical form ----------------//
Form::Form(void) 
	: _name("unknown"),
	  _sign(false),
	  _s_grade(150), 
	  _e_grade(150)
{
	// std::cout << GRY << "(Form: default constructor)" << DFT << std::endl;
}

Form::Form(std::string name, int s_grade, int e_grade)
	: _name(name), 
	  _sign(false),
	  _s_grade(s_grade), 
	  _e_grade(e_grade)
{
	// std::cout << GRY << "(Form: constructor: " << this->_name << ")" << DFT << std::endl;
	checkGrade(this->_s_grade, 1, 150);
	checkGrade(this->_e_grade, 1, 150);
}

Form::Form(const Form& ref) 
	: _name(ref._name),
	  _sign(false),
	  _s_grade(ref._s_grade), 
	  _e_grade(ref._e_grade)
{
	// std::cout << GRY << "(Form: copy constructor)" << DFT << std::endl;
}

Form& Form::operator=(const Form& ref)
{
	// std::cout << GRY << "(Form: copy assignment)" << DFT << std::endl;
	if (this == &ref)
		return (*this);
	return (*this);
}

Form::~Form(void)
{
	// std::cout << GRY << "(Form: destructor: " << this->_name << ")" << DFT << std::endl;
}

//----------------------- getter ------------------------//
const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_sign);
}

int	Form::getSignGrade(void) const
{
	return (this->_s_grade);
}

int	Form::getExecGrade(void) const
{	
	return (this->_e_grade);
}

//---------------------- exception ----------------------//
void	Form::checkGrade(int grade, int min, int max) const
{
	if (grade < min)
		throw GradeTooHighException();
	else if (grade > max)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Error: Form: Grade Too High");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Error: Form: Grade Too Low");
}

const char *Form::AlreadySignedException::what(void) const throw()
{
	return ("Error: Form: Already Signed");
}

//----------------------- utils -------------------------//
void	Form::beSigned(const Bureaucrat& b)
{
	if (this->getSigned() == true)
		throw AlreadySignedException();
	else if (b.getGrade() <= this->_s_grade)
		this->_sign = true;
	else
		throw GradeTooLowException();
}

//--------------------- insertion -----------------------//
std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out	<< f.getName();
	if (f.getSigned() == true)
		out << ", signed ";
	else
		out << ", unsigned ";
	out	<< "(sign grade: " << f.getSignGrade()
		<< ", execute grade: " << f.getExecGrade() << ")" << std::endl;
	return (out);
}