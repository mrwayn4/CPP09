#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return ;
    }
    std::string line;
    bool first = true;
    while (std::getline(file, line))
    {
        if (first)
        {
            first = false;
            continue;
        }
        std::stringstream ss(line);
        std::string date;
        std::string valuestr;
        float value;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valuestr))
        {
            std::cerr << "Error: bad input" << std::endl;
            return ;
        }
        try
        {
            value = std::stof(valuestr);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: could not convert value to float" << std::endl;
            return ;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            return ;
        }
        if (value > 2147483647)
        {
            std::cerr << "Error: too large a number." << std::endl;
            return ;
        }
        sort[date] = value;
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{

}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& B)
{
    *this = B;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& B)
{
    if (this != &B)
    {
        this->sort = B.sort;
    }
    return (*this);
}

