/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:40:22 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 18:00:37 by jrim             ###   ########.fr       */
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
		
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	highFivesGuys(void);
};

#endif
