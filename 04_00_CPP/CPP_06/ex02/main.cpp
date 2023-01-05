/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:08:02 by jrim              #+#    #+#             */
/*   Updated: 2023/01/03 19:33:21 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) 
{
    Base* base = generate();
    identify(*base);
    identify(base);
    delete base;
    // system("leaks ex02 | grep leaked");
    return (0);
}
