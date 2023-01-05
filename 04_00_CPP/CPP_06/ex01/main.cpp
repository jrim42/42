/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:07:52 by jrim              #+#    #+#             */
/*   Updated: 2023/01/03 19:34:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#define CONTOUR "------------------------"

int main(int argc, char **argv)
{
    Data        data1;
	Data        *data2;
	uintptr_t   ptr;

	if (argc != 2)
    {
        std::cout << "Error: Wrong Input Format" << std::endl;
        return (0);
    }
	data1.setName(argv[1]);
	ptr = serialize(&data1);
	data2 = deserialize(ptr);
	std::cout << CONTOUR << std::endl;
	std::cout << data1;
	std::cout << CONTOUR << std::endl;
	std::cout << "ptr : " << ptr << std::endl;
	std::cout << CONTOUR << std::endl;
	std::cout << *data2;
	// system("leaks ex01 | grep leaked");
	return (0);
}
