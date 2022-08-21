/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:24:54 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 17:14:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//------------- constructor and destructor -------------//

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	Fixed::value = value << bits;
}

Fixed::Fixed(const float value)
{
	Fixed::value = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &ref)
{
	(*this) = ref;
}

Fixed::~Fixed(void)
{
}

//--------------------- operators ---------------------//

Fixed & Fixed::operator=(Fixed const &ref)
{
	value = ref.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &ref) const
{
	return (this->value > ref.value);
}

bool	Fixed::operator<(Fixed const &ref) const
{
	return (this->value < ref.value);
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	return (this->value >= ref.value);
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	return (this->value <= ref.value);
}

bool	Fixed::operator==(Fixed const &ref) const
{
	return (this->value == ref.value);
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return (this->value != ref.value);
}

Fixed	Fixed::operator+(Fixed const &ref) const
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &ref) const
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &ref) const
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &ref) const
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed &	Fixed::operator++(void)
{
	// std::cout << GRY << "(pre-increment called) " << DFT;
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	// std::cout << GRY << "(post-increment called) " << DFT;
	this->value++;
	return (tmp);
}

Fixed & Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->value--;
	return (tmp);
}

std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

//--------------------- min & max ---------------------//

Fixed &	Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed const & Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed &	Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

Fixed const & Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

//-----------------------------------------------------//

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
