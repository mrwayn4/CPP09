#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main ()
{
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}