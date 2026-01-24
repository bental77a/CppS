#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::exception();

    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::exception();

    int tmp;
    int val;

    std::vector<int> res = _numbers;
    std::sort(res.begin(), res.end());

    val = res[1] - res[0];
    for (size_t  i = 1; i < res.size() - 1; i++)
    {
        tmp = res[i + 1] - res[i];
        if (tmp < val)
            val = tmp;
    }
    return val;
}

int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::exception();

    int tmp;
    int val;

    std::vector<int> res = _numbers;
    std::sort(res.begin(), res.end());

    val = res[1] - res[0];
    for (size_t  i = 1; i < res.size() - 1; i++)
    {
        tmp = res[i + 1] - res[i];
        if (tmp > val)
            val = tmp;
    }
    return val;
}

