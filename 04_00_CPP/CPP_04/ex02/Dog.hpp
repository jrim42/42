/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:27:10 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 20:37:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	
	public:
		Dog(void);
		Dog(const Dog & ref);
		~Dog(void);
		
		Dog & 	operator=(Dog const & ref);

		void		makeSound(void) const;
		const Brain	*getBrain(void) const;

};

#endif