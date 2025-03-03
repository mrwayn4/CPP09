#include "MutantStack.hpp"

int main()
{
    {
        try
        {
            MutantStack<int> mstack;
            mstack.push(5);
            mstack.push(17);
            std::cout << mstack.top() << std::endl;
            mstack.pop();
            std::cout << mstack.size() << std::endl;
            mstack.push(3);
            mstack.push(5);
            mstack.push(737);
            mstack.push(0);
            MutantStack<int>::iterator it = mstack.begin();
            MutantStack<int>::iterator ite = mstack.end();
            ++it;
            --it;
            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
            std::stack<int> s(mstack);
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    {
        try
        {
            MutantStack<int> mstack;
            
            if (!mstack.empty())
                mstack.pop();

            mstack.push(5);
            mstack.push(17);
            std::cout << mstack.top() << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
