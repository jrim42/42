#include "easyfind.hpp"

int main(void)
{
	std::list<int> l;
	std::deque<int> d;
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
		d.push_back(i);
		v.push_back(i);
	}

	std::cout << GRY << "(case 1: list) " << DFT;
	try
	{
		std::cout 	<< *(easyfind(l, 8)) << " is found at index " 
					<< std::distance(l.begin(), easyfind(l, 8)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GRY << "(case 2: deque) " << DFT;
	try
	{
		std::cout 	<< *(easyfind(d, 6)) << " is found at index " 
					<< std::distance(d.begin(), easyfind(d, 6)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << GRY << "(case 3: vector) " << DFT;
	try
	{
		std::cout	<< *(easyfind(v, 11)) << " is found at index " 
					<< std::distance(v.begin(), easyfind(v, 11)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DFT << '\n';
	}
	return (0);
}