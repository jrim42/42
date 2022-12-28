/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:40:47 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 18:14:38 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define CONTOUR "---------------------------------------" 

int main(void)
{
	try
	{
		Bureaucrat 				b("Marvin", 20);
		// Bureaucrat 				b("Marvin", 1);
		ShrubberyCreationForm 	form_s("t1");
		RobotomyRequestForm 	form_r("t2");
		PresidentialPardonForm 	form_p("t3");

		std::cout << b << std::endl;
		std::cout << form_r;
		std::cout << form_s;
		std::cout << form_p << std::endl;

		b.executeForm(form_s);
		b.signForm(form_s);
		b.executeForm(form_s);

		std::cout << std::endl;
		b.signForm(form_r);
		b.signForm(form_r);
		b.executeForm(form_r);

		std::cout << std::endl;
		b.signForm(form_p);
		b.executeForm(form_p);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DFT << std::endl;
	}
	// system("leaks ex02 | grep leaked");
	return (0);
}