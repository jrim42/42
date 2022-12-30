#include "Span.hpp"

//-------------- orthodox canonical form ----------------//
Span::Span(void) : _v(0, 0)
{
	// std::cout << GRY << "(Span: default constructor)" << DFT << std::endl;
}

Span::Span(unsigned int len)
{
	// std::cout << GRY << "(Span: constructor)" << DFT << std::endl;
    _v.reserve(len);
}

Span::Span(const Span& ref)
{
	// std::cout << GRY << "(Span: copy constructor)" << DFT << std::endl;
    this->_v.reserve(ref._v.capacity());
    std::copy(std::begin(ref._v), std::end(ref._v), std::back_inserter(this->_v));
}

Span&   Span::operator=(const Span& ref)
{
	// std::cout << GRY << "(Span: copy assignment)" << DFT << std::endl;
    if (this->_v.capacity() != ref._v.capacity())
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
    {
        std::cout << "Error: out of capacity" << std::endl;
        return ;
    }
    _v.push_back(val);
}

std::size_t Span::longestSpan(void) const
{
	if (_v.size() <= 2)
		throw std::logic_error("vector size is not over 2");
	return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()) );
}

std::size_t Span::shortestSpan(void) const
{
	if (_v.size() <= 2)
		throw std::logic_error("vector size is not over 2");

	long ret = LONG_MAX;
	int prev;
	std::vector<int> tmp = _v;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++) 
	{
		if (iter == tmp.begin()) 
			prev = *iter;
		else 
		{
			if (ret > *iter - prev) 
				ret = *iter - prev;
			prev = *iter;
		}
	}
	return static_cast<std::size_t>(ret);
}
