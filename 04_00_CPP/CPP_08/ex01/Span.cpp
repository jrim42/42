/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:03 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 17:37:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//-------------- orthodox canonical form ----------------//
Span::Span(void) : _v(0, 0)
{
	// std::cout << GRY << "(Span: default constructor)" << DFT << std::endl;
}

Span::Span(unsigned int N)
{
	// std::cout << GRY << "(Span: constructor)" << DFT << std::endl;
    _v.reserve(N);
}

Span::Span(const Span& ref)
{
	// std::cout << GRY << "(Span: copy constructor)" << DFT << std::endl;
    _v.reserve(ref._v.capacity());
    std::copy(std::begin(ref._v), std::end(ref._v), std::back_inserter(_v));
}

Span&   Span::operator=(const Span& ref)
{
	// std::cout << GRY << "(Span: copy assignment)" << DFT << std::endl;
    if (_v.capacity() != ref._v.capacity())
        return (*this);
    if (this != &ref) 
    {
        _v.clear();
        _v.reserve(ref._v.capacity());
        std::copy(std::begin(ref._v), std::end(ref._v), std::back_inserter(_v));
    }
    return (*this);
}

Span::~Span(void)
{
	// std::cout << GRY << "(Span: destructor)" << DFT << std::endl;
}

//----------------------- utils -------------------------//
void    Span::addNumber(int val)
{
    if (_v.size() == _v.capacity())
        throw OutOfCapacityException();
    _v.push_back(val);
}

std::size_t Span::longestSpan(void) const
{
	if (_v.size() < 2)
		throw NotEnoughElementException();

	size_t	l_span;

	l_span = *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
	return (l_span);
}

std::size_t Span::shortestSpan(void) const
{
	if (_v.size() < 2)
		throw NotEnoughElementException();

	long				s_span = LONG_MAX;
	long				t_span;
	std::vector<int>	tmp = _v;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter + 1 != tmp.end(); iter++) 
	{
		t_span = *(iter + 1) - *iter;
		if (t_span < s_span)
			s_span = t_span;
	}
	return static_cast<std::size_t>(s_span);
}

//-------------------- exceptions -----------------------//
const char *Span::OutOfCapacityException::what(void) const throw()
{
	return ("Error: Out of Capacity");
}

const char *Span::NotEnoughElementException::what(void) const throw()
{
	return ("Error: Not Enough Elements");
}