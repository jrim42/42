/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:40:47 by jrim              #+#    #+#             */
/*   Updated: 2022/12/27 14:46:50 by jrim             ###   ########.fr       */
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
		// Bureaucrat 				b("Marvin", 149);
		ShrubberyCreationForm 	form_s("target_1");
		RobotomyRequestForm 	form_r("target_2");
		PresidentialPardonForm 	form_p("target_3");

		std::cout << b << std::endl;
		std::cout << form_r << std::endl;
		std::cout << form_s << std::endl;
		std::cout << form_p << std::endl;

		form_s.beSigned(b);
		form_r.beSigned(b);
		form_p.beSigned(b);

		form_s.execute(b);
		form_r.execute(b);
		form_p.execute(b);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}