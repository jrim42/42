/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:01 by jrim              #+#    #+#             */
/*   Updated: 2022/10/31 12:34:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "contact.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;34m"
# define DFT "\033[0;38m"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		length;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	addContact(void);
		void	searchContact(void);
		int		getContactIdx(void);
		void	displayContactHead(void);
		void	displayContactInfo(void);
		void	displayContactField(std::string content);
};

#endif