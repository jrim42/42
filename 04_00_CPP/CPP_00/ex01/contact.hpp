/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:01 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 12:29:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact 
{
	private:
		std::string	f_name;
		std::string	l_name;
		std::string	n_name;
		std::string	p_num;
		std::string	secret;

	public:
		Contact(void);
		Contact(std::string f_name,
				std::string	l_name,
				std::string	n_name,
				std::string	p_num,
				std::string	secret);
		~Contact(void);

		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string getNickname(void);
		void		setContact(void);
		void		displayContact(void);
};

#endif