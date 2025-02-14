#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &P) : AForm(P.getName(), 25, 5)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(target, 25, 5)
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& P)
{
    if (this != &P)
    {
        this->setSigned(P.getIsSigned());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

void    PresidentialPardonForm::execute(Bureaucrat const &e) const
{
    if (e.getGrade() > getGradeToExec())
        throw (GradeTooLowException());
    else
    {
        if (getIsSigned())
            std::cout << getName() << " has been pardoned by Zafod Beeblebrox\n";
        else
            throw(FormNotSignedException());
    }
}