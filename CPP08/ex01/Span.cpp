#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::~Span()
{

}

Span::Span(const Span& S)
{
    *this = S;
}

Span &Span::operator=(const Span& S)
{
    if (this != &S)
    {
        this->N = S.N;
        this->list = S.list;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (list.size() >= N)
        throw std::overflow_error("List is full");
    list.insert(n);
}

int Span::shortestSpan()
{
    if (list.size() < 2)
        throw std::length_error("Not enough elements to find a span");
    std::multiset<int>::iterator it = list.begin();
    std::multiset<int>::iterator it2 = it;
    ++it2;
    int min = *it2 - *it;
    while (it2 != list.end())
    {
        if (*it2 - *it < min)
            min = *it2 - *it;
        ++it;//for efficiency we do not need old values
        ++it2;
    }
    return min;
}

int Span::longestSpan()
{
    if (list.size() < 2)
        throw std::length_error("Not enough elements to find a span");
    return *list.rbegin() - *list.begin();//we use pointer to give The actual element (integer). rbegin() is largets element
    // end is one past the last element
}

void Span::Range(std::multiset<int>::iterator begin, std::multiset<int>::iterator end)
{
    if (list.size() + std::distance(begin, end) > N)
        throw std::length_error("Not enough elements to find a span");
    list.insert(begin, end);
}