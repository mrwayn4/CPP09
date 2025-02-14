#pragma once

#include "Bureaucrat.hpp"
#include <iostream>


class Bureaucrat;
class AForm
{
    private:
        const std::string name;
        bool Signed;
        const int gradeToSign;
        const int gradeToExec;
        
    public:
        AForm();
        AForm(const AForm& F);
        AForm(const std::string name, int gradeToSign, int gradeToExec);
        AForm& operator=(const AForm& F);
        virtual ~AForm();

        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool getIsSigned() const;
        void setSigned(bool S);

        virtual void    execute(Bureaucrat const & executor) const = 0;

        void    beSigned(const Bureaucrat& B);


        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();

        };

        class  FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};
std::ostream& operator<<(std::ostream& os, const AForm& F);