#include <iostream>

template <typename T, typename F>

void iter(T *arr, const size_t lenght, F f)
{
    if (arr == NULL || f == NULL)
        return ;
    for (size_t i = 0; i < lenght; i++)
    {
        f(arr[i]);
    }   
}