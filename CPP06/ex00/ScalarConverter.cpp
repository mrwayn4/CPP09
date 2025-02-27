#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& sc)
{
    (void)sc;
    return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter& sc)
{
    (void)sc;
}

bool nopoint(std::string literal)
{
    int i;

    i = literal.find('.');
    if (i == -1)
        return (true);
    i++;
    while (literal[i])
    {
        if (literal[i] != '0' && literal[i] != 'f')
            return (false);
        i++;
    }
    return (true);
}

void ScalarConverter::convert(std::string literal)
{
    double d;
    d = strtod(literal.c_str(), NULL);

    std::cout << "char: ";
    if (d < 0 || d > CHAR_MAX || (literal[0] != '+' && !isdigit(literal[0])) || (literal[0] == '+' && !isdigit(literal[1])))
        std::cout << "impossible" << std::endl;
    else if (d < 32 || d > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX || (literal[0] != '+' && literal[0] != '-' && !isdigit(literal[0])) || ((literal[0] == '+' || literal[0] == '-') && !isdigit(literal[1])))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: ";
    if (literal[0] == 'n')
        std::cout << "nanf" << std::endl;
    double f = static_cast<float>(d);
    if (f == -HUGE_VAL)
        std::cout << "-inff" << std::endl;
    else if (f == HUGE_VAL)
        std::cout << "+inff" << std::endl;
    else
    {
        if (nopoint(literal))
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }
    std::cout << "double: ";
    if (literal[0] == 'n')
        std::cout << "nan" << std::endl;
    double db = static_cast<double>(d);
    if (db == -HUGE_VAL)
        std::cout << "-inf" << std::endl;
    else if (db == HUGE_VAL)
        std::cout << "+inf" << std::endl;
    else
    {
        if (nopoint(literal))
            std::cout << db << ".0" << std::endl;
        else
            std::cout << db << std::endl;
    }
}
