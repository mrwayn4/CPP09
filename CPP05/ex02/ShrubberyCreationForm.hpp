#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& S);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& S);
        ~ShrubberyCreationForm();

        void    execute(Bureaucrat const &e) const;      
};