/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:30:58 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 12:30:41 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//----------------- constructor/distructor-----------------//

Contact::Contact(void)
{
	Contact("", "", "", "", "");
}

Contact::Contact(std::string f_name,
		std::string	l_name,
		std::string	n_name,
		std::string	p_num,
		std::string	secret)
{
	this->f_name = f_name;
	this->l_name = l_name;
	this->n_name = n_name;
	this->p_num = p_num;
	this->secret = secret;
}

Contact::~Contact(void)
{
}

//--------------------- getter/setter ----------------------//
std::string	Contact::getFirstName(void)
{
	return (this->f_name);
}

std::string	Contact::getLastName(void)
{
	return (this->l_name);
}

std::string Contact::getNickname(void)
{
	return (this->n_name);
}

void	Contact::setContact(void)
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "  first name   : ";
	std::cin >> this->f_name;
	std::cout << "   last name   : ";
	std::cin >> this->l_name;
	std::cout << "   nickname    : ";
	std::cin >> this->n_name;
	std::cout << " phone number  : ";
	std::cin >> this->p_num;
	std::cout << "darkest secret : ";
	std::cin >> this->secret;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "contact created." << std::endl;
}

//---------------------------------------------------------//
void	Contact::displayContact(void)
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "  first name   : " << this->f_name << std::endl;
	std::cout << "   last name   : " << this->l_name << std::endl;
	std::cout << "   nickname    : " << this->n_name << std::endl;
	std::cout << " phone number  : " << this->p_num << std::endl;
	std::cout << "darkest secret : " << this->secret << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}
