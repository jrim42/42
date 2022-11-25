/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:18:05 by jrim              #+#    #+#             */
/*   Updated: 2022/11/25 17:20:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//-------------- orthodox canonical form ----------------//
Point::Point(void) : x(0), y(0) 
{
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) 
{
}

Point::Point(const Point& ref) : x(ref.x), y(ref.y) 
{
}

Point& Point::operator=(const Point& ref)
{
	if (this != &ref)
	{
		const_cast<Fixed&>(this->x) = ref.getX();
		const_cast<Fixed&>(this->y) = ref.getY();
	}
	return (*this);
}

Point::~Point(void)
{
}

//--------------------- getter/setter -------------------//
Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}


