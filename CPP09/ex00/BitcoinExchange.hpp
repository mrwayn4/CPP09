#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> sort;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& B);
        BitcoinExchange& operator=(const BitcoinExchange& B);
    void printDatabase() const {
        for (const auto &pair : sort) {
            std::cout << pair.first << " => " << pair.second << std::endl;
        }
    }
};