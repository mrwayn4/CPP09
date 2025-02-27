#include "ScalarConverter.hpp"

int parseLiteral(std::string literal) {
    int i = 0;
    int invld = 0;
    int dot = 0;
    int f = 0;
    int sign = 0;
    int digit = 0;

    if (literal == "nan" || literal == "nanf" || literal == "-inf" ||
        literal == "+inf" || literal == "+inff" || literal == "-inff")
    {
        return (0);
    }

    while (literal[i])
    {
        if (!isdigit(literal[i]) && literal[i] != 'f' && literal[i] != '+' && literal[i] != '-' && literal[i] != '.')
            invld = 1;
        if (literal[i] == '.')
            dot++;
        if (literal[i] == 'f')
            f++;
        if (literal[i] == '+' || literal[i] == '-')
            sign++;
        if (isdigit(literal[i]))
            digit++;
        i++;
    }
    
    if (invld || dot > 1 || f > 1 || sign > 1 || digit == 0)
    {
        std::cout << "Invalid literal\n";
        return (1);
    }
    if (dot == 1 && ((literal[0] == '.') || (literal[literal.length() - 1] == '.')))
    {
        std::cout << "Invalid literal\n";
        return (1);
    }
    if (f == 1 && literal[literal.length() - 1] != 'f')
    {
        std::cout << "Invalid literal\n";
        return (1);
    }
    if (f == 1 && dot == 1 && literal[literal.length() - 2] == '.')
    {
        std::cout << "Invalid literal\n";
        return (1);
    }
    if (sign == 1 && (literal[0] != '+' && literal[0] != '-'))
    {
        std::cout << "Invalid literal\n";
        return (1);
    }
    return (0);
}

int main(int ac, char **av) {
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [literal]\n";
        return (1);
    }
    std::string literal = av[1];
    int parse = parseLiteral(literal);
    if (parse)
        return (1);
    ScalarConverter::convert(literal);
    return (0);
}