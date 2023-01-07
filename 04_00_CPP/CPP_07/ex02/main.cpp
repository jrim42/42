/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:19:13 by jrim              #+#    #+#             */
/*   Updated: 2023/01/05 16:30:43 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
#define CONTOUR "-------------------------------------------------" 

int main(int, char**)
{
    Array<int>  numbers(MAX_VAL);
    int         *mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int   value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // deep copy test
	std::cout << CONTOUR << std::endl;
    {
        Array<int> temp = numbers;
        Array<int> test(temp);
        Array<int> copy;

        copy = test;
        std::cout << "temp : " << temp[0] << " -> ";
        temp[0] = 42;
        std::cout << temp[0] << std::endl;
        std::cout << "test : " << test[0] << " -> ";
        test[0] = 4242;
        std::cout << test[0] << std::endl;
        std::cout << "copy : " << copy[0] << std::endl;
        copy = test;
        std::cout << "copy : " << copy[0] << std::endl;
    }
	std::cout << CONTOUR << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return (1);
        }
    }
    // content change: case 1
    try
    {
        std::cout << GRY << "(case 1) " << DFT;
        std::cout << numbers[4] << " -> ";
        numbers[4] = 424242;
        std::cout << numbers[4] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DFT << '\n';
    }
    // content change: case 2
    try
    {
        std::cout << GRY << "(case 2) " << DFT;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DFT << '\n';
    }
    // content change: case 3
    try
    {
        std::cout << GRY << "(case 3) " << DFT;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DFT << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;
	std::cout << CONTOUR << std::endl;
    system("leaks ex02 | grep leaked");
    return (0);
}