/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:41:44 by jrim              #+#    #+#             */
/*   Updated: 2022/12/23 16:37:15 by jrim             ###   ########.fr       */
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
	return (0);
}

