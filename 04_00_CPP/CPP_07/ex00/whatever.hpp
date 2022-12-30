#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

template<typename T>
void	swap(T& a, T& b)
{
	T	tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(T& a, T& b)
{
	if (a < b) 
		return (a);
	else 
		return (b);
}

template<typename T>
T	max(T& a, T& b)
{
	if (a > b) 
		return (a);
	else 
		return (b);
}

#endif