/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:40:22 by jrim              #+#    #+#             */
/*   Updated: 2022/11/27 15:17:19 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& ref);
		FragTrap& operator=(const FragTrap& ref);
		~FragTrap(void);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
