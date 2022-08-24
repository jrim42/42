/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:24:21 by jrim              #+#    #+#             */
/*   Updated: 2022/08/24 20:49:58 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"
# define GRY "\033[0;30m"

class Brain
{
	private:
		std::string	_ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain & ref);
		~Brain(void);

		Brain & 	operator=(const Brain & ref);

		std::string	getIdea(const int & idx) const;
};

std::ostream& operator<<(std::ostream & out, const Brain & brain);

#endif