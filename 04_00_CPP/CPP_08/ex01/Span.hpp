#ifndef SPAN_HPP
# define SPAN_HPP

# include <array>
# include <algorithm>
# include <cstddef>
# include <exception>
# include <numeric>
# include <iostream>
# include <utility>
# include <vector>

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

        void        addNumber(int val);
        std::size_t shortestSpan(void) const;
        std::size_t longestSpan(void) const;
};

#endif