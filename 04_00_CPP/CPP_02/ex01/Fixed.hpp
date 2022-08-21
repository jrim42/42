/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:21:39 by jrim              #+#    #+#             */
/*   Updated: 2022/08/21 16:45:17 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"
# define GRY "\033[0;30m"

class Fixed 
{
	private:
		int					value;
		const static int	bits = 8;
		
	public:
		Fixed(void);		
		Fixed(const int fixed);					
		Fixed(const float fixed);					
		Fixed(const Fixed &ref);				
		Fixed &	operator=(Fixed const &ref);	
		~Fixed(void);						

		int		getRawBits(void) const;			
		void	setRawBits(int const raw);		

		int 	toInt(void) const;
		float	toFloat(void) const;
};

std::ostream & operator<<(std::ostream &out, const Fixed &fixed);

#endif