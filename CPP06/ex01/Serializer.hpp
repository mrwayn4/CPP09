#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer& operator=(const Serializer& s);
        Serializer(const Serializer& s);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};