#include "Serializer.hpp"


int main() 
{
    Data obj(21);
    std::cout << "Original Object Address: " << &obj << std::endl;
    std::cout << "Original Value: " << obj.n << std::endl;
    uintptr_t raw = Serializer::serialize(&obj);
    std::cout << "Serialized Value (uintptr_t): " << raw << std::endl;
    Data* newPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Object Address: " << newPtr << std::endl;
    std::cout << "Deserialized Value: " << newPtr->n << std::endl;
}