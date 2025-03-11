#include "RPN.hpp"

bool RPN(std::string operation) {
    std::stack<float> numbers;
    std::istringstream iss(operation);
    std::string token;
    while (iss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
            numbers.push(token[0] - '0');
        else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || 
                 token[0] == '*' || token[0] == '/')) {
            if (numbers.size() < 2)
            {
                std::cerr << "Error\n";
                return false;
            }
            float n2 = numbers.top(); numbers.pop();
            float n1 = numbers.top(); numbers.pop();
            if (token[0] == '+')
                numbers.push(n1 + n2);
            else if (token[0] == '-')
                numbers.push(n1 - n2);
            else if (token[0] == '*')
                numbers.push(n1 * n2);
            else if (token[0] == '/')
            {
                if (n2 == 0) 
                {
                    std::cerr << "Error: division by zero\n";
                    return false;
                }
                numbers.push(n1 / n2);
            }
        }
        else {
            std::cerr << "Error\n";
            return false;
        }
    }
    if (numbers.size() != 1)
    {
        std::cerr << "Error\n";
        return false;
    }
    std::cout << numbers.top() << std::endl;
    return true;
}