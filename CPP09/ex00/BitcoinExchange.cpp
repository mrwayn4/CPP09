#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
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
        try
        {
            value = std::stof(valuestr);
        }
        catch(const std::exception&)
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
    std::map<std::string, float>::iterator it = sort.lower_bound(date);
    if (it == sort.end()) 
        return (--it)->second;

    if (it != sort.begin() && (it == sort.end() || it->first > date)) 
        --it;
    return it->second;
}

void BitcoinExchange::update(std::string input)
{
    std::ifstream file(input);
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
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        float value;
        try
        {
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            value = std::stof(valueStr);
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
        }
        catch(const std::exception&)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        float bitcoinPrice = price(date);
        float result = value * bitcoinPrice;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}
