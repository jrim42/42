/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:30:58 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 19:19:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
	Contact("", "", "", "", "");
}

Contact::Contact(std::string first_name,
		std::string	last_name,
		std::string	nickname,
		std::string	phone_num,
		std::string	dark_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_num = phone_num;
	this->dark_secret = dark_secret;
}

Contact::~Contact(void)
{
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);

}

std::string Contact::get_nickname(void)
{
	return (this->nickname);
}

void	Contact::add_contact(void)
{
	std::cout << "----------------------" << std::endl;
	std::cout << "first name : ";
	std::cin >> this->first_name;
	std::cout << "last name : ";
	std::cin >> this->last_name;
	std::cout << "nickname : ";
	std::cin >> this->nickname;
	std::cout << "phone number : ";
	std::cin >> this->phone_num;
	std::cout << "darkest secret : ";
	std::cin >> this->dark_secret;
	std::cout << "--- contact created ---" << std::endl;
}