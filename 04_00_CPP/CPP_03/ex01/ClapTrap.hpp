/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:17:56 by jrim              #+#    #+#             */
/*   Updated: 2022/11/26 17:48:57 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ref);
		ClapTrap& operator=(const ClapTrap& ref);
		virtual ~ClapTrap(void);

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getDamage(void);
};

#endif