#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.addNumber(1311);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Exception caught in small test" << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    try
    {
        Span bigSpan(10000);
        std::vector<int> values;

        for (int i = 0; i < 10000; ++i)
            values.push_back(rand());
        bigSpan.addNumbers(values.begin(), values.end());
        std::cout << "Big shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big longest span: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Exception caught in big test" << std::endl;
    }

    return 0;
}
