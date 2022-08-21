/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:24:54 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 16:49:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << GRN << "Int" << DFT << " constructor called" << std::endl;
	Fixed::value = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << BLU << "Float" << DFT << " constructor called" << std::endl;
	Fixed::value = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = ref;
}

Fixed &Fixed::operator=(Fixed const &ref)
{
	std::cout << RED << "Assignation" << DFT << " operation called" << std::endl;
	value = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int 	Fixed::toInt(void) const
{
	return (value >> bits);
}

float	Fixed::toFloat(void) const
{
	return (float(value) / (1 << bits));
}

std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
	std::cout << GRY << "(ostream operator called) " << DFT;
	out << fixed.toFloat();
	return (out);
}