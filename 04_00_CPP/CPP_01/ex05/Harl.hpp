/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:15:02 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 22:29:24 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define DFT "\033[0;37m"

class Harl 
{
	typedef struct	s_level 
	{
		std::string	name;
		void	(Harl::*f_ptr)(void);
	}				t_level;

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		t_level	level[4];
		
	
	public:
		Harl(void);
		~Harl(void);
		void	init_harl(void);
		void	complain(std::string level);

};

#endif