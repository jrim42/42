/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:40:47 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 16:46:11 by jrim             ###   ########.fr       */
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
		// Bureaucrat 				b("Marvin", 1);
		Bureaucrat 				b("Marvin", 20);
		// Bureaucrat 				b("Marvin", 149);
		ShrubberyCreationForm 	form_s("target_1");
		RobotomyRequestForm 	form_r("target_2");
		PresidentialPardonForm 	form_p("target_3");

		std::cout << b << std::endl;
		std::cout << form_r << std::endl;
		std::cout << form_s << std::endl;
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
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DFT << std::endl;
	}
	return (0);
}