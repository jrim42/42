/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:18:04 by jrim              #+#    #+#             */
/*   Updated: 2022/11/25 13:23:35 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point& ref);
		Point& operator=(const Point& ref);
		~Point(void);

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
		
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif