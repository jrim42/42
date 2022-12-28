/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:07 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 16:31:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//-------------- orthodox canonical form ----------------//
AForm::AForm(void) 
	: _name("unknown"),
	  _sign(false),
	  _s_grade(150), 
	  _e_grade(150),
	  _target("undefined")
{
	// std::cout << GRY << "(AForm: default constructor)" << DFT << std::endl;
}

AForm::AForm(std::string name, int s_grade, int e_grade, std::string target)
	: _name(name), 
	  _sign(false),
	  _s_grade(s_grade), 
	  _e_grade(e_grade),
	  _target(target)
{
	// std::cout << GRY << "(AForm: constructor: " << this->_name << ")" << DFT << std::endl;
	checkGrade(this->_s_grade, 1, 150);
	checkGrade(this->_e_grade, 1, 150);
}

AForm::AForm(const AForm& ref) 
	: _name(ref._name),
	  _sign(false),
	  _s_grade(ref._s_grade), 
	  _e_grade(ref._e_grade),
	  _target(ref._target)
{
	// std::cout << GRY << "(AForm: copy constructor)" << DFT << std::endl;
}

AForm& AForm::operator=(const AForm& ref)
{
	// std::cout << GRY << "(AForm: copy assignment)" << DFT << std::endl;
	if (this == &ref)
		return (*this);
	this->_sign = ref._sign;
	this->_target = ref._target;
	return (*this);
}

AForm::~AForm(void)
{
	// std::cout << GRY << "(AForm: destructor: " << this->_name << ")" << DFT << std::endl;
}

//----------------------- getter ------------------------//
const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_sign);
}

int	AForm::getSignGrade(void) const
{
	return (this->_s_grade);
}

int	AForm::getExecGrade(void) const
{	
	return (this->_e_grade);
}

const std::string&	AForm::getTarget(void) const
{
	return (this->_target);
}

//----------------------- utils -------------------------//
void	AForm::beSigned(const Bureaucrat& b)
{
	if (this->getSigned() == true)
		throw AlreadySignedException();
	else if (b.getGrade() <= this->_s_grade)
		this->_sign = true;
	else
		throw GradeTooLowException();
}

//---------------------- exception ----------------------//
void	AForm::checkGrade(int grade, int min, int max) const
{
	if (grade < min)
		throw GradeTooHighException();
	else if (grade > max)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Error: AForm: Grade Too High");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Error: AForm: Grade Too Low");
}

const char *AForm::AlreadySignedException::what(void) const throw()
{
	return ("Error: AForm: Already Signed");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Error: AForm: Not Signed");
}

//--------------------- insertion -----------------------//
std::ostream& operator<<(std::ostream& out, const AForm& f)
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