#include "Array.hpp"

int main ()
{
    int arr[4] = {0,1,2,3};
    iter(arr, 4, print<int>);
    for (int i = 0; i < 4; i++)
        std::cout << arr[i] << "\n";
}