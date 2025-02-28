#pragma once
#include <iostream>

template <typename F>

void print(F &i)
{
    i++;
}

template <typename T, typename LEN, typename FUN>

void iter (T *a, LEN b, FUN c)
{
    for (LEN i = 0; i < b; i++)
    {
        c(a[i]);
    }
}