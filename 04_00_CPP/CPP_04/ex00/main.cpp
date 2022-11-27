/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:03:17 by jrim              #+#    #+#             */
/*   Updated: 2022/11/28 01:32:49 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define CONTOUR "-------------------------------------------------------------------------" 

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "type of j : " << j->getType() << " " << std::endl;
		std::cout << "type of i : " << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete j;
		delete i;
		delete meta;
	}
	std::cout << CONTOUR << std::endl;
	{
		const WrongAnimal* w_meta = new WrongAnimal();
		const WrongAnimal* w = new WrongCat();

		std::cout << "type of w : " << w->getType() << " " << std::endl;
		w->makeSound(); //will output the cat sound!
		
		delete w;
		delete w_meta;	
	}
	return (0);
}