#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::invalid_argument("Value not found!");
    return it;
}