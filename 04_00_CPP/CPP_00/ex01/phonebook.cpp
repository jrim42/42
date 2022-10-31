/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:41:34 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 12:33:50 by jrim             ###   ########.fr       */
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
void	PhoneBook::addContact(void)
{
	Contact	new_contact;

	new_contact.setContact();
	this->contacts[length % 8] = new_contact;
	this->length++;
}

void	PhoneBook::searchContact(void)
{
	int idx;

	if (this->length == 0)
	{
		std::cout << "this phonebook is empty" << std::endl;
		return ;
	}
	this->displayContactHead();
	this->displayContactInfo();
	idx = getContactIdx();
	this->contacts[idx].displayContact();
	std::cin.clear();
	std::cin.ignore(256, '\n');
}

int		PhoneBook::getContactIdx(void)
{
	int	idx;

	std::cout << "> index : ";
	std::cin >> idx;
	if (std::cin.fail() || idx > this->length || idx < 1)
	{
		std::cout << "wrong index. try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return (getContactIdx());
	}
	return (idx - 1);
}

//---------------------------------------------------------//
void	PhoneBook::displayContactHead(void)
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

void PhoneBook::displayContactInfo(void)
{
	Contact contact;

	for (int i = 0; i < this->length; i++)
	{
		contact = this->contacts[i];
		std::cout << std::right << std::setw(5) << i + 1;
    	std::cout << "|";
		displayContactField(contact.getFirstName());
    	std::cout << "|";
		displayContactField(contact.getLastName());
		std::cout << "|";
		displayContactField(contact.getNickname());
		std::cout << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::displayContactField(std::string content)
{
	if (content.length() > 10)
		content = content.substr(0,9) + ".";
	std::cout << std::right << std::setw(10) << content;
}