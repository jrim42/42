/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:41:34 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 19:21:18 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->length = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add_contact(void)
{
	Contact new_contact;

	new_contact.add_contact();
	this->contacts[length % 8] = new_contact;
	this->length++;
}

void	PhoneBook::search_contact(void)
{
	if (this->length == 0)
	{
		std::cout << "this phonebook is empty" << std::endl;
		return ;
	}
	this->display_contact_head();
	this->display_contact_info();
}

void	PhoneBook::display_contact_head(void)
{
	std::cout << std::right << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "first name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "last name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "nickname";
    std::cout << std::endl; 
}

void PhoneBook::display_contact_info(void)
{
	Contact contact;

	for(int i = 0; i < this->length; i++)
	{
		contact = this->contacts[i];
		display_contact_field(std::to_string(i + 1));
    	std::cout << "|";
		display_contact_field(contact.get_first_name());
    	std::cout << "|";
		display_contact_field(contact.get_last_name());
		std::cout << "|";
		display_contact_field(contact.get_nickname());
		std::cout << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::display_contact_field(std::string content)
{
	if (content.length() > 10)
		content = content.substr(0,9) + ".";
	std::cout << std::right << std::setw(10) << content;
}