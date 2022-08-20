/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:16:25 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 22:52:37 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	init_harl();
}

Harl::~Harl(void)
{
}

void	Harl::init_harl(void)
{
	level[0].name = "DEBUG";
	level[0].f_ptr = &Harl::debug;
	level[1].name = "INFO";
	level[1].f_ptr = &Harl::info;
	level[2].name = "WARNING";
	level[2].f_ptr = &Harl::warning;
	level[3].name = "ERROR";
	level[3].f_ptr = &Harl::error;
}

void	Harl::complain(std::string input)
{
	for (int i = 0; i < 4; i++)
	{
		if (level[i].name == input)
			(this->*(level[i].f_ptr))();
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
