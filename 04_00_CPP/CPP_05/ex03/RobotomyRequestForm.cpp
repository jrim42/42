/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:16:09 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 19:50:07 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//-------------- orthodox canonical form ----------------//
RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("RobotomyRequestForm", 72, 45, "undefined")
{
	// std::cout << GRY << "(RobotomyRequestForm: default constructor)" << DFT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45, target)
{
	// std::cout << GRY << "(RobotomyRequestForm: constructor)" << DFT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) 
{
	// std::cout << GRY << "(RobotomyRequestForm: copy constructor)" << DFT << std::endl;
	*this = ref;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	// std::cout << GRY << "(RobotomyRequestForm: copy assignment)" << DFT << std::endl;
	if (this == &ref)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << GRY << "(RobotomyRequestForm: destructor)" << DFT << std::endl;
}

//----------------------- utils -------------------------//
void	RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	if (this->getExecGrade() < b.getGrade())
		throw GradeTooLowException();

	int tmp;

	std::srand(time(NULL));
	tmp = (std::rand() % 2); 
	std::cout << "DRRRRRRRRRRRRR... ";
	if (tmp)
		std::cout 	<< BLU << this->getTarget() << DFT
					<< " has been successfully robotomized." << std::endl;
	else
		std::cout << "robotomy failed..." << std::endl;
}
