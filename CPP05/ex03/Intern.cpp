#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& intern)
{
    (void)intern;
}

Intern& Intern::operator=(const Intern& intern)
{
    (void)intern;
    return *this;
}

Intern::~Intern()
{
    
}

AForm* createRobotomyRequestForm(std::string target)
{
    return  (new RobotomyRequestForm(target));
}

AForm* createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string tab[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*func[])(std::string) = {
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (tab[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return func[i](target);
        }
    }
    std::cout << "Invalid form" << std::endl;
    return NULL;
}
