/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:06:48 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 14:17:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"
# define GRY "\033[0;30m"

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(const Animal & ref);
		virtual ~Animal(void);

		Animal & operator=(Animal const & ref);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif