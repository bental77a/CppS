#include "Array.hpp"
#include <iostream>

int main()
{
    try
    {
        Array<int> a;
        std::cout << "a size: " << a.size() << std::endl;

        Array<int> b(5);
        std::cout << "b size: " << b.size() << std::endl;

        for (size_t i = 0; i < b.size(); ++i)
            b[i] = static_cast<int>(i);

        std::cout << "b elements: ";
        for (size_t i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        Array<int> c(b);
        c[0] = 999;

        std::cout << "b[0]: " << b[0] << std::endl;
        std::cout << "c[0]: " << c[0] << std::endl;

        Array<int> d;
        d = b;
        d[1] = 888;

        std::cout << "b[1]: " << b[1] << std::endl;
        std::cout << "d[1]: " << d[1] << std::endl;

        std::cout << b[100] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught (out of bounds)" << std::endl;
    }

    return 0;
}