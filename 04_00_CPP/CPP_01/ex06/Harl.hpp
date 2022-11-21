/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:15:02 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 18:32:31 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;34m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Harl 
{
	typedef struct	s_complain 
	{
		std::string	level;
		void		(Harl::*f_ptr)(void);
	}				t_complain;

	private:
		t_complain	complains[4];
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		
	public:
		Harl(void);
		~Harl(void);
		
		void	complain(std::string level);
		void	something_else(void);
};

#endif