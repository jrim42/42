/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:21:39 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 16:24:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed 
{
	private:
		int					value;
		const static int	bits = 8;
		
	public:
		Fixed(void);							// default constructor that initializes the fixed-point number value to 0.
		Fixed(const Fixed &ref);				// copy constructor.
		Fixed &	operator=(Fixed const &ref);	// copy assignment operator overload.
		~Fixed(void);							// destructor
		int		getRawBits(void) const;			// returns the raw value of the fixed-point value
		void	setRawBits(int const raw);		//  sets the raw value of the fixed-point number
};

#endif