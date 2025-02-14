#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &R) : AForm(R.getName(),72 , 45)
{

}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, 72, 45)
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& P)
{
    if (this != &P)
    {
        this->setSigned(P.getIsSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::execute(Bureaucrat const &e) const
{
    if (e.getGrade() > getGradeToExec())
        throw (GradeTooLowException());
    else
    {
        if (getIsSigned())
        {
            std::cout << "Makes some drilling noises\n";
            int valid = rand() % 2;
            if (valid)
                std::cout << getName() << " has been robotomized successfully 50% of the time\n";
            else
                std::cout << getName() << " robotomization failed\n";
        }
        else
            throw(FormNotSignedException());
    }
}