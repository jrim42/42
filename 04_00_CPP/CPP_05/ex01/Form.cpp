/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:07 by jrim              #+#    #+#             */
/*   Updated: 2022/11/28 13:06:13 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//-------------- orthodox canonical form ----------------//
Form::Form(void) : _name("unknown"), _signed(false), _s_grade(1), _e_grade(1)
{
	// std::cout << GRY << "(Form: default constructor)" << DFT << std::endl;
}

// Form::Form(std::string name, bool signed, int s_grade, int e_grade)
// {
// 	// std::cout << GRY << "(Form: constructor: " << this->_name << ")" << DFT << std::endl;
// }

Form::Form(const Form& ref)
{
	// std::cout << GRY << "(Form: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Form& Form::operator=(const Form& ref)
{
	// std::cout << GRY << "(Form: copy asignment)" << DFT << std::endl;
	// this->_name = ref._name;
	this->_signed = ref._signed;
	this->_s_grade = ref._s_grade;
	this->_e_grade = ref._e_grade;
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
	return (this->_signed);
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
const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Error: Grade Too High");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Error: Grade Too Low");
}

//----------------------- utils -------------------------//
void	Form::beSigned(Bureaucrat b)
{

}

void	Form::signForm(Bureaucrat b)
{
	
}

//--------------------- insertion -----------------------//
std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out	<< f.getName() << "(signed:" << std::boolalpha << f.getSigned()
		<< ", sign grade: " << f.getSignGrade()
		<< ", execute grade: " << f.getExecGrade() << std::endl;
	return (out);
}