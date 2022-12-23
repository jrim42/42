/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:03:17 by jrim              #+#    #+#             */
/*   Updated: 2022/12/23 11:37:13 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define CONTOUR "---------------------------------------" 

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		
		std::cout << "type of i: " << i->getType() << " " << std::endl;
		std::cout << "type of j: " << j->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();		//will output the cat sound
		j->makeSound();		//will output the dog sound

		delete j;
		delete i;
		delete meta;
	}
	std::cout << CONTOUR << std::endl;
	{
		const WrongAnimal* w_meta = new WrongAnimal();
		const WrongAnimal* w = new WrongCat();

		std::cout << "type of w: " << w->getType() << " " << std::endl;
		w_meta->makeSound(); 	//will output wrong sound
		w->makeSound(); 		//will output wrong sound
		
		delete w;
		delete w_meta;	
	}
	// std::cout << CONTOUR << std::endl;
	// system("leaks ex00 | grep leaked");
	return (0);
}