#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b;
        b.decrementGrade();
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b;
        b.incrementGrade();
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("ziyad", 149);
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("idder", 1);
        b.decrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
        b.incrementGrade();
        
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}