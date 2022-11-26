/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:57:59 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 17:52:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

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