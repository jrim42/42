/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:44 by jrim              #+#    #+#             */
/*   Updated: 2022/12/31 15:49:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#define CONTOUR "------------------------------------------------------" 

int main(void)
{
	std::cout << CONTOUR << std::endl;
	{
		std::cout << GRY << "(test 1: constructor)" << DFT << std::endl;
		try
		{
			// Form	test("A", 1, 151);
			// Form	test("A", 0, 75);
			Form	test("A", 16, 31);
			std::cout << test;
		}
		catch(std::exception& e)
		{
			std::cout << RED << e.what() << DFT << std::endl;
		}
	}
	std::cout << CONTOUR << std::endl;
	{
		std::cout << GRY << "(test 2: sign grade)" << DFT << std::endl;
		Bureaucrat	a("a", 4);
		Form		A("A", 3, 1);

		std::cout << A;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "\n" << a;
			try
			{
				a.signForm(A);
				a.increaseGrade();
			}
			catch (std::exception& e)
			{
				std::cout << RED << e.what() << DFT << std::endl;
			}
		}
		std::cout << "\n" << A;
	}
	// system("leaks ex01 | grep leaked");
	return (0);
}