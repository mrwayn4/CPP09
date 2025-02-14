#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& S) : AForm (S.getName(), 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm (target, 145, 137)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& S)
{
    if (this != &S)
    {
        this->setSigned(S.getIsSigned());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void    ShrubberyCreationForm::execute(Bureaucrat const &e) const
{
    if (e.getGrade() > getGradeToExec())
        throw(GradeTooLowException());
    else
    {
        if (getIsSigned())
        {
            std::ofstream tree(getName() + "_shrubbery");
            if (tree.fail())
            {
                std::cout << "Error opening file" << std::endl;
                return;
            }
            else
            {
                tree << "               ,@@@@@@@,                  " << std::endl;
                tree << "       ,,,.   ,@@@@@@/@@,  .oo8888o.     " << std::endl;
                tree << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl;
                tree << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl;
                tree << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl;
                tree << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    " << std::endl;
                tree << "   `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl;
                tree << "       |o|        | |         | |        " << std::endl;
                tree << "       |.|        | |         | |        " << std::endl;
                tree << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
                tree << "----------------------------------------" << std::endl;
                tree.close();
            }
        }
        else
            throw(FormNotSignedException());
    }
}