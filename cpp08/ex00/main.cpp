#include "easyfind.hpp"
#include <vector>
#include <iostream>


int main()
{
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        std::vector<int>::iterator it_v = easyfind(v, 2);
        std::cout << "Found in vector: " << *it_v << std::endl;

        easyfind(v, 42);
    }
    catch (const std::exception&)
    {
        std::cout << "Value not found" << std::endl;
    }
    
}