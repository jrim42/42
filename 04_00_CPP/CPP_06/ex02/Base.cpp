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

static bool tryCasting(const Base& p, const std::string& s) 
{
	try 
	{
		if (s == "A")
			(void)dynamic_cast<const A&>(p);
		else if (s == "B")
			(void)dynamic_cast<const B&>(p);
		else if (s == "C")
			(void)dynamic_cast<const C&>(p);
		std::cout << s << std::endl;
	} 
	catch (std::exception&) 
	{}
	return (false);
}

void identify(const Base& p) 
{
	std::cout << GRY << "(reference) " << DFT;
	if (tryCasting(p, "A") || tryCasting(p, "B") || tryCasting(p, "C"))
    	return ;
}