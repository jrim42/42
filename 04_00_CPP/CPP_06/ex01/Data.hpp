/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:07:49 by jrim              #+#    #+#             */
/*   Updated: 2023/01/03 19:34:00 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Data 
{
    private:
  		std::string	_name;

	public:
  		Data(void);
 		Data(std::string name);
 		Data(const Data& ref);
		Data& operator=(const Data& ref);
 		~Data(void);

  		const std::string&	getName(void) const;
		void				setName(const std::string& name);
};

uintptr_t		serialize(Data* ptr);
Data*			deserialize(uintptr_t raw);
std::ostream& 	operator<<(std::ostream& o, const Data& ptr);

#endif
