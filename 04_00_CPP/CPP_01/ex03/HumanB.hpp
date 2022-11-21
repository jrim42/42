/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:27:16 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 19:26:49 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB 
{
	private:
		std::string	name;
		Weapon		*weapon;
		
	public:
        HumanB(std::string name);
		~HumanB(void);
		
		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
};

#endif