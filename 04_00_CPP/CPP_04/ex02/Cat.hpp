/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:22:34 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 20:37:26 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
		
	public:
		Cat(void);
		Cat(const Cat & ref);
		~Cat(void);
		
		Cat & 	operator=(Cat const & ref);

		void		makeSound(void) const;
		const Brain	*getBrain(void) const;
};

#endif