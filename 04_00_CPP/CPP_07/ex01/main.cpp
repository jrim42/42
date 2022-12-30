#include "iter.hpp"

#define CONTOUR "---------------------------------------" 

int main(void) 
{
    {
        std::cout << GRY << "(case 1: int array)" << DFT << std::endl;
        int arr[5] = {0, 1, 2, 3, 4};
        iter(arr, 5, display);
        std::cout << std::endl;
        iter(arr, 5, increment);
        iter(arr, 5, display);
    }
	std::cout << "\n" << CONTOUR << std::endl;
    {
        std::cout << GRY << "(case 2: double array)" << DFT << std::endl;
        double  arr[5] = {-5.3, -1.7, 0.0, 2.4, 4.6};
        iter(arr, 5, display);
        std::cout << std::endl;
        iter(arr, 5, increment);
        iter(arr, 5, display);
    }
	std::cout << "\n" << CONTOUR << std::endl;
    {
        std::cout << GRY << "(case 3: char array)" << DFT << std::endl;
        char    arr[5] = {'a', 'b', 'c', 'd', 'e'};
        iter(arr, 5, display);
        std::cout << std::endl;
        iter(arr, 5, increment);
        iter(arr, 5, display);
    }
	std::cout << "\n" << CONTOUR << std::endl;
    {
        std::cout << GRY << "(case 4: string array)" << DFT << std::endl;
        std::string arr[5] = {"libft", "gnl", "ft_printf", "born2beroot", "exam"};
        iter(arr, 5, display);
    }
    std::cout << std::endl;
    return (0);
}