#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    std::vector<int> v;
    if (ac < 2)
    {
        std::cerr << "Error: invalid number of arguments!" << std::endl;
        return 1;
    }
    if (parseargs(av, v, ac) == 0)
    {
        std::cerr << "Error: invalid argument!" << std::endl;
        return 1;
    }
    sort(v);
}