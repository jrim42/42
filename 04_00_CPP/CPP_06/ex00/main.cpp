#include "Converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Wrong Input Format" << std::endl;
        return (0);
    }
    Converter c(argv[1]);
    std::cout << c;
    return (0);
}
