#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    std::string operation = av[1];
    if (!RPN(operation))
        return (1);
}