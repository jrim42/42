/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:01 by jrim              #+#    #+#             */
/*   Updated: 2022/10/26 20:13:08 by jrim             ###   ########.fr       */
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
# define GRY "\033[0;30m"
# define DFT "\033[0;38m"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		length;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	add_contact(void);
		void	search_contact(void);
		int		get_contact_idx(void);
		void	display_contact_head(void);
		void	display_contact_info(void);
		void	display_contact_field(std::string content);
};

#endif