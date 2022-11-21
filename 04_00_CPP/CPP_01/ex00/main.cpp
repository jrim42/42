/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:48:23 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 19:11:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	s_zom1("s_zom1");
	Zombie	*h_zom1 = newZombie("h_zom1");
    
	randomChump("s_zom2");
	s_zom1.announce();
	h_zom1->announce();
	
	delete (h_zom1);
	// system("leaks Zombie | grep leaked");
	return (0);
}