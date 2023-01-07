/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:05 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 18:15:44 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Span
{
    private:
        std::vector<int>    _v;

    public:
        Span(void);
        Span(unsigned int len);
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		~Span(void);

        void    addNumber(int val);

        std::size_t shortestSpan(void) const;
        std::size_t longestSpan(void) const;

        class OutOfCapacityException : public std::exception 
		{
			public : 
				virtual const char	*what(void) const throw();
		};
        class NotEnoughElementException : public std::exception 
		{
			public : 
				virtual const char	*what(void) const throw();
		};

        template <typename T>
        void    addByRange(T begin, T end)
        {
            int distance = std::distance(begin, end);
            int leftover = static_cast<int>(_v.capacity() - _v.size());

            if (distance > leftover)
                throw OutOfCapacityException();
            while (begin < end)
            {
                _v.push_back(*begin);
                begin++;
            }
        }
};

#endif