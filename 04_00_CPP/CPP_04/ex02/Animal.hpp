/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:06:48 by jrim              #+#    #+#             */
/*   Updated: 2022/12/21 01:48:00 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal& ref);
		Animal& operator=(const Animal& ref);
		virtual ~Animal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif