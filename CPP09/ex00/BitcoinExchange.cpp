#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        exit(1);
    }
    std::string line;
    bool first = true;
    while (std::getline(file, line))
    {
        if (first) { first = false; continue; }

        std::stringstream ss(line);
        std::string date, valuestr;
        float value;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valuestr))
        {
            std::cerr << "Error: bad input in database => " << line << std::endl;
            continue;
        }
        std::stringstream sv(valuestr);
        if (!(sv >> value))
        {
            std::cerr << "Error: could not convert value to float in database => " << line << std::endl;
            continue;
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
        this->sort = B.sort;
    return (*this);
}

bool BitcoinExchange::parse_date(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    std::istringstream iy(date.substr(0, 4));
    std::istringstream im(date.substr(5, 2));
    std::istringstream id(date.substr(8, 2));
    int year, month, day;
    if (iy >> year && im >> month && id >> day && iy.eof() && im.eof() && id.eof())
    {
        if (year < 1 || month < 1 || month > 12 || day < 1)
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[2] = 29;
        if (day > daysInMonth[month])
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }
        return true;
    }
    std::cerr << "Error: bad input => " << date << std::endl;
    return false;
}

float BitcoinExchange::price(const std::string& date)
{
    std::map<std::string, float>::iterator it = sort.upper_bound(date);
    if (it != sort.begin())
    {
        it--;
        return it->second;
    }
    else
    {
        std::cerr << "Error: no data available for this date." << std::endl;
        return (-1);
    }
}

void BitcoinExchange::update(std::string input)
{
    std::ifstream file(input.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    bool first = true;
    while (std::getline(file, line))
    {
        if (first && line.find("date | value") != std::string::npos)
        {
            first = false;
            continue;
        }
        size_t split = line.find(" | ");
        if (split == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, split);
        std::string valueStr = line.substr(split + 3);
        if (!parse_date(date))
            continue;
        float value;
        char extra;
        std::stringstream ss(valueStr);
        if (!(ss >> value) || (ss >> extra))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        float bitcoinPrice = price(date);
        if (bitcoinPrice == -1)
            continue;
        float result = value * bitcoinPrice;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}
