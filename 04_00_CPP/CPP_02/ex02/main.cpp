/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:20:33 by jrim              #+#    #+#             */
/*   Updated: 2022/11/22 17:09:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "  a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "  a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "  a : " << a << std::endl;
	std::cout << "  b : " << b << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "max : " << Fixed::max(a, b) << std::endl;
	std::cout << "min : " << Fixed::min(a, b) << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	return (0);
}