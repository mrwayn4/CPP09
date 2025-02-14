#include "AForm.hpp"

AForm::AForm() : name("default"), Signed(false), gradeToSign(150), gradeToExec(150)
{

}

AForm::AForm(const AForm& F) : name(F.name), Signed(F.Signed), gradeToSign(F.gradeToSign), gradeToExec(F.gradeToExec)
{

}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : name(name), Signed(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw(GradeTooHighException());
    if (gradeToSign > 150 || gradeToExec > 150)
        throw(GradeTooLowException());
}

AForm& AForm::operator=(const AForm& F)
{
    if (this != &F)
    {
        this->Signed = F.Signed;
    }
    return (*this);
}

AForm::~AForm()
{

}

const std::string AForm::getName() const
{
    return (name);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExec() const
{
    return (gradeToExec);
}

bool AForm::getIsSigned() const
{
    return (Signed);
}

void AForm::setSigned(bool S)
{
    Signed = S;
}

void AForm::beSigned(const Bureaucrat& B)
{
    if (B.getGrade() > gradeToSign)
        throw(GradeTooLowException());
    Signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << " AForm is ";
    if (f.getIsSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << f.getGradeToSign() << " to sign and grade " << f.getGradeToExec() << " to execute.";
    return (os);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}