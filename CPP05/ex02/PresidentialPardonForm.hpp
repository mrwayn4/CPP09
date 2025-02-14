#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& P);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& P);
        ~PresidentialPardonForm();

        void    execute(Bureaucrat const &e) const;
};