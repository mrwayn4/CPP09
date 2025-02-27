#pragma once

#include <iostream>
#include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter& operator=(ScalarConverter& sc);
        ScalarConverter(const ScalarConverter& sc);
    public:
        static void convert(std::string literal);
};