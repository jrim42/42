/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:01 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 18:47:36 by jrim             ###   ########.fr       */
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
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string get_nickname(void);
		// std::string get_phone_num(void);
		// std::string get_dark_secret(void);
		void	add_contact(void);

		Contact(void);
		Contact(std::string first_name,
				std::string	last_name,
				std::string	nickname,
				std::string	phone_num,
				std::string	dark_secret);
		~Contact(void);
};

#endif