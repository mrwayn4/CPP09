#pragma once

#include "Bureaucrat.hpp"
#include <iostream>


class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool Signed;
        const int gradeToSign;
        const int gradeToExec;
        
    public:
        Form();
        Form(const Form& F);
        Form(const std::string name, int gradeToSign, int gradeToExec);
        Form& operator=(const Form& F);
        ~Form();

        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool getIsSigned() const;

    

        void    beSigned(const Bureaucrat& B);


        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};
std::ostream& operator<<(std::ostream& os, const Form& F);