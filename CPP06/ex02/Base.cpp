#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A\n";
        return ;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B\n";
        return ;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C\n";
        return ;
    }
}

void identify(Base& p)
{
    try 
    {
        A a = (dynamic_cast<A &>(p));
        std::cout << "A\n";
        return ;
    }
    catch(const std::exception& e)
    {
        try
        {
            B b = (dynamic_cast<B &>(p));
            std::cout << "B\n";
            return ;
        }
        catch(const std::exception& e)
        {
            std::cout << "C\n";
            return ;
        }
    }
}