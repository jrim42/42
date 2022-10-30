/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:16:25 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 00:27:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//-------------- constructor/destructor ----------------//
Harl::Harl(void)
{
	init_harl();
}

Harl::~Harl(void)
{
}

//------------------------ init ------------------------//
void	Harl::init_harl(void)
{
	complains[0].level = "DEBUG";
	complains[0].f_ptr = &Harl::debug;
	complains[1].level = "INFO";
	complains[1].f_ptr = &Harl::info;
	complains[2].level = "WARNING";
	complains[2].f_ptr = &Harl::warning;
	complains[3].level = "ERROR";
	complains[3].f_ptr = &Harl::error;
}

//----------------------- complain ---------------------//
void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (complains[i].level == level)
			(this->*(complains[i].f_ptr))();
	}
}

void	Harl::debug(void)
{
	std::cout	<< BLU
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
				<< DFT << std::endl;
}

void	Harl::info(void)
{
	std::cout 	<< GRN
				<< "I cannot believe adding extra bacon costs more money. " 
				<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" 
				<< DFT << std::endl;
}

void	Harl::warning(void)
{
	std::cout 	<< YLW
				<<  "I think I deserve to have some extra bacon for free. "
				<< "I've been coming for years whereas you started working here since last month." 
				<< DFT << std::endl;
}

void	Harl::error(void)
{
	std::cout 	<< RED
				<< "This is unacceptable! I want to speak to the manager now."
				<< DFT << std::endl;
}
