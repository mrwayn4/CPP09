#include "Data.hpp"

Data::Data() : n(0)
{

}

Data::~Data()
{

}

Data& Data::operator=(const Data& d)
{
    if (this != &d)
        this->n = d.n;
    return *this;
}

Data::Data(const Data& d)
{
    *this = d;
}

Data::Data(int n) : n(n)
{

}