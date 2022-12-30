#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <exception>
# include <string>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Base 
{
	public:
  		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void);
void 	identify(Base* p);
void 	identify(const Base& b);

#endif