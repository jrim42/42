/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:18:05 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 17:24:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//------------- constructor and destructor -------------//

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &ref) : _x(ref._x), _y(ref._y) {}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}

Point::~Point() {}

//------------------------------------------------------//

Fixed	Point::get_x(void) const
{
	return (this->_x);
}

Fixed	Point::get_y(void) const
{
	return (this->_y);
}

Point & Point::operator=(Point const & ref)
{
	(void)ref;
	return (*this);
}
