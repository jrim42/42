#include "Base.hpp"

int main(void) 
{
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;
    // system("leaks ex02 | grep leaked");
    return (0);
}