/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:44 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 18:16:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#define CONTOUR "------------------------------------------------------" 

int main(void)
{
	{
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
		Form	test("A", 16, 31);
		Form	copy1;

		std::cout << copy1;
		copy1 = test;
		std::cout << copy1;
	}
	std::cout << CONTOUR << std::endl;
	{
		Bureaucrat	a("a", 4);
		Form		A("A", 3, 1);
		int			cnt = 3;

		std::cout << A;
		while (cnt--)
		{
			std::cout << std::endl;
			std::cout << a;
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