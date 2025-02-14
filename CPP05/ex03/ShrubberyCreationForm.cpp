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
                tree << "             &&&&               \n";
                tree << "            &&&&&&&              \n";
                tree << "          &&&\\//&/&&&            \n";
                tree << "         &&&\\//&/&&&&&           \n";
                tree << "           &&&&&&&&&&            \n";
                tree << "      &&&&&&&&&/|\\/|&&&&&&            \n";
                tree << "    &&&&&&&&&&/|||\\|&&&&&&&&          \n";
                tree << "  &&&&&&&&&&&/|||||\\& % \\%       \n";
                tree << " &&& \\$$\\%|$%\\%    \n";
                tree << "  &&  |% |$%|/%    \n";
                tree << "   && |% |$%|%    \n";
                tree << "     |% |$%|%    \n";
                tree << " |% |$%|%    \n";
                tree << "  |% |$%|%     /~\\ /~\\ \n";
                tree << "     &&     \\|||\n";
                tree << "             |||\n";
                tree << "             |||\n";
                tree << "             |||\n";
                tree << ":------------.//~~\\.--------------------:\n";
                tree << "\\                                     //\n";
                tree << " \\____________________________________//\n";
                tree << "  (_)                                  (_) \n";
                tree.close();
            }
        }
        else
            throw(FormNotSignedException());
    }
}