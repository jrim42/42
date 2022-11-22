/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:18:04 by jrim              #+#    #+#             */
/*   Updated: 2022/11/22 15:41:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		Point();
		Point(Point const & ref);
		Point(Fixed const x, Fixed const y);
		~Point();

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
		
		Point & operator=(Point const & ref);
};

#endif