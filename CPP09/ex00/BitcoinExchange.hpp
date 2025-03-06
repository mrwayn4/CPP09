#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
private:
    std::map<std::string, float> sort;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& B);
    BitcoinExchange& operator=(const BitcoinExchange& B);

    void update(std::string input);
    bool parse_date(const std::string& date);
    float price(const std::string& date);
};