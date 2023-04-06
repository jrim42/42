#include "Warlock.hpp"

int main()
{
    const Warlock   richard("Richard", "Mistress of Magma");

    richard.introduce();
    std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

    Warlock*    jack = new Warlock("Jack", "the Long");

    jack->introduce();
    jack->setTitle("the Mighty");
    jack->introduce();

    delete jack;
    return (0);
}