/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:41:22 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 19:25:52 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;

	while (1)
	{
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			phonebook.add_contact();
		else if (cmd == "SEARCH")
			phonebook.search_contact();
		// else
		// 	std::cout << "wrong command. try again." << std::endl;
	}
	return (0);
}