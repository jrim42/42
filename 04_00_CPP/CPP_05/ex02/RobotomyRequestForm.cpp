/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:16:09 by jrim              #+#    #+#             */
/*   Updated: 2022/12/31 16:19:32 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//-------------- orthodox canonical form ----------------//
RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("RRF", 72, 45, "undefined")
{
	// std::cout << GRY << "(RobotomyRequestForm: default constructor)" << DFT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RRF", 72, 45, target)
{
	// std::cout << GRY << "(RobotomyRequestForm: constructor)" << DFT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) 
	: AForm("RRF", 72, 45, ref.getTarget())
{
	// std::cout << GRY << "(RobotomyRequestForm: copy constructor)" << DFT << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	// std::cout << GRY << "(RobotomyRequestForm: copy assignment)" << DFT << std::endl;
	if (this == &ref)
		return (*this);
	this->setTarget(ref.getTarget());
	this->setSigned(ref.getSigned());
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

	std::srand(time(NULL));
	std::cout << "DRRRRRRRRRRRRR... ";
	if (std::rand() % 2)
		std::cout 	<< BLU << this->getTarget() << DFT
					<< " has been successfully robotomized." << std::endl;
	else
		std::cout << "robotomy failed..." << std::endl;
}
