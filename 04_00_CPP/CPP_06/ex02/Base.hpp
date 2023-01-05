/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:07:59 by jrim              #+#    #+#             */
/*   Updated: 2023/01/03 19:33:18 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Base 
{
	public:
  		virtual ~Base(void);
};

class A : public Base 
{
	~A(void) {};
};
class B : public Base
{
	~B(void) {};
};
class C : public Base 
{
	~C(void) {};
};

Base*	generate(void);
void 	identify(Base* p);
void 	identify(Base& b);

#endif
