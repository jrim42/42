/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:49:07 by jrim              #+#    #+#             */
/*   Updated: 2022/11/09 19:20:28 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	setName(std::string name);
		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif