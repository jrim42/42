/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:44 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 15:05:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define CONTOUR "---------------------------------------" 

int main(void)
{
	{
		try
		{
			Bureaucrat test("test", 151);
			// Bureaucrat test("test", 0);
			// Bureaucrat test("test", 75);
			std::cout << test;
		}
		catch (std::exception& e)
		{
			std::cout << RED << e.what() << DFT << std::endl;
		}
	}
	std::cout << CONTOUR << std::endl;
	{
		Bureaucrat	a("a", 3);
		int			cnt = 3;
		
		while (cnt--)
		{
			std::cout << a;
			try
			{
				a.increaseGrade();
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

