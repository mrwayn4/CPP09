#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void    signForm(AForm &f);
        void    executeForm(AForm const & form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);