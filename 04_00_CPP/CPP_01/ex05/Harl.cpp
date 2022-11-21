/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:16:25 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 18:21:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//-------------- constructor/destructor ----------------//
Harl::Harl(void)
{
	// std::cout << GRY << "(Harl: constructor)" << DFT << std::endl;
	complains[0].level = "DEBUG";
	complains[0].f_ptr = &Harl::debug;
	complains[1].level = "INFO";
	complains[1].f_ptr = &Harl::info;
	complains[2].level = "WARNING";
	complains[2].f_ptr = &Harl::warning;
	complains[3].level = "ERROR";
	complains[3].f_ptr = &Harl::error;
}

Harl::~Harl(void)
{
	// std::cout << GRY << "(Harl: destructor)" << DFT << std::endl;
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
	std::cout 	<< BLU << "[ DEBUG ]" << DFT << std::endl;
	std::cout 	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
				<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout 	<< GRN << "[ INFO ]" << DFT << std::endl;
	std::cout 	<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout 	<< YLW << "[ WARNING ]" << DFT << std::endl;
	std::cout 	<< "I think I deserve to have some extra bacon for free.\n"
				<< "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout 	<< RED << "[ ERROR ]" << DFT << std::endl;
	std::cout 	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}