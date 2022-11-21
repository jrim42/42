/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:25:34 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 19:27:03 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA 
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		
		void	attack(void) const;
};
#endif