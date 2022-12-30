#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
    private:
        int _num;

    public:
        Span(void);
        Span(int num);
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		~Span(void);

        void    addNumber(int num);
        int     shortestSpan(void);
        int     longestSpan(void);
};

#endif