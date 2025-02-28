#pragma once

#include <iostream>

template<typename T>
class Array
{
    private:
        T *arr;
        unsigned int _size;
    public:
        Array(){arr = new T[0]; _size = 0;}
        Array(unsigned int n){arr = new T[n]; _size = n;}
        ~Array(){delete [] arr;}
        Array(const Array& A): arr(NULL){*this = A;};
        Array& operator=(const Array& A)
        {
            if (this != &A)
            {
                delete[] arr;
                arr = new T[A._size];
                this->_size = A._size;
            }
            return (*this);
        }
    T size()const
    {
        return (this->_size);
    }
    
    T&  operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("indeex out of range");
        return (arr[index]);
    }
};