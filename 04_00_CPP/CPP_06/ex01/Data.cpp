#include "Data.hpp"

//-------------- orthodox canonical form ----------------//
Data::Data(void) : _name("unknown")
{
	// std::cout << GRY << "(Data: default constructor)" << DFT << std::endl;

}

Data::Data(std::string name) : _name(name)
{
	// std::cout << GRY << "(Data: default constructor)" << DFT << std::endl;
}

Data::Data(const Data& ref)
{
	// std::cout << GRY << "(Data: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Data& Data::operator=(const Data& ref)
{
	// std::cout << GRY << "(Data: copy assignment)" << DFT << std::endl;
	if (this == &ref) 
		return (*this);
	this->_name = ref._name;
	return (*this);
}

Data::~Data(void)
{
	// std::cout << GRY << "(Data: destructor)" << DFT << std::endl;
}

//--------------------- getter/setter --------------------//
const std::string& Data::getName(void) const 
{
  	return (this->_name);
}

void	Data::setName(const std::string& name)
{
	this->_name = name;
}

//------------------------- utils -----------------------//
uintptr_t serialize(Data* ptr) 
{
 	 return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) 
{
  	return (reinterpret_cast<Data *>(raw));
}

//----------------- insertion/display -------------------//
std::ostream& operator<<(std::ostream& out, const Data& d) 
{
	out	<< "addr: " << &d << std::endl;
	out << "name: " << d.getName() << std::endl;
	return (out);
}

void print(uintptr_t raw) 
{
	Data *ptr = deserialize(raw);
  	if (!ptr)
    	return ;
	std::cout	<< "addr: " << ptr << std::endl;
	std::cout	<< "name: " << ptr->getName() << std::endl;
}