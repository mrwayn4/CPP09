#pragma once

#include <iostream>
#include <vector>
#include <set>

class Span
{
    private:
    std::multiset<int> list;
        unsigned int N;
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span& S);
        Span& operator=(const Span& S);

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void Range(std::multiset<int>::iterator begin, std::multiset<int>::iterator end);
};