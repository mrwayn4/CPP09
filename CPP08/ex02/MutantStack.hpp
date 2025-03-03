#pragma once

#include <iostream>
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack :public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        ~MutantStack() {}
        MutantStack() {}
        MutantStack(const MutantStack &M) {*this = M;}
        MutantStack &operator=(const MutantStack &M)
        {
            if (this != &M)
                std::stack<T, Container>::operator=(M);
            return *this;
        }

        iterator begin() {return std::stack<T, Container>::c.begin();}
        iterator end() {return std::stack<T, Container>::c.end();}
        const_iterator begin() const {return std::stack<T, Container>::c.begin();}
        const_iterator end() const {return std::stack<T, Container>::c.end();}

        reverse_iterator rbegin() {return std::stack<T, Container>::c.rbegin();}
        reverse_iterator rend() {return std::stack<T, Container>::c.rend();}
        const_reverse_iterator rbegin() const {return std::stack<T, Container>::c.rbegin();}
        const_reverse_iterator rend() const {return std::stack<T, Container>::c.rend();}
};