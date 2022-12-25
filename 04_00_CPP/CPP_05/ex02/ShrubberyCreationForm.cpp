/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:34:16 by jrim              #+#    #+#             */
/*   Updated: 2022/12/25 16:17:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//-------------- orthodox canonical form ----------------//
ShrubberyCreationForm::ShrubberyCreationForm(void) 
	: AForm("ShrubberyCreationForm", 145, 137, "undefined")
{
	// std::cout << GRY << "(ShrubberyCreationForm: default constructor)" << DFT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, target)
{
	// std::cout << GRY << "(ShrubberyCreationForm: constructor)" << DFT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) 
{
	// std::cout << GRY << "(ShrubberyCreationForm: copy constructor)" << DFT << std::endl;
	*this = ref;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	// std::cout << GRY << "(ShrubberyCreationForm: copy assignment)" << DFT << std::endl;
	if (this != &ref) {}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << GRY << "(ShrubberyCreationForm: destructor)" << DFT << std::endl;
}

//----------------------- utils -------------------------//
void	ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	if (this->getExecGrade() < b.getGrade())
		throw GradeTooLowException();
	std::cout << "createShrubbery" << std::endl;
	// this->createShrubbery();
}

void 	ShrubberyCreationForm::createShrubbery(void)
{
	std::string		filename;
	std::ofstream	outfile;

	filename = this->getTarget() + "_shrubbery";
	outfile.open(filename);
	if (outfile.is_open() == false)
	{
		std::cout << "Error: File Creation Failed" << std::endl;
		return ;
	}
	outfile << "ASCIItree.txt";
	outfile.close();
}