/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:41:22 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 12:22:25 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == "EXIT")
		{
			std::cout << "bye." << std::endl;
			break ;
		}
		else if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "wrong command. try again." << std::endl;
	}
	return (0);
}