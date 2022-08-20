/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:22:38 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 20:23:40 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon 
{
	private:
		std::string	type;
		Weapon(void);

	public:
		Weapon(std::string type);
		~Weapon(void);
		
		void	setType(std::string type);
		const std::string	&getType(void);
};

#endif