#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern
{
public:
    Intern();
    Intern(const Intern& intern);
    Intern& operator=(const Intern& intern);
    ~Intern();

    AForm* makeForm(std::string Name, std::string target);
};