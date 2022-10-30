/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:16:25 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 00:38:02 by jrim             ###   ########.fr       */
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
	int			idx;

	idx = -1;
	for (int i = 0; i < 4; i++)
	{
		if (complains[i].level == level)
			idx = i;
	}
	switch (idx)
	{
		case 0:
			(this->*(complains[idx++].f_ptr))();
			std::cout << std::endl;
		case 1:
			(this->*(complains[idx++].f_ptr))();
			std::cout << std::endl;
		case 2:
			(this->*(complains[idx++].f_ptr))();
			std::cout << std::endl;
		case 3:
			(this->*(complains[idx++].f_ptr))();
			break;
		default:
			something_else();
	}
}

void	Harl::something_else(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::debug(void)
{
	std::cout 	<< BLU << "[ DEBUG ]" << DFT << std::endl;
	std::cout 	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
				<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout 	<< GRN << "[ INFO ]" << DFT << std::endl;
	std::cout 	<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout 	<< YLW << "[ WARNING ]" << DFT << std::endl;
	std::cout 	<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout 	<< RED << "[ ERROR ]" << DFT << std::endl;
	std::cout 	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}
