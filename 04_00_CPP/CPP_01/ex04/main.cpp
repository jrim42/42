/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:47:46 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 21:05:01 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfile_name;
	std::string		content;
	int				idx;

	if (argc != 4)
	{
		std::cout << "error: wrong usage" << std::endl;
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
	outfile_name = argv[1];
	outfile_name.append(".replace");
	outfile.open(outfile_name);
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
		while (1)
		{
			idx = content.find(argv[2]);
			// find에 의해 발견되지 못하면 -1을 리턴한다 - std::string::npos
			if (idx == -1)
			{
				outfile << content;
				break ;
			}
			outfile << content.substr(0, idx) << argv[3];
			content = content.substr(idx + std::strlen(argv[2]));
		}
		if (infile.eof())
			break;
		outfile << std::endl;
	}
	
	infile.close();
	outfile.close();
	return (0);
}
