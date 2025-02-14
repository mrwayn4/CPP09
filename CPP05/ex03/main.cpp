#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main()
{
    AForm* f = NULL;
    srand(time(NULL));
    try
    {
        Intern dadak;
        f = dadak.makeForm("robotomy request", "Bender");
        Bureaucrat b("idder", 2);
        f->beSigned(b);
        f->execute(b);
        delete f;
        f = NULL;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
        delete f;
        f = NULL;
        
    }
}