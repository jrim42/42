/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:22:34 by jrim              #+#    #+#             */
/*   Updated: 2022/11/28 01:41:55 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		Cat(void);
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		~Cat(void);

		void		makeSound(void) const;
		const Brain	*getBrain(void) const;
};

#endif