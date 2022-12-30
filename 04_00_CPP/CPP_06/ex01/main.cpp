#include "Data.hpp"

int main(int argc, char **argv)
{
    Data        d1;
	Data        *d2;
	uintptr_t   ptr;

	if (argc != 2)
		return (1);
	d1.setName(argv[1]);
	std::cout << "d1 : " << d1.getName() << std::endl;

	ptr = serialize(&d1);
	std::cout << "ptr : " << ptr << std::endl;

	d2 = deserialize(ptr);
	std::cout << "d2 : " << d2->getName() << std::endl;

	return (0);
}