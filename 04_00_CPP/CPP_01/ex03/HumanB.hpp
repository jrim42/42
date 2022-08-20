/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:27:16 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 20:43:59 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"

class HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	public:
        HumanB(std::string name);
		~HumanB(void);
		
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif