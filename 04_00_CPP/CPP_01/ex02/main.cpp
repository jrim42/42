/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:14:23 by jrim              #+#    #+#             */
/*   Updated: 2022/10/30 22:34:13 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	msg = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = msg;

	stringPTR = &msg;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "str addr        : " << &msg << std::endl;
	std::cout << "str addr by ptr : " << stringPTR << std::endl;
	std::cout << "str addr by ref : " << &stringREF << std::endl;
	std::cout << "---------------------------------" << std::endl;    
	std::cout << "str by ptr : " << *stringPTR << std::endl;
	std::cout << "str by ref : " << stringREF << std::endl;
	std::cout << "---------------------------------" << std::endl;
	
	return (0);
}