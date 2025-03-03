#include "easyfind.hpp"

int main ()
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    try
    {
        std::vector<int>::iterator it = easyfind(v, 4);
        std::cout << "found: " << *it << std::endl;
        easyfind(v,10);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;  
    }
}