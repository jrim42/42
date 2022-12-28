/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:10:50 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 17:38:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& ref);
		Intern& operator=(const Intern& ref);
		~Intern(void);

		AForm*	makeForm(std::string name, std::string target);

		class FormatNotFoundException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif