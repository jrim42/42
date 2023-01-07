/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:00 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 18:15:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define CONTOUR "-------------------------------------------------" 

void    test1_NormalCase(void);
void    test2_MoreElements(void);
void    test3_OutOfCapacity(void);
void    test4_NotEnoughElement(void);
void    test5_addByRange(void);

int main(void)
{
    std::cout << CONTOUR << std::endl;
    test1_NormalCase();
    std::cout << CONTOUR << std::endl;
    test2_MoreElements();
    std::cout << CONTOUR << std::endl;
    test3_OutOfCapacity();
    std::cout << CONTOUR << std::endl;
    test4_NotEnoughElement();
    std::cout << CONTOUR << std::endl;
    test5_addByRange();
    return (0);
}

void    test1_NormalCase(void)
{
    std::cout << GRY << "(case1: nomal operation)" << DFT << std::endl;
    Span    sp = Span(5);
    Span    copy = Span(5);

    sp.addNumber(5);
    sp.addNumber(2);
    sp.addNumber(8);
    sp.addNumber(3);
    sp.addNumber(12);
    copy = sp;
    std::cout << "shortestSpan: " << copy.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << copy.longestSpan() << std::endl;
}

void    test2_MoreElements(void)
{
    std::cout << GRY << "(case2: more elements)" << DFT << std::endl;
    Span    sp = Span(10000);
    
    for (int i = 5000; i < 10000; i++)
        sp.addNumber(i);
    for (int i = 0; i < 5000; i++)
        sp.addNumber(i);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
}

void    test3_OutOfCapacity(void)
{
    std::cout << GRY << "(case3: out of capacity)" << DFT << std::endl;
    Span    sp = Span(10);

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        sp.addNumber(rand() % 10);
    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}
}

void    test4_NotEnoughElement(void)
{
    std::cout << GRY << "(case4: not enough element)" << DFT << std::endl;
    Span    sp = Span(1);

    sp.addNumber(42);
    try
    {
        sp.shortestSpan();
    }
    catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}
    try
    {
        sp.longestSpan();
    }
    catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}
}

void    test5_addByRange(void)
{
    std::cout << GRY << "(case5: add by range)" << DFT << std::endl;
    int arr[10] = {1, 12, 2, 17, 3, 5, 23, 8, 30, 1};
    // int arr[11] = {1, 12, 2, 17, 3, 5, 23, 8, 30, 1, 42};
    Span sp(10);

    try
    {
        sp.addByRange(std::begin(arr), std::end(arr));
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DFT << '\n';
    }
}