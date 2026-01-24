template <typename I>

void Span::addNumbers(I begin, I end)
{
    unsigned int count = std::distance(begin, end);
    if (_numbers.size() + count > _maxSize)
        throw std::exception();
    _numbers.insert(_numbers.end(), begin, end);
}