/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:19:07 by jrim              #+#    #+#             */
/*   Updated: 2023/01/05 15:36:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>
# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

template <typename T>
class Array 
{
	private:
		unsigned int	_len;
		T				*_content;

	public:
		Array(void);
		Array(unsigned int len);
		Array(const Array& ref);
		Array& operator=(const Array& ref);
		~Array(void);

		class OutOfRangeException : public std::exception 
		{
			public : 
				virtual const char	*what(void) const throw();
		};

		unsigned int	size(void) const;
		T& 				operator[](unsigned int i);
		const T& 		operator[](unsigned int i) const;
};

# include "Array.tpp"
#endif