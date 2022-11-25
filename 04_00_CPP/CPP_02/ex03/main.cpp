/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:20:33 by jrim              #+#    #+#             */
/*   Updated: 2022/11/25 17:27:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) 
{
	Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 30);
	Point	p1(10, 15);
	Point	p2(30, 50);
	Point	p3(10, 30);

	// case 1 : in
	if (bsp(a, b, c, p1) == true)
		std::cout << "p1 is " << BLU << "in" << DFT << " the triangle" << std::endl;
	else
		std::cout << "p1 is " << RED << "out" << DFT << " of the triangle" << std::endl;
	
	// case 2 : out
	if (bsp(a, b, c, p2) == true)
		std::cout << "p2 is " << BLU << "in" << DFT << " the triangle" << std::endl;
	else
		std::cout << "p2 is " << RED << "out" << DFT << " of the triangle" << std::endl;
	
	// case 3 : out
	if (bsp(a, b, c, p3) == true)
		std::cout << "p3 is " << BLU << "in" << DFT << " the triangle" << std::endl;
	else
		std::cout << "p3 is " << RED << "out" << DFT << " of the triangle" << std::endl;
}