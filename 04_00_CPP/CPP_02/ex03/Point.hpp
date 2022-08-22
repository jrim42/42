/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:18:04 by jrim              #+#    #+#             */
/*   Updated: 2022/08/22 12:01:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"
# define GRY "\033[0;30m"

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