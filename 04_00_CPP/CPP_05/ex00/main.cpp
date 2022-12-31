/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:44 by jrim              #+#    #+#             */
/*   Updated: 2022/12/31 15:40:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define CONTOUR "---------------------------------------" 

int main(void)
{
	std::cout << CONTOUR << std::endl;
	{
		std::cout << GRY << "(test 1: constructor)" << DFT << std::endl;
		try
		{
			// Bureaucrat test1("a", 151);
			// Bureaucrat test1("a", 0);
			Bureaucrat test1("a", 75);
			std::cout << test1;
		}
		catch (std::exception& e)
		{
			std::cout << RED << e.what() << DFT << std::endl;
		}
	}
	std::cout << CONTOUR << std::endl;
	{
		std::cout << GRY << "(test 2: grade increment)" << DFT << std::endl;
		Bureaucrat	test2("b", 3);
		
		std::cout << test2;
		for (int i = 0; i < 3; i++)
		{
			try
			{
				test2.increaseGrade();
				std::cout << test2;
			}
			catch (std::exception& e)
			{
				std::cout << RED << e.what() << DFT << std::endl;
			}
		}
	}
	// system("leaks ex00 | grep leaked");
	return (0);
}

