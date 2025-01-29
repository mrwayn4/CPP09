#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat b("idder", 14);
        Form f("form1", 11, -1);

        b.decrementGrade();
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("idder", 8);
        Form f("form1", 7, 1); 
        std::cout << f << std::endl;
        f.beSigned(b);

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