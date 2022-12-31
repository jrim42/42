/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:41:05 by jrim              #+#    #+#             */
/*   Updated: 2022/12/31 16:32:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << CONTOUR << std::endl;
    {
		std::cout << GRY << "(test 1: form making)" << DFT << std::endl;
        Intern      someIntern;
        AForm*      wrongForm;

        try
        {
            wrongForm = someIntern.makeForm("bla", "Bender");
        }
        catch (std::exception & e)
        {
            std::cerr << RED << e.what() << DFT << std::endl;
        }
    }
	std::cout << CONTOUR << std::endl;
    {
		std::cout << GRY << "(test 2: form executing)" << DFT << std::endl;
        Bureaucrat  someBureaucrat("Marvin", 1);
        Intern      someIntern;
        AForm*      rrf;
        
        rrf = someIntern.makeForm("RRF", "Bender");    
        someBureaucrat.signForm(*rrf);
        someBureaucrat.executeForm(*rrf);
    }
	// system("leaks ex03 | grep leaked");
	return (0);
}