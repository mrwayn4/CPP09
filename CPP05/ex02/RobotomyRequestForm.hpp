#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& R);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& R);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const &e) const; 
};
