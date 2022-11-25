/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:25:31 by jrim              #+#    #+#             */
/*   Updated: 2022/11/25 17:24:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	checkPosition(Point const p1, Point const p2, Point const q1, Point const q2);
Fixed	getSlope(Point const p1, Point const p2);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// m(x - x1) - (y - y1) = 0
	// mx - y + (-m * x1 + y1) = 0
	// y = mx + n
	if (checkPosition(a, b, c, point) == false)
		return (false);
	if (checkPosition(b, c, a, point) == false)
		return (false);
	if (checkPosition(c, a, b, point) == false)
		return (false);
	return (true);
}

bool	checkPosition(Point const p1, Point const p2, Point const q1, Point const q2)
{
	Fixed	m;
	Fixed	n;

	if (p1.getX() - p2.getX() == 0)
	{
		if ((q1.getX() - p1.getX()) * (q2.getX() - p1.getX()) <= 0)
			return (false);
	}
	else
	{
		m = getSlope(p1, p2);
		n = (m * -1 * p1.getX()) + p1.getY();
		if ((m * q1.getX() - q1.getY() + n) * (m * q2.getX() - q2.getY() + n) <= 0)
			return (false);
	}
	return (true);
}

Fixed	getSlope(Point const p1, Point const p2)
{
	Fixed	denom;
	Fixed	numer;

	denom = p2.getX() - p1.getX();
	numer = p2.getY() - p1.getY();
	if (numer == 0)
		return (0);
	else 
		return (numer / denom);
}