/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:07:57 by jrim              #+#    #+#             */
/*   Updated: 2023/01/03 19:33:27 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

//-------------------------------------------------------//
Base::~Base(void)
{
	// std::cout << GRY << "(Base: destructor)" << DFT << std::endl;
}

//----------------------- utils -------------------------//
Base* generate(void) 
{
	int	tmp;
	std::srand(time(NULL));
	tmp = std::rand() % 3;
	switch (tmp) 
	{
		case 0:
			std::cout << GRY << "(A is generated)" << DFT << std::endl;
			return (new A());
		case 1:
			std::cout << GRY << "(B is generated)" << DFT << std::endl;
			return (new B());
		case 2:
			std::cout << GRY << "(C is generated)" << DFT << std::endl;
			return (new C());
		default:
			return (NULL);
  	}
}

void identify(Base* p) 
{
	std::cout << GRY << "(pointer) " << DFT;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) 
{
	std::cout << GRY << "(reference) " << DFT;
	try 
	{
		A &a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
	} 
	catch (std::exception&) {}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
	} 
	catch (std::exception&) {}
	try 
	{
		C &c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
	} 
	catch (std::exception&) {}
}
