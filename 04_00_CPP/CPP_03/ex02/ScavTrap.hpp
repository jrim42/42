/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:57:59 by jrim              #+#    #+#             */
/*   Updated: 2022/08/22 12:26:11 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"
# define GRY "\033[0;30m"

class ScavTrap : public ClapTrap
{
	private:
		bool			_keeper;
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const & ref);

		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getDamage(void);
		
		void			guardGuate(void);
};

#endif