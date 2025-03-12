#include <iostream>
#include "Span.hpp"
#include <set>

int main() {
    try {
        Span sp(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(16);
        sp.addNumber(18);
        sp.addNumber(10);

        if (sp.shortestSpan() != -1)
            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        if (sp.longestSpan() != -1)
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::multiset<int> moreNumbers;
        moreNumbers.insert(20);
        moreNumbers.insert(1);
        moreNumbers.insert(14);
        moreNumbers.insert(100);
        moreNumbers.insert(5);

        sp.Range(moreNumbers.begin(), moreNumbers.end());

        std::cout << "Shortest Span after addRange: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span after addRange: " << sp.longestSpan() << std::endl;
    } 
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
