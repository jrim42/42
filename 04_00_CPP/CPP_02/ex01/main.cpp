/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:20:33 by jrim              #+#    #+#             */
/*   Updated: 2022/11/22 17:02:55 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	std::cout << "------------------ a ------------------" << std::endl;
	Fixed a;
	std::cout << "------------------ b ------------------" << std::endl;
	Fixed const b(10);
	std::cout << "------------------ c ------------------" << std::endl;
	Fixed const c(42.42f);
	std::cout << "------------------ d ------------------" << std::endl;
	Fixed const d(b);

	std::cout << "------------------ a ------------------" << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	return (0);
}