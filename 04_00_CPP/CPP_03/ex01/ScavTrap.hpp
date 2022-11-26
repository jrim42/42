/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:57:59 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 17:49:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class ScavTrap : public ClapTrap
{
	private:
		bool			_keeper;
	
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ref);
		ScavTrap& operator=(const ScavTrap& ref);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	guardGuate(void);
};

#endif