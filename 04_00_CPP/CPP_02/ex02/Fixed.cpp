/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:24:54 by jrim              #+#    #+#             */
/*   Updated: 2022/11/22 17:13:00 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//-------------- orthodox canonical form ----------------//
Fixed::Fixed(void)
{
	// std::cout << GRY << "Default constructor called" << DFT << std::endl;
	this->value = 0;
}

Fixed::Fixed(int num)
{
	// std::cout << BLU << "Int" << DFT << " constructor called" << std::endl;
	this->value = num << this->bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << BLU << "Float" << DFT << " constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &ref)
{
	// std::cout << GRY << "Copy constructor called" << DFT << std::endl;
	this->value = ref.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &ref)
{
	// std::cout << GRY << "Copy assignment operator called" << DFT << std::endl;
	this->value = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << GRY << "Destructor called" << DFT << std::endl;
}

//--------------------- getter/setter -------------------//
int Fixed::getRawBits(void) const
{
	// std::cout << GRY << "getRawBits member function called" << DFT << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << GRY << "setRawBits member function called" << DFT << std::endl;
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

//------------------- insertion operator ----------------//
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	// std::cout << GRY << "(insertion operator called) " << DFT;
	out << fixed.toFloat();
	return (out);
}