#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat b("idder",150);
        Form f("form1", 11, 1);

        b.decrementGrade();
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("idder", 10);
        Form f("form1", 8, 8); 
        std::cout << f << std::endl;
        b.signForm(f);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("idder", 6);
        Form f("form1", 7, 1);
        b.signForm(f);
        b.signForm(f);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}