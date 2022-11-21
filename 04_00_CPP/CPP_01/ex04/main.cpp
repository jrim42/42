/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:47:46 by jrim              #+#    #+#             */
/*   Updated: 2022/11/21 19:31:22 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		of_name;
	std::string		content;
	size_t			idx;

	//-------------- input error handling --------------//
	if (argc != 4)
	{
		std::cout << "error: bad arguments" << std::endl;
		return (1);
	}

	//----------------- opening infile -----------------//
	infile.open(argv[1]);
	if (infile.is_open() == false)
	{
		std::cout << "error: file open failed" << std::endl;
		return (1);
	}

	//---------------- creating outfile ----------------//
	of_name = argv[1];
	of_name.append(".replace");
	outfile.open(of_name);
	if (outfile.is_open() == false)
	{
		std::cout << "error: file creation failed" << std::endl;
		infile.close();
		return (1);
	}

	//---------------- writing outfile ----------------//
	while (1)
	{
		std::getline(infile, content);
		idx = 0;
		while (1)
		{
			idx = content.find(argv[2], idx);
			if (idx == std::string::npos)
				break ;
			content.erase(idx, std::strlen(argv[2]));
			content.insert(idx, argv[3]);
			idx += std::strlen(argv[3]);
		}
		outfile << content;
		if (infile.eof())
			break;
		outfile << std::endl;
	}
	
	infile.close();
	outfile.close();
	// system("leaks no_more_sed | grep leaked");
	return (0);
}
