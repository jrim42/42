/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:36:57 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 17:36:57 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> lst;
	std::deque<int> deq;
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		lst.push_back(i);
		deq.push_back(i);
		vec.push_back(i);
	}

	try
	{
		std::cout << GRY << "(case 1: list) " << DFT;
		// std::cout 	<< *(easyfind(lst, -1)) << " is found at index " 
		// 			<< std::distance(lst.begin(), easyfind(lst, -1)) << std::endl;
		std::cout 	<< *(easyfind(lst, 8)) << " is found at index " 
					<< std::distance(lst.begin(), easyfind(lst, 8)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}

	try
	{
		std::cout << GRY << "(case 2: deque) " << DFT;
		// std::cout 	<< *(easyfind(deq, 42)) << " is found at index " 
		// 			<< std::distance(deq.begin(), easyfind(deq, 42)) << std::endl;
		std::cout 	<< *(easyfind(deq, 6)) << " is found at index " 
					<< std::distance(deq.begin(), easyfind(deq, 6)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}
	
	try
	{
		std::cout << GRY << "(case 3: vector) " << DFT;
		// std::cout	<< *(easyfind(vec, 11)) << " is found at index " 
		// 			<< std::distance(vec.begin(), easyfind(vec, 11)) << std::endl;
		std::cout	<< *(easyfind(vec, 2)) << " is found at index " 
					<< std::distance(vec.begin(), easyfind(vec, 2)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}
	return (0);
}