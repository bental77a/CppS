#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <exception>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return (it);
}

#endif