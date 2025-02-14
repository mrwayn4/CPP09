#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
        srand(time(NULL));
    {
        try
        {
            Bureaucrat b("baron", 2);
            RobotomyRequestForm r("idder");
            r.beSigned(b);         
            r.execute(b);
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "========================\n";
    {
        try
        {
            Bureaucrat b("baron", 2);
            PresidentialPardonForm P("idder");
            b.signForm(P);
            b.executeForm(P);
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "========================\n";
    {
        try
        {
            Bureaucrat b("baron", 2);
            ShrubberyCreationForm S("idder");
            b.signForm(S);
            b.executeForm(S);
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}