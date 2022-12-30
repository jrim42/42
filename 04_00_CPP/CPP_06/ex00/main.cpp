/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:03:11 by jrim              #+#    #+#             */
/*   Updated: 2022/12/30 15:13:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << std::endl;
        return (0);
    }
    // detect type
    // convert
    // display
    Converter   input;

    input.setRawValue(argv[1]);
    return (0);
}

// int main(int argc, char **argv) {
//   if (argc != 2) {
//     std::cout << "Command Not Formatted Well" << std::endl
//       << "./convert [ Convert Input ]" << std::endl;
//   } else {
//     std::cout << Convert(argv[1]);
//   }
//   return 0;
// }