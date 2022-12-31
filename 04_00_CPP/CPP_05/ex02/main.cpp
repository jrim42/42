/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:40:47 by jrim              #+#    #+#             */
/*   Updated: 2022/12/31 16:17:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat 				b("Tim", 20);
		// Bureaucrat 				b("Ben", 1);
		ShrubberyCreationForm 	scf("t1");
		RobotomyRequestForm 	rrf("t2");
		PresidentialPardonForm 	ppf("t3");

		std::cout << CONTOUR << std::endl;
		std::cout << b ;
		std::cout << rrf << scf << ppf;
	
		std::cout << CONTOUR << std::endl;
		b.executeForm(scf);
		b.signForm(scf);
		b.executeForm(scf);

		std::cout << CONTOUR << std::endl;
		b.signForm(rrf);
		b.signForm(rrf);
		b.executeForm(rrf);

		std::cout << CONTOUR << std::endl;
		b.signForm(ppf);
		b.executeForm(ppf);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DFT << std::endl;
	}
	// system("leaks ex02 | grep leaked");
	return (0);
}