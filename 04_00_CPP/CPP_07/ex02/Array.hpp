#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array 
{
	private:
		std::size_t	_len;
		T			*_content;

	public:
		Array(void);
		Array(std::size_t len);
		Array(const Array& ref);
		Array& operator=(const Array& ref);
		~Array(void);

		class OutOfRangeException : public std::exception 
		{
			public : 
				virtual const char	*what(void) const throw();
		};

		size_t		size(void) const;
		T& 			operator[](std::size_t i);
		const T& 	operator[](std::size_t i) const;
};

# include "Array.tpp"
#endif