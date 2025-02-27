#pragma once

#include <iostream>

class Data
{
    public:
        int n;
        Data();
        ~Data();
        Data& operator=(const Data& d);
        Data(const Data& d);
        Data(int n);
};