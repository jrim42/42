/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:41:05 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 17:24:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define CONTOUR "------------------------------------------------------" 

int main(void)
{
    {
        Intern      someRandomIntern;
        AForm*      wrongForm;

        try
        {
            wrongForm = someRandomIntern.makeForm("someRandomForm", "Bender");
        }
        catch (std::exception & e)
        {
            std::cerr << RED << e.what() << DFT << std::endl;
        }
    }
	std::cout << CONTOUR << std::endl;
    {
        Bureaucrat  someRandomBureaucrat("Marvin", 1);
        Intern      someRandomIntern;
        AForm*      rrf;
        
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");    
        someRandomBureaucrat.signForm(*rrf);
        someRandomBureaucrat.executeForm(*rrf);
    }
	return (0);
}