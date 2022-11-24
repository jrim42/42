/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:24:54 by jrim              #+#    #+#             */
/*   Updated: 2022/11/24 18:32:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//-------------- orthodox canonical form ----------------//
Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	this->value = num << this->bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed& ref)
{
	this->value = ref.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	this->value = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

//--------------------- getter/setter -------------------//
int Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

//---------------------- converter ---------------------//
int 	Fixed::toInt(void) const
{
	return (value >> bits);
}

float	Fixed::toFloat(void) const
{
	return (float(value) / (1 << bits));
}

//--------------------- operators ---------------------//
bool	Fixed::operator>(const Fixed& ref) const
{
	return (this->value > ref.value);
}

bool	Fixed::operator<(const Fixed& ref) const
{
	return (this->value < ref.value);
}

bool	Fixed::operator>=(const Fixed& ref) const
{
	return (this->value >= ref.value);
}

bool	Fixed::operator<=(const Fixed& ref) const
{
	return (this->value <= ref.value);
}

bool	Fixed::operator==(const Fixed& ref) const
{
	return (this->value == ref.value);
}

bool	Fixed::operator!=(const Fixed& ref) const
{
	return (this->value != ref.value);
}

Fixed	Fixed::operator+(const Fixed& ref) const
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& ref) const
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& ref) const
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& ref) const
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	// std::cout << GRY << "(pre-increment called) " << DFT;
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	// std::cout << GRY << "(post-increment called) " << DFT;
	Fixed	tmp(*this);

	this->value++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	// std::cout << GRY << "(pre-decrement called) " << DFT;
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	// std::cout << GRY << "(post-decrement called) " << DFT;
	Fixed	tmp(*this);

	this->value--;
	return (tmp);
}

//--------------------- min & max ---------------------//
Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

//------------------- insertion operator ----------------//
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}