#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default") , grade(150)
{

}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    *this = other;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 1)
        throw(GradeTooHighException());
    if (grade > 150)
        throw(GradeTooLowException());
    this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}
Bureaucrat::~Bureaucrat()
{

}

const std::string Bureaucrat::getName() const
{
    return (name);
}


int Bureaucrat::getGrade() const
{
    return (grade);
}
void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw(GradeTooHighException());
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw(GradeTooLowException());
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}