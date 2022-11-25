/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:18:05 by jrim              #+#    #+#             */
/*   Updated: 2022/11/25 13:25:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//-------------- orthodox canonical form ----------------//
Point::Point(void) : _x(0), _y(0) 
{
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) 
{
}

Point::Point(const Point& ref) : _x(ref._x), _y(ref._y) 
{
}

Point& Point::operator=(const Point& ref)
{
	if (this != &ref)
	{
		const_cast<Fixed&>(this->_x) = ref.get_x();
		const_cast<Fixed&>(this->_y) = ref.get_y();
	}
	return (*this);
}

Point::~Point(void)
{
}

//--------------------- getter/setter -------------------//
Fixed	Point::get_x(void) const
{
	return (this->_x);
}

Fixed	Point::get_y(void) const
{
	return (this->_y);
}


