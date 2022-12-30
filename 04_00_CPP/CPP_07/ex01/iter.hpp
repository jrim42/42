#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

template<typename T>
void	iter (T *array, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void	display(T& content)
{
	std::cout << content << " ";
}

template<typename T>
void	increment(T& num)
{
	num += 1;
}

#endif