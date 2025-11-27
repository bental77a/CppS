#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "default contructor created" << std::endl;
}

Brain::~Brain()
{
    std::cout << "destructor called!" << std::endl;
}
Brain::Brain(const Brain& other)
{
	std::cout << "Brain :  Copy contructer called" << std::endl;
    if (this != &other)
    {
        for (int idx = 0; idx < 100; ++idx)
            this->ideas[idx] = other.ideas[idx];
    }
}
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain  : Assignation operator called" << std::endl;
    if (this != &other)
    {
        for (int idx = 0; idx < 100; ++idx)
            this->ideas[idx] = other.ideas[idx];
    }
    return *this;
}