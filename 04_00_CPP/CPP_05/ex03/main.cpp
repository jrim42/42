/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:41:05 by jrim              #+#    #+#             */
/*   Updated: 2022/12/27 16:10:49 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Bureaucrat  someRandomBureaucrat("Marvin", 1);
    Intern      someRandomIntern;
    AForm*      rrf;
    
    try
    {
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");    
        // rrf = someRandomIntern.makeForm("someRandomForm", "Bender");
        rrf->beSigned(someRandomBureaucrat);
        rrf->execute(someRandomBureaucrat);
    }
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}