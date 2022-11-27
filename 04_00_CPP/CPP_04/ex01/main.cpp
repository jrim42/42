/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:03:17 by jrim              #+#    #+#             */
/*   Updated: 2022/11/28 01:48:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define CONTOUR "---------------------------------------" 


int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << CONTOUR << std::endl;	
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
	
	std::cout << CONTOUR << std::endl;	
	Cat		*shorthair;
	
	shorthair = new Cat((*dynamic_cast<Cat *>(animals[1])));
	std::cout << *shorthair->getBrain() << std::endl;
	
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return (0);
}