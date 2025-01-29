#include "Form.hpp"

Form::Form() : name("default"), Signed(false), gradeToSign(150), gradeToExec(150)
{

}

Form::Form(const Form& F) : name(F.name), Signed(F.Signed), gradeToSign(F.gradeToSign), gradeToExec(F.gradeToExec)
{

}

Form::Form(const std::string name, int gradeToSign, int gradeToExec) : name(name), Signed(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw(GradeTooHighException());
    if (gradeToSign > 150 || gradeToExec > 150)
        throw(GradeTooLowException());
}

Form& Form::operator=(const Form& F)
{
    if (this != &F)
    {
        this->Signed = F.Signed;
    }
    return (*this);
}

Form::~Form()
{

}

const std::string Form::getName() const
{
    return (name);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExec() const
{
    return (gradeToExec);
}

bool Form::getIsSigned() const
{
    return (Signed);
}

void Form::beSigned(const Bureaucrat& B)
{
    if (B.getGrade() > gradeToSign)
        throw(GradeTooLowException());
    Signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << " form is ";
    if (f.getIsSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << f.getGradeToSign() << " to sign and grade " << f.getGradeToExec() << " to execute.";
    return (os);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}