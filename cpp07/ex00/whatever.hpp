#include <iostream>


template <typename  T>

T &max(T &x, T &y)
{
    return (x >= y ? x : y);
}


template <typename  A>

A &min(A &x, A &y)
{
    return (x <= y ? x : y);
}


template <typename  S>


void swap(S &x, S &y)
{
    S tmp = x;
    x = y;
    y = tmp;
}