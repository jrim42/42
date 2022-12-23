/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:03:17 by jrim              #+#    #+#             */
/*   Updated: 2022/12/23 11:44:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define CONTOUR "---------------------------------------" 

int main(void)
{
	// Animal *err = new Animal();		// wrong!
	Animal	*i = new Cat();
	Animal	*j = new Dog();

	i->makeSound();
	j->makeSound();
	
	delete i;
	delete j;
	// std::cout << CONTOUR << std::endl;
	// system("leaks ex02 | grep leaked");
	return (0);
}