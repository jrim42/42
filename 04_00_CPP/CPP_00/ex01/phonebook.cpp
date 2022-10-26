/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:41:34 by jrim              #+#    #+#             */
/*   Updated: 2022/10/26 20:29:33 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

//----------------- constructor/distructor-----------------//
PhoneBook::PhoneBook(void)
{
	this->length = 0;
}

PhoneBook::~PhoneBook(void)
{
}

//---------------------------------------------------------//
void	PhoneBook::add_contact(void)
{
	Contact new_contact;

	new_contact.add_contact();
	this->contacts[length % 8] = new_contact;
	this->length++;
}

void	PhoneBook::search_contact(void)
{
	int idx;

	if (this->length == 0)
	{
		std::cout << "this phonebook is empty" << std::endl;
		return ;
	}
	this->display_contact_head();
	this->display_contact_info();
	idx = get_contact_idx();
	this->contacts[idx].display_contact();
	std::cin.clear();
	std::cin.ignore(256, '\n');
}

int		PhoneBook::get_contact_idx(void)
{
	int	idx;

	std::cout << "> index : ";
	std::cin >> idx;
	if (std::cin.fail() || idx > this->length || idx < 1)
	{
		std::cout << "wrong index. try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return (get_contact_idx());
	}
	return (idx - 1);
}

//---------------------------------------------------------//
void	PhoneBook::display_contact_head(void)
{
	std::cout << std::right << std::setw(5) << "index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "first name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "last name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "nickname";
    std::cout << "|";
    std::cout << std::endl; 
}

void PhoneBook::display_contact_info(void)
{
	Contact contact;

	for(int i = 0; i < this->length; i++)
	{
		contact = this->contacts[i];
		std::cout << std::right << std::setw(5) << i + 1;
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