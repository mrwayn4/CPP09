#include <iostream>
#include "Array.hpp"  // Include the Array class header

int main()
{
    try
    {
        Array<int> arr(5);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = 100 + i;
        std::cout << "Array contents:" << std::endl;
        for (int i = 0; i < arr.size(); i++)
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        arr[20] = 500;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
}
