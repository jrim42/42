/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:01 by jrim              #+#    #+#             */
/*   Updated: 2022/10/26 20:12:57 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact 
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	dark_secret;

	public:
		Contact(void);
		Contact(std::string first_name,
				std::string	last_name,
				std::string	nickname,
				std::string	phone_num,
				std::string	dark_secret);
		~Contact(void);

		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string get_nickname(void);
		void		add_contact(void);
		void		display_contact(void);
};

#endif