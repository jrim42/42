/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:03:17 by jrim              #+#    #+#             */
/*   Updated: 2022/12/22 15:36:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define CONTOUR "---------------------------------------" 

int main(void)
{
	{
		const Animal	*i = new Cat();
		const Animal	*j = new Dog();
		Animal			*k = new Cat();
		Cat				*blackcat;

		blackcat = new Cat((*dynamic_cast<Cat *>(k)));
		std::cout << *blackcat->getBrain();

		delete i;
		delete j;
		delete k;
		delete blackcat;
	}
	std::cout << CONTOUR << std::endl;
	{
		Animal	*animals[10];

		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 1)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
		
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << CONTOUR << std::endl;
	// system("leaks Brains | grep leaked");
	return (0);
}