#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    int shortestSpan() const;
    int longestSpan() const;

    template <typename I>
    void addNumbers(I begin, I end);
};

#include "Span.tpp"

#endif
